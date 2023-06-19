#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include "tm4c_cmsis.h"
/*===================================================MACROs==============================================*/
#define LED_RED   (1U << 1)
#define LED_BLUE  (1U << 2)
#define LED_GREEN (1U << 3)
#define LED_OFF   (0U)

#define PRIV               (1U)
#define UNPRIV             (0U)
#define nPRIV_bit          (1U<<0)   

#define WAIT()             for(counter=0;counter<500000;counter++)

/*===============================================public variables===============================================*/
extern  int32_t  __ICFEDIT_size_cstack__;
extern  int32_t  __ICFEDIT_region_RAM_start__;
/*==============================================private variables==============================================*/
static unsigned int volatile counter  ;
static const int32_t stackSize =(int32_t) &__ICFEDIT_size_cstack__;
static  int32_t stackEnd =(int32_t) &__ICFEDIT_region_RAM_start__;

int32_t imdSVC; 
static int32_t stackPspTask;
/*=================================================prototypes==============================================*/
extern __stackless void assert_failed (char const *file, int line);
extern __stackless void SVC_Handler(void);
extern  void PendSV_Handler(void);
//init
static void osInit(void);
static void init(void); 
//tasks
static void TaskA(void);
static void TaskB(void);
static void TaskC(void);
//schedular
static  void switchToTask(void(*ptrToFunc)(void),int taskStackSize);
static __stackless void Switch_SP_TO_PSP(int taskStackSize);
static __stackless void Switch_SP_TO_MSP(void);
static __stackless void Switch_PRIV_TO_USER(void);
static __stackless void Switch_USER_TO_PRIV(void);
static int32_t osSvcSet(int32_t a,int32_t b , int32_t svcId); 
/*===================================================main==============================================*/
int main()
{
    init();
    osInit();
    /*Extract imd in SVC instruction then perform add,sub,mult sequencially*/
    __asm volatile ("SVC #1"); // imd will be stored in the global var (imdSVC)
    int32_t result = osSvcSet(10,20,imdSVC); //add
    
     __asm volatile ("SVC #2"); // imd will be stored in the global var (imdSVC)
     result = osSvcSet(10,20,imdSVC); //sub
     
     __asm volatile ("SVC #3"); // imd will be stored in the global var (imdSVC)
     result = osSvcSet(10,20,imdSVC); //mult
    /*Extract imd in SVC instruction then perform add,sub,mult sequencially*/

    switchToTask(TaskA,imdSVC);    
    switchToTask(TaskB,imdSVC);    
    switchToTask(TaskC,imdSVC);    
    while(1)
    {    
        GPIOF_HS->DATA_Bits[LED_RED] = LED_RED;
        WAIT();
        GPIOF_HS->DATA_Bits[LED_RED] = 0;
        
        GPIOF_HS->DATA_Bits[LED_GREEN] = LED_GREEN;
        WAIT();
        GPIOF_HS->DATA_Bits[LED_GREEN] = 0;
        
        GPIOF_HS->DATA_Bits[LED_BLUE] = LED_BLUE;
        WAIT();
        GPIOF_HS->DATA_Bits[LED_BLUE] = 0;
        
        
        WAIT();
    }
    //return 0;
}

//=========================initializations=====================================
void init(void)
{
  SYSCTL->RCGC2|= (1U << 5);
  SYSCTL->GPIOHSCTL|=(1U << 5);
  GPIOF_HS->DIR|= (LED_RED | LED_GREEN |LED_BLUE);
  GPIOF_HS->DEN|= (LED_RED | LED_GREEN |LED_BLUE);
 
  GPIOF_HS->DATA_Bits[LED_BLUE] = LED_OFF;
  GPIOF_HS->DATA_Bits[LED_GREEN] = LED_OFF;
  GPIOF_HS->DATA_Bits[LED_RED] = LED_OFF;
}
void osInit(void)
{
  stackPspTask = stackEnd + (stackSize>>1);
}

//=========================SWITCHERS (SP->MSP , SP->PSP , ACCESS->PRIVILEGED ,ACCESS->UNPRIVILEGED , SWITCH -> TaskA,B,C)============
void switchToTask(void(*ptrToFunc)(void),int taskStackSize)
{
    Switch_SP_TO_PSP(taskStackSize);
    Switch_PRIV_TO_USER();
    ptrToFunc();
    __asm volatile("svc #0x2");
    Switch_SP_TO_MSP();
}
void Switch_SP_TO_PSP(int taskStackSize)
{
     if(taskStackSize>128 )
        taskStackSize=128;
    int32_t newPSPAdress = stackPspTask;
    stackPspTask-=taskStackSize;
    __asm volatile("MOV R0 ,%0" : :"r" (newPSPAdress));
    __asm volatile("MSR PSP , R0");
  
    __asm volatile("MOV R0 , #0x2");
    __asm volatile("MRS R1 , CONTROL");
    __asm volatile("ORR  R0,R0,R1");
    __asm volatile("MSR CONTROL,R0");
      
    __asm volatile("BX LR");
}
void Switch_SP_TO_MSP(void)
{
    __asm volatile("MOV R0 , #0xfffffffd");
    __asm volatile("MRS R1 , CONTROL");
    __asm volatile("AND  R0,R0,R1");
    __asm volatile("MSR CONTROL,R0"); 
    __asm volatile("BX LR");
}
void Switch_PRIV_TO_USER(void)
{ 
      __asm volatile ("MRS R0,CONTROL");
      __asm volatile ("ORR R0, #0x1");
      __asm volatile ("MSR CONTROL,R0");
}
void Switch_USER_TO_PRIV(void)
{   
      __asm volatile ("MRS R0,CONTROL");
      __asm volatile ("AND R0, #0x6");
      __asm volatile ("MSR CONTROL,R0");   
}


