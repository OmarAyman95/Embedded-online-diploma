#include"bsp.h"
#include "stdint.h"
void RCC_init();
void PORT_init();
int main(void)
{
   RCC_init();
   PORT_init();
 for(;;)
 {
   GPIOA_ODR_REG->ODR.ODR00 = 1;
   WAIT(100000);
   GPIOA_ODR_REG->ODR.ODR00 = 0;  
   WAIT(100000);
}
	return 0;
}

void PORT_init()
{
   
   GPIOA_CRL |= 0x00000001;
}

void RCC_init()
{
//PLL Multiplier ((8MHz/2) X 8 = 32MHz) 0110: PLL input clock x 8
RCC_CFGR |=(0b0110 << 18);
//0b10: PLL selected as system clock
RCC_CFGR |=(0b10 << 0);
 //PLL used as system clock :: wait until  PLL be ready 
//while(!(RCC_CFGR & (0b10<<2) ));


/*Bit 24 PLLON: PLL enable
Set and cleared by software to enable PLL.
Cleared by hardware when entering Stop or Standby mode. This bit can not be reset if the 
PLL clock is used as system clock or is selected to become the system clock.
0: PLL OFF
1: PLL ON*/
RCC_CR |=(0b1 << 24);

 //APB1 (Div/2) (32MHz/2 = 16MHz)
RCC_CFGR |=(0b100 << 8);
 //APB2 (Div/4) (32MHz/4 = 8MHz)
RCC_CFGR |=(0b101 << 11);
 //AHB (Div/1)  (32MHz/1 = 32MHz)
RCC_CFGR &= ~(0b1111 << 4);
 // enable clocking for PORTA
RCC_APB2ENR|=IOPAEN;
}
