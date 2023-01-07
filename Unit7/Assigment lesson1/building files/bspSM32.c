#include "bspSM32.h"
volatile GPIOA_ODR_t * GPIOA_ODR_REG = ((volatile GPIOA_ODR_t *)(GPIOA_BASE+0x0CU));
volatile GPIOA_IDR_t * GPIOA_IDR_REG = ((volatile GPIOA_IDR_t *)(GPIOA_BASE+0x08U));

void clock_init(void)
{
	RCC_APB2ENR |=(IOPAEN | IOPBEN | AFIOEN );
}
void port_init(void)
{
	
	GPIOB_CRL&=~(0xffffffffU);
	GPIOB_CRH&=~(0xffffffffU);
	GPIOA_CRL&=~(0xffffffffU);
	GPIOA_CRH&=~(0xffffffffU);

	//OUTPUTs
	GPIOB_CRL |= CRL_B01OUT_2MHZ; // B01 as a digital output
	GPIOB_CRH |= CRH_B13OUT_2MHZ; // B13 as a digital output
	GPIOB_CRH |= CRH_B14OUT_2MHZ; // B14 as a digital output
	GPIOB_CRH |= CRH_B15OUT_2MHZ; // B15 as a digital output
	
}



void pinB13_TOGGLE(void)
{
	GPIOB_ODR^=(GPIOB_ODR13);	
}

void pinB14_TOGGLE(void)
{
	GPIOB_ODR^=(GPIOB_ODR14);	
}

void pinB01_TOGGLE(void)
{
	GPIOB_ODR^=(GPIOB_ODR1);
}

void pinB15_Speaker(void)
{
	unsigned char m1,m2;
	//generate teet teet sound on a speaker
    for(m1=0;m1<100;m1++){GPIOB_ODR^= GPIOB_ODR15;delay_some_time(2);}GPIOB_ODR&= ~GPIOB_ODR15;
}


void delay_some_time(int counter)
{
	int i ,j;
	for(j=0;j<=counter;j++)
	for(i=0;i<=250;i++);
}