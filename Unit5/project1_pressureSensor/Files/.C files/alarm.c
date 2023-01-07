#include"bsp.h"
#include "alarm.h"

void init_alarm()
{
	//Enable clock of GPIOA
	RCC_APB2ENR |=IOPAEN;
	//wait some time
	WAIT(5000);
	GPIOA_CRH &= ~(0xffffffffU);
	//General purpose output Open-drain
	GPIOA_CRH |=(0x22222222U);
	//clear GPIO(bit15~bit08)
	GPIOA_ODR&=~0xff00;
}

void start_alarm(void)
{
	uint8_t m1;
	//LED ON
	GPIOA_ODR |= GPIOA_ODR09;
	//generate teet teet sound on a speaker
    for(m1=0;m1<150;m1++){GPIOA_ODR^= GPIOA_ODR08;WAIT(250);}
    for(m1=0;m1<150;m1++){GPIOA_ODR^= GPIOA_ODR08;WAIT(125);}	
}
void stop_alarm(void)
{
	//LED OFF
  	GPIOA_ODR &= ~GPIOA_ODR09;
}