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

/*==============================================private variables==============================================*/
static unsigned int volatile counter  ;
int32_t result=0xaaaaaaaa;


/*=================================================prototypes==============================================*/
extern void assert_failed (char const *file, int line);
extern void PendSV_Handler(void);
extern void SVC_Handler(void);

static void Switch_PRIV_TO_USER(void);
static void Switch_USER_TO_PRIV(void);
static int  Is_Privileged(void);
static void init(void);
/*===================================================main==============================================*/
int main()
{
init(); 
 Switch_PRIV_TO_USER();

 __asm volatile("svc #0x3");
  *((uint32_t*)(0xE000E100)) = (1U<<0); /*Illegal because the access level now is Unprebilged 
                                        (HARD FAULT EXCEPTION Will Happen if you connect the real board)*/

  while(1)
  {   
    
    GPIOF_HS->DATA_Bits[LED_RED] = LED_RED;
    for(counter=0;counter<500000;counter++);
    GPIOF_HS->DATA_Bits[LED_RED] = 0;
    for(counter=0;counter<500000;counter++);
  }
  //return 0;
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
void Switch_PRIV_TO_USER(void)
{ 
    if(Is_Privileged() == PRIV)
    {   
      __asm volatile ("MRS R0,CONTROL");
      __asm volatile ("ORR R0, #0x1");
      __asm volatile ("MSR CONTROL,R0");
    }
}
void Switch_USER_TO_PRIV(void)
{   
      __asm volatile ("MRS R0,CONTROL");
      __asm volatile ("AND R0, #0x6");
      __asm volatile ("MSR CONTROL,R0");   
}
void init(void)
{
  SYSCTL->RCGC2|= (1U << 5);
  SYSCTL->GPIOHSCTL |=(1U << 5);
  GPIOF_HS->DIR |= (LED_RED | LED_GREEN |LED_BLUE);
  GPIOF_HS->DEN |= (LED_RED | LED_GREEN |LED_BLUE);
  GPIOF_HS->DATA_Bits[LED_BLUE] = LED_OFF;
  GPIOF_HS->DATA_Bits[LED_GREEN] = LED_OFF;
  GPIOF_HS->DATA_Bits[LED_RED] = LED_OFF;
}

void PendSV_Handler(void)
{
  Switch_USER_TO_PRIV();
}

void SVC_Handler(void)
{
  SCB->ICSR|=(1U<<28);
}

 void assert_failed (char const *file, int line) {
  /* TBD: damage control */
  NVIC_SystemReset(); /* reset the system */
}