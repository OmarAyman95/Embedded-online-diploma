#include "bspSM32.h"
volatile GPIOA_ODR_t * GPIOA_ODR_REG = ((volatile GPIOA_ODR_t *)(GPIOA_BASE+0x0CU));
volatile GPIOA_IDR_t * GPIOA_IDR_REG = ((volatile GPIOA_IDR_t *)(GPIOA_BASE+0x08U));

void clock_init(void)
{
	RCC_APB2ENR |=(IOPAEN | AFIOEN);
}
void port_init(void)
{
	
	GPIOA_CRH &=~CRH_A13OUT_2MHZ;
	GPIOA_CRH |= CRH_A13OUT_2MHZ; // A13 as a digital output
	GPIOA_CRL&=~(0xffffffffU);
	GPIOA_CRL |=(0x08000004U);//A0 and A6 as a digital input(A0:floating input :: A6:input with pull up/pull down)
}

void interrupt_init(void)
{
	//select the source input for EXTI0 external interrupt
	//0000: PA[0] pin
	AFIO_EXTICR1 &= ~(0b0000<<0);
	//: Interrupt Mask on line 0
	//0: Interrupt request from Line 0 is masked
	//1: Interrupt request from Line 0 is not masked
	EXTI_IMR  |=(1U<<0);
	/*TR0: Rising trigger event configuration bit of line 0
	0: Rising trigger disabled (for Event and Interrupt) for input line
	1: Rising trigger enabled (for Event and Interrupt) for input line
	*/
	EXTI_RTSR |= (1U<<0);
	/*TR0: Falling trigger event configuration bit of line 0
	0: Falling trigger disabled (for Event and Interrupt) for input line
	1: Falling trigger enabled (for Event and Interrupt) for input line.*/
	EXTI_FTSR |= (1U<<0);
	//NVIC ISER0 Enable 
	NVIC_ISER |= NVIC_ISER0; 
}

void pin13_TOGGLE(void)
{
	int i= 0;
	GPIOA_ODR^=(GPIOA_ODR13);
	for(;i<=75000;i++);
}
void pin06POLLING(void)
{
	while(GPIOA_IDR_REG->IDR.IDR06);
}

void EXTI0_IRQHandler(void)
{
	//if( EXTI_PR &=(1U<<0) )
	//{
		EXTI_PR |= (1U<<0);
		GPIOA_ODR^=(GPIOA_ODR13);
	//}
}