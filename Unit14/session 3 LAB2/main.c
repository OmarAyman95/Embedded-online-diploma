#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include "lm4f120h5qr.h"
#include "tm4c_cmsis.h"

/*===================================================MACROs==============================================*/
#define LED_RED   (1U << 1)
#define LED_BLUE  (1U << 2)
#define LED_GREEN (1U << 3)
#define LED_OFF   (0U)

#define PRIV               (1U)
#define UNPRIV             (0U)
#define nPRIV_bit          (1U<<0) 

//================ITM module =============
#define  DEMCR                          *((volatile uint32_t *)(0xE000EDFC))         
#define  ITM_STIMULUS_PORT0             *((volatile uint32_t *)(0xE0000000))         
#define  ITM_TRACE_EN                   *((volatile uint32_t *)(0xE0000E00))        

/*==============================================private variables==============================================*/
static unsigned int volatile counter  ;
static int gVar = PRIV;
static char text[]="Hello Omar!\n";
static uint8_t _data = 'M';
static int32_t i;
static int32_t numbers[] = {1,5,12,6,7,89};
int32_t result=0xaaaaaaaa;

int32_t Var1 = 0x0000BEAF;
int32_t Var2 = 0xDEAD0000;
int32_t Var3;

int32_t Control_REG_Val;
int32_t IPSR_REG_Val;


/*=================================================prototypes==============================================*/
__stackless void Switch_SP_TO_PSP(void);
__stackless void assert_failed (char const *file, int line);
void SVC_Handler(void);
void call__SVC_exception(void);
void check_xPSR(void);
int32_t avg(int32_t * arr, int32_t size);
void Disable_FPU(void);
int Is_Privileged(void);
/*===================================================main==============================================*/
int main()
{
  SYSCTL_RCGCGPIO_R |= (1U << 5);
  SYSCTL_GPIOHBCTL_R |=(1U << 5);
  GPIO_PORTF_AHB_DIR_R  |= (LED_RED | LED_GREEN |LED_BLUE);
  GPIO_PORTF_AHB_DEN_R  |= (LED_RED | LED_GREEN |LED_BLUE);
  GPIO_PORTF_AHB_DATA_BITS_R[LED_BLUE] = LED_OFF;
  GPIO_PORTF_AHB_DATA_BITS_R[LED_GREEN] = LED_OFF;
  GPIO_PORTF_AHB_DATA_BITS_R[LED_RED] = LED_OFF;
  
 
  
  
  /* __asm volatile("add %0,%1,%2"
                  : "=r" (Var3)         // first parameter : output
                  : "r"  (Var1) , "r"  (Var2)   // second parameter : input
                  
                  );*/
  
  
   __asm volatile ("MRS R0,CONTROL");
   __asm volatile ("MOV %0,R0"
                  : "=r" (Control_REG_Val)        // first parameter : output
                  );
   
   __asm volatile("SVC #0x2"); // make exception
   
   
  check_xPSR();
  result =  avg(numbers,(sizeof(numbers)/sizeof(int)));
  call__SVC_exception();
  gVar = Is_Privileged();
  while(1)
  {    
    GPIO_PORTF_AHB_DATA_BITS_R[LED_RED] = LED_RED;
    for(counter=0;counter<2000000;counter++);
    GPIO_PORTF_AHB_DATA_BITS_R[LED_RED] = 0;
    for(counter=0;counter<2000000;counter++);
  }
  //return 0;
}

__stackless void assert_failed (char const *file, int line) {
  /* TBD: damage control */
  NVIC_SystemReset(); /* reset the system */
}


int32_t avg(int32_t * arr, int32_t size)
{
  int32_t i;
  int32_t result = 0;
  for(i=0;i<size;i++)
  {
      result+=arr[i];
  }
  result/=size;
  return result;
}
void check_xPSR(void)
{
  signed int a = 0xA0000000;
  signed int b = 0x00000000;
  signed int result;
  result = a + b ;
  
  a = 0xA0000000;
  b = 0xA0000000;
  result = a + b ; 
  
  a = 0x90000000;
  b = 0x80000000;
  result = a - b ; 
  
  a = 0xE0000000;
  b = 0xF0000000;
  result = a + b ; 

 
}
__stackless void Switch_SP_TO_PSP(void)
{

  __asm volatile("LDR R0 ,=0x20000C00");
  __asm volatile("MSR PSP , R0");
  
 __asm volatile("MOV R0 , #0x6");
 __asm volatile("MSR CONTROL , R0");

 __asm volatile("BX LR");
}

void call__SVC_exception(void)
{
  
  __asm volatile("SVC #0x2");
  
}
void SVC_Handler(void) {
   __asm volatile ("MRS R0,IPSR");
   __asm volatile ("MOV %0,R0"
                  : "=r" (IPSR_REG_Val)        // first parameter : output
                  );
}
void Disable_FPU(void)
{
  *((unsigned int *)(0xE000ED88)) &= ~(0xf<<20);
}
int Is_Privileged(void)
{
   if(__get_IPSR() !=0)
   {
      return PRIV;
   }
   else 
   {
      if( (__get_CONTROL() & nPRIV_bit) == nPRIV_bit )
      {  
         return UNPRIV;
      }
      else
      {
         return PRIV;
      }
   }
}