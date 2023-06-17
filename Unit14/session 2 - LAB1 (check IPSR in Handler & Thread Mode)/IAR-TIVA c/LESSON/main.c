#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include "tm4c_cmsis.h"

/*===================================================MACROs==============================================*/
#define LED_RED   (1U << 1)
#define LED_BLUE  (1U << 2)
#define LED_GREEN (1U << 3)
#define LED_OFF   (0U)

#define WAIT()                          for(int counter=0;counter<2000000;counter++);

#define PRIV               (1U)
#define UNPRIV             (0U)
#define nPRIV_bit          (1U<<0) 


/*==============================================private variables==============================================*/
static unsigned int volatile counter  ;
/*=================================================prototypes==============================================*/

extern __stackless void assert_failed (char const *file, int line);
extern void SVC_Handler(void);
static void call__SVC_exception(void);
static void init(void);
/*===================================================main==============================================*/
int main()
{
  init();
  call__SVC_exception();
  while(1)
  {    
    GPIOF_HS->DATA_Bits[LED_RED] = LED_RED;
    WAIT();
    GPIOF_HS->DATA_Bits[LED_RED] = 0;
    WAIT();
  }
  //return 0;
}

__stackless void assert_failed (char const *file, int line) {
  /* TBD: damage control */
  NVIC_SystemReset(); /* reset the system */
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

void call__SVC_exception(void)
{
  __asm volatile("SVC #0x2"); 
}
void SVC_Handler(void) {
    __asm volatile ("NOP");
    __asm volatile ("NOP");
    __asm volatile ("NOP");
}