#include <stdint.h>
#include <stdio.h>
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


//==================Stack================
#define _PSP_STACK_TASK_A_SIZE   100
#define _PSP_STACK_TASK_B_SIZE   100
//schedular 
#define SW_PRIV_TO_UNPRIV()     __asm volatile("MRS R0,CONTROL");__asm volatile("ORR R0, #0x1");__asm volatile("MSR CONTROL,R0");
#define SW_UNPRIV_TO_PRIV()     __asm volatile("MRS R0,CONTROL");__asm volatile("AND R0, #0x6");__asm volatile("MSR CONTROL,R0");
#define SW_SP_TO_MSP()          __asm volatile("MRS R0,CONTROL");__asm volatile("AND R0, #0x5");__asm volatile("MSR CONTROL , R0");
#define SW_SP_TO_PSP()          __asm volatile("MRS R0,CONTROL");__asm volatile("ORR R0, #0x2");__asm volatile("MSR CONTROL , R0");
#define SW_PSP_TASKA()          __asm volatile("MOV R0 ,%0":: "r" (PSP_STACK_TASK_A_START));__asm volatile("MSR PSP , R0");       
#define SW_PSP_TASKB()          __asm volatile("MOV R0 ,%0":: "r" (PSP_STACK_TASK_B_START));__asm volatile("MSR PSP , R0");   
/*==============================================private variables==============================================*/

//Memory stacks regions
extern int CSTACK$$Limit;
int MSP_STACK_START = (int)&CSTACK$$Limit;
int MSP_STACK_END;
int PSP_STACK_TASK_A_START;
int PSP_STACK_TASK_A_END;
int PSP_STACK_TASK_B_START;
int PSP_STACK_TASK_B_END;

//Tasks variables;
int TaskA_flag;
int TaskB_flag;
int Task_result ;

/*=================================================prototypes==============================================*/
int TaskA (int a, int b ,int c);
int TaskB (int a, int b ,int c);
void OS_Schd(void);
void SVC_Handler(void);
void call__SVC_exception(void);


__stackless void SW_PRIV_TO_UNPRIV_func(void);
__stackless void SW_UNPRIV_TO_PRIV_func(void);
__stackless void SW_SP_TO_MSP_func(void);
__stackless  void SW_SP_TO_PSP_func(void);
__stackless void SW_PSP_TASKA_func(void);
__stackless void SW_PSP_TASKB_func(void); 
/*===================================================main==============================================*/
int main()
{
  //GPIO init 
  SYSCTL_RCGCGPIO_R |= (1U << 5);
  SYSCTL_GPIOHBCTL_R |=(1U << 5);
  GPIO_PORTF_AHB_DIR_R  |= (LED_RED | LED_GREEN |LED_BLUE);
  GPIO_PORTF_AHB_DEN_R  |= (LED_RED | LED_GREEN |LED_BLUE);
  GPIO_PORTF_AHB_DATA_BITS_R[LED_BLUE] = LED_OFF;
  GPIO_PORTF_AHB_DATA_BITS_R[LED_GREEN] = LED_OFF;
  GPIO_PORTF_AHB_DATA_BITS_R[LED_RED] = LED_OFF;
  //SYSTICK init 
  SysTick->LOAD = 1000;
  SysTick->VAL  =  0x00;
  SysTick->CTRL |= 0x07;
  //start schedular
  OS_Schd();
  while(1)
  {    
    
  }
  //return 0;
}

void SysTick_Handler(void)
{
  
  GPIO_PORTF_AHB_DATA_BITS_R[LED_RED] ^= LED_RED;
  if(GPIO_PORTF_AHB_DATA_BITS_R[LED_RED] == LED_RED)
  {
    TaskA_flag = 1 ; 
    TaskB_flag = 0 ;
  }
  else 
  {
    TaskA_flag = 0 ; 
    TaskB_flag = 1 ;
  }
}
int TaskA (int a, int b ,int c)
{
  int arr[3];
  int sum;
  arr[0] = a;
  arr[1] = b ;
  arr[2] = c;
  sum = arr[0] + arr[1] + arr[2];
  return sum;
}

int TaskB (int a, int b ,int c)
{
 int arr[3];
  int sum;
  arr[0] = a;
  arr[1] = b ;
  arr[2] = c;
  sum = arr[0] + arr[1] + arr[2];
  return sum/3;
}

void OS_Schd(void)
{
  MSP_STACK_END = (MSP_STACK_START - 512 );
  
  PSP_STACK_TASK_A_START = (MSP_STACK_END - 8);
  PSP_STACK_TASK_A_END   = (PSP_STACK_TASK_A_START - 100 );
  
  PSP_STACK_TASK_B_START = (PSP_STACK_TASK_A_END - 8);
  PSP_STACK_TASK_B_END   = (PSP_STACK_TASK_B_START - 100 );
  
  while(1)
  {
      if(TaskA_flag == 1 && TaskB_flag == 0)
      {
                  //PSP = PSP_STACK_TASK_A_START
        //SW_PSP_TASKA();
        SW_PSP_TASKA_func();
                  // SP -> PSP
        //SW_SP_TO_PSP();
        SW_SP_TO_PSP_func();
                // switch from priv to unpriv 
        SW_PRIV_TO_UNPRIV();
                //perform TASK A
        Task_result = TaskA(1,2,3);
              // switch from unpriv to priv
       call__SVC_exception();
            // SP -> MSP
        SW_SP_TO_MSP();
      }
      else if(TaskA_flag == 0 && TaskB_flag == 1)
      {
        //PSP = PSP_STACK_TASK_B_START
       // SW_PSP_TASKB();
        SW_PSP_TASKB_func();
        // SP -> PSP
       // SW_SP_TO_PSP();
       SW_SP_TO_PSP_func();
        // switch from priv to unpriv 
        SW_PRIV_TO_UNPRIV();
        //perform TASK B
        Task_result = TaskB(10,20,30);
         // switch from unpriv to priv
        call__SVC_exception();
        // SP -> MSP
        SW_SP_TO_MSP();
      }
  }
}
void call__SVC_exception(void)
{
  __asm volatile("SVC #0x2");
}
void SVC_Handler(void) {
  SW_UNPRIV_TO_PRIV();
  
}

__stackless void SW_PRIV_TO_UNPRIV_func(void)
{
  //To do
}
__stackless void SW_UNPRIV_TO_PRIV_func(void)
{
   //To do
}
__stackless void SW_SP_TO_MSP_func(void)
{
  __asm volatile("MRS R0,CONTROL");
  __asm volatile("AND R0, #0x5");
  __asm volatile("MSR CONTROL , R0");
  
  __asm volatile("BX LR");
}
__stackless  void SW_SP_TO_PSP_func(void)
{
  __asm volatile("MRS R0,CONTROL");
  __asm volatile("ORR R0, #0x2");
  __asm volatile("MSR CONTROL , R0");
  
  __asm volatile("BX LR");
}
__stackless void SW_PSP_TASKA_func(void)
{
  __asm volatile("MOV R0 ,%0":: "r" (PSP_STACK_TASK_A_START));
  __asm volatile("MSR PSP , R0"); 
  
  __asm volatile("BX LR");
}
__stackless void SW_PSP_TASKB_func(void) 
{
  __asm volatile("MOV R0 ,%0":: "r" (PSP_STACK_TASK_B_START));
  __asm volatile("MSR PSP , R0"); 
  
  __asm volatile("BX LR");
}



