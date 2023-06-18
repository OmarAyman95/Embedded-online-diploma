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


static int32_t stackPspTask;
/*=================================================prototypes==============================================*/
extern __stackless void assert_failed (char const *file, int line);
extern void SVC_Handler(void);
extern void PendSV_Handler(void);
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
/*===================================================main==============================================*/
int main()
{
    init();
    osInit();
    
    /*SW interrupt GPIOF PORT*/
    NVIC->ISER[0] |= (1U<<30);
    NVIC->STIR |= 30;
    /*SW interrupt GPIOF PORT*/
    
    /*SW interrupt GPIOE PORT*/
    NVIC->ISER[0] |= (1U<<4);
    NVIC->STIR |= 4;
    /*SW interrupt GPIOE PORT*/
    
    switchToTask(TaskA,128);    
    switchToTask(TaskB,128);    
    switchToTask(TaskC,128);    

    while(1)
    {    
    
    
        GPIOF_HS->DATA_Bits[LED_RED] = LED_RED;
        WAIT();
        GPIOF_HS->DATA_Bits[LED_RED] = 0;
        
        GPIOF_HS->DATA_Bits[LED_BLUE] = LED_BLUE;
        WAIT();
        GPIOF_HS->DATA_Bits[LED_BLUE] = 0;
        
        GPIOF_HS->DATA_Bits[LED_GREEN] = LED_GREEN;
        WAIT();
        GPIOF_HS->DATA_Bits[LED_GREEN] = 0;
        
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
//=========================Handlers (SVC,PENDSV)===========
void SVC_Handler(void)
{
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
        GPIOF_HS->DATA_Bits[LED_BLUE] = LED_BLUE;
        WAIT();
        GPIOF_HS->DATA_Bits[LED_BLUE] = 0;
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
        GPIOF_HS->DATA_Bits[LED_GREEN] = LED_GREEN;
        WAIT();
        GPIOF_HS->DATA_Bits[LED_GREEN] = 0;
        WAIT();
    }
}
//=====================assert_failed to handle (Errors)===============
void assert_failed (char const *file, int line) {
  /* TBD: damage control */
  NVIC_SystemReset(); /* reset the system */
}
