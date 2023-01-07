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

	//INPUTs
	GPIOA_CRL |= CRL_A01IN_FLOATING_INPUT;
	GPIOA_CRH |= (CRH_A13IN_FLOATING_INPUT);
	
}



void pinB13_TOGGLE(void)
{
	GPIOB_ODR^=(GPIOB_ODR13);	
}

void pinB01_TOGGLE(void)
{
	GPIOB_ODR^=(GPIOB_ODR1);
}

int pinA01POLLING(void)
{
	if((GPIOA_IDR & GPIOA_ODR1) == GPIOA_ODR1)
	{
		return 1 ;
	}
	return 0 ;
}

int pinA13POLLING(void)
{
	if((GPIOA_IDR & GPIOA_ODR13) == GPIOA_ODR13)
	{
		return 1 ;
	}
	return 0 ;
}

void pinA01WAITING(void)
{
while((GPIOA_IDR & GPIOA_ODR1) == GPIOA_ODR1);
}

void delay_some_time(void)
{
	int i = 0 ;for(;i<=25000;i++);
}