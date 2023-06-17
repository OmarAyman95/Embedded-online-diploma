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

//================wait some time========================
#define WAIT()                          for(int counter=0;counter<2000000;counter++);
/*==============================================private variables==============================================*/
//to read CONTROL,IPSR CPU registers
static int32_t Control_REG_Val;
static int32_t IPSR_REG_Val;
//Exlusive-Or Operation variables
static uint8_t Q = 0 ;
static uint8_t A = 0x03 ;
static uint8_t B = 0x02 ;
/*=================================================prototypes==============================================*/
extern void assert_failed (char const *file, int line);
extern void SVC_Handler(void);
static void init(void); 
/*===================================================main==============================================*/
int main()
{
  init();
 
   __asm volatile("EOR %0,%1,%2" : "=r" (Q) : "r"(A) ,"r"(B) : "r7");        
   
   __asm volatile ("MRS R0,CONTROL");
   __asm volatile ("MOV %0,R0" : "=r" (Control_REG_Val) : : );
   __asm volatile("SVC #0x2"); // make exception
    while(1)
  {    
   GPIOF_HS->DATA_Bits[LED_RED] = LED_RED;
    WAIT();
    GPIOF_HS->DATA_Bits[LED_RED] = 0;
    WAIT();
  }
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

void SVC_Handler(void) {
   __asm volatile ("MRS R0,IPSR");
   __asm volatile ("MOV %0,R0"
                  : "=r" (IPSR_REG_Val)        // first parameter : output
                  );
}
void assert_failed (char const *file, int line) {
  /* TBD: damage control */
  NVIC_SystemReset(); /* reset the system */
}


/* __asm volatile("add %0,%1,%2"
                  : "=r" (Var3)         // first parameter : output
                  : "r"  (Var1) , "r"  (Var2)   // second parameter : input
                  
                  );*/
  
  