//=====================handlers helpers===============

 int32_t osSvcSet(int32_t a,int32_t b , int32_t svcId)
 {
   switch(svcId)
   {
      case 1 : return(a+b) ; break;//add
      case 2 : return(a-b) ; break;//sub
      case 3 : return(a*b) ; break;//mult
      default  : /*MISRA*/; break;
   }
   return 0;
 }

//=========================Handlers (SVC,PENDSV)===========
void SVC_Handler(void)
{
    /*==================================Extract imd in SVC instruction==================================*/
   /*test bit 2 (0100) of LR 
   if thread code we came from uses MSP, the bit[2] of LR stores 0 else it stores 1,
   after this instruction, in case of MSP,the Zero-flag will set, in case of PSP the Zero-flag clears. */ 
    __asm volatile("TST LR,#4");
    /*move APSR sub-register of xPSR to R0*/
    __asm volatile("MRS R0,APSR");
    /*write mask of bit 30 (zero bit in APSR is bit[30])*/
    __asm volatile("MOV R1,#0x40000000");
    /*ANDING the MASK and APSR to cheack ZERO FLAG __bit[30] of APSR__*/
    __asm volatile("AND R1,R1,R0");
    /*Anding to cheack ZERO-bit bit[30] of APSR*/
    __asm volatile("CMP R1,#0x40000000");
    /*if MSP is the privous stack pointer used then go to Zis1 LABEL*/
    __asm volatile("beq ??Zis1");
    /*if PSP is the privous stack pointer used then go to Zis0 LABEL*/
    __asm volatile("bne ??Zis0");
  
__asm volatile("Zis1:"); //previous used stack is MSP
        __asm volatile("MRS R0,MSP");
        __asm volatile("ADD R0,R0,#24");
        __asm volatile("LDR R1,[R0]");
        __asm volatile("SUBS R1,R1,#2");
        __asm volatile("LDRB R0,[R1]");
        __asm volatile("LDR r1, =imdSVC");
        __asm volatile("STR R0,[R1]");
        __asm volatile("b ??close");
      
__asm volatile("Zis0:");//previous used stack is PSP
        __asm volatile("MRS R0,PSP");
        __asm volatile("ADD R0,R0,#24");
        __asm volatile("LDR R1,[R0]");
        __asm volatile("SUBS R1,R1,#2");
        __asm volatile("LDRB R0,[R1]");
        __asm volatile("LDR r1, =imdSVC");
        __asm volatile("STR R0,[R1]");
        __asm volatile("b ??close");     
__asm volatile("close:");
/*==================================Extract imd in SVC instruction==================================*/
   SCB->ICSR|=(1U<<28);
}

void PendSV_Handler(void) {
  Switch_USER_TO_PRIV();
}

void GPIOPortF_IRQHandler(void)
{ 
    __asm volatile("NOP");
    __asm volatile("NOP");
    __asm volatile("NOP");
}

void GPIOPortE_IRQHandler(void)
{ 
    __asm volatile("NOP");
    __asm volatile("NOP");
    
    
     /*SW interrupt GPIOF PORT*/
    NVIC->ISER[0] |= (1U<<30);
    NVIC->STIR |= 30;
    /*SW interrupt GPIOF PORT*/
    
     __asm volatile("NOP");
    __asm volatile("NOP");
}
//======================Tasks (A,B,C)============
void TaskA(void)
{
  int32_t pattern[16];
  for(int i = 0 ;i<16;i++)
      pattern[i] = 0xAAAAAAAA;
  int *x = pattern;
  *(x+8) = 0xDEADBEAF;
  
  int i = 0;
  while(i++<4)
    {    
        GPIOF_HS->DATA_Bits[LED_RED] = LED_RED;
        WAIT();
        GPIOF_HS->DATA_Bits[LED_RED] = 0;
        WAIT();
    }
}
void TaskB(void)
{
   int32_t pattern[16];
  for(int i = 0 ;i<16;i++)
      pattern[i] = 0xBBBBBBBB;
  int *x = pattern;
  *(x+8) = 0xDEADBEAF;
  
  int i = 0;
  while(i++<4)
    {    
        GPIOF_HS->DATA_Bits[LED_GREEN] = LED_GREEN;
        WAIT();
        GPIOF_HS->DATA_Bits[LED_GREEN] = 0;
        WAIT();
    }
}

void TaskC(void)
{
  int32_t pattern[16];
  for(int i = 0 ;i<16;i++)
      pattern[i] = 0xCCCCCCCC;
  int *x = pattern;
  *(x+8) = 0xDEADBEAF;
  
  int i = 0;
  while(i++<4)
    {    
        GPIOF_HS->DATA_Bits[LED_BLUE] = LED_BLUE;
        WAIT();
        GPIOF_HS->DATA_Bits[LED_BLUE] = 0;
        WAIT();
    }
}

//=====================assert_failed to handle (Errors)===============
void assert_failed (char const *file, int line) {
  /* TBD: damage control */
  NVIC_SystemReset(); /* reset the system */
}
