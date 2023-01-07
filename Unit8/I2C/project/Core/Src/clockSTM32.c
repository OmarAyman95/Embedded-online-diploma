/*
 * clockSTM32.c
 *
 *  Created on: Dec 30, 2022
 *      Author: OMAR
 */

#include "clockSTM32.h"

static uint8_t gclock_source=HSI;
void RCC_clock_source_select(uint32_t clock_source)
{
	//RESET  SW bits <1,0>
	RCC->CFGR &= ~(0xfU<<0);
	if(clock_source == HSI)
	{
		RCC->CFGR |= HSI;
		RCC->CR |= HSION;
		RCC->CR &= ~HSEON;
		gclock_source=HSI;
	}
	else if(clock_source == HSE)
	{
		RCC->CFGR |= HSE;
		RCC->CR |= HSEON;
		RCC->CR &= ~HSION;
		gclock_source=HSE;
	}
	else if(clock_source == PLL)
	{
		RCC->CFGR |= PLL;
		gclock_source=PLL;
	}
	else
	{
		//Do nothing
	}

}
void RCC_HSE_select_BYBASS(void)
{
	RCC->CR |= (HSEON<<2);
}
void RCC_Set_PLL(uint32_t PLLsrc,uint32_t PLLmulfactor)
{

	RCC->CFGR &= ~(0x3fU<<16);//RESET bits <21,20,19,18,17,16>
	RCC->CFGR |= (PLLsrc | PLLmulfactor);
	if(PLLsrc == HSI_DEV_BY2_AS_PLLSRC)
		{RCC->CR |= HSION;RCC->CR &= ~HSEON;}
	else if((PLLsrc == HSE_AS_PLLSRC) | (PLLsrc == HSE_DEV_BY2_AS_PLLSRC))
		{RCC->CR |= HSEON;RCC->CR &= ~HSION;}

	RCC->CR |= PLLON;
}

void RCC_Set_Prescaler_Of_Buses(uint32_t AHBps,uint32_t APB1ps,uint32_t APB2ps)
{
	RCC->CFGR &= ~(0x3ffU<<4);
	RCC->CFGR |= (AHBps | APB1ps | APB2ps);
}

uint8_t RCC_current_clock_source(void)
{
	return gclock_source;
}

void RCC_MCO_setting(uint32_t Mcu_clock_output)
{
	RCC->CFGR &= ~(0x7U<<24);
	RCC->CFGR |= Mcu_clock_output;
	RCC->APB2ENR |= (IOPAEN);
	GPIO_Init_Output_Pin(GPIOA,GPIO_PIN8,OUTPUT_ALT_PUSH_PULL_10MHZ);
}
