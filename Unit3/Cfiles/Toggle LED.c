/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Omar Ayman
 * @brief          : Main program body
 ******************************************************************************
 * @attention
 *
 * <h2><center>&copy; Copyright (c) 2022 STMicroelectronics.
 * All rights reserved.</center></h2>
 *
 * This software component is licensed by ST under BSD 3-Clause license,
 * the "License"; You may not use this file except in compliance with the
 * License. You may obtain a copy of the License at:
 *                        opensource.org/licenses/BSD-3-Clause
 *
 ******************************************************************************
 */
  /* this Demo just toggles the LED on and off .
   * */

#include "stdint.h"

#define RCC_BASE    0x40021000U
#define GPIOA_BASE  0x40010800U
#define RCC_APB2ENR  (*((volatile uint32_t  *)(RCC_BASE+0x18U)))
#define GPIOA_CRH    (*((volatile uint32_t  *)(GPIOA_BASE+0x04U)))
#define GPIOA_ODR    (*((volatile uint32_t  *)(GPIOA_BASE+0x0CU)))
#define IOPAEN (0x04U)


#define CRH_A08OUT_2MHZ (1U<<1)
#define CRH_A09OUT_2MHZ (1U<<5)
#define CRH_A10OUT_2MHZ (1U<<9)
#define CRH_A11OUT_2MHZ (1U<<13)
#define CRH_A12OUT_2MHZ (1U<<17)
#define CRH_A13OUT_2MHZ (1U<<21)
#define CRH_A14OUT_2MHZ (1U<<25)
#define CRH_A15OUT_2MHZ (1U<<29)

#define GPIOA_ODR0  (1U<<0)
#define GPIOA_ODR1  (1U<<1)
#define GPIOA_ODR2  (1U<<2)
#define GPIOA_ODR3  (1U<<3)
#define GPIOA_ODR4  (1U<<4)
#define GPIOA_ODR5  (1U<<5)
#define GPIOA_ODR6  (1U<<6)
#define GPIOA_ODR7  (1U<<7)
#define GPIOA_ODR8  (1U<<8)
#define GPIOA_ODR9  (1U<<9)
#define GPIOA_ODR10 (1U<<10)
#define GPIOA_ODR11 (1U<<11)
#define GPIOA_ODR12 (1U<<12)
#define GPIOA_ODR13 (1U<<13)
#define GPIOA_ODR14 (1U<<14)
#define GPIOA_ODR15 (1U<<15)
typedef union{
	uint32_t volatile GPIOA_ODR_REG;
	struct{
		uint32_t volatile ODR00 :1;
		uint32_t volatile ODR01 :1;
		uint32_t volatile ODR02 :1;
		uint32_t volatile ODR03 :1;
		uint32_t volatile ODR04 :1;
		uint32_t volatile ODR05 :1;
		uint32_t volatile ODR06 :1;
		uint32_t volatile ODR07 :1;
		uint32_t volatile ODR08 :1;
		uint32_t volatile ODR09 :1;
		uint32_t volatile ODR10 :1;
		uint32_t volatile ODR11 :1;
		uint32_t volatile ODR12 :1;
		uint32_t volatile ODR13 :1;
		uint32_t volatile ODR14 :1;
		uint32_t volatile ODR15 :1;
		uint32_t volatile reserved:16;
	}ODR;
}GPIOA_ODR_t;
volatile GPIOA_ODR_t * GPIOA_ODR_REG = ((volatile GPIOA_ODR_t *)(GPIOA_BASE+0x0CU));



int main(void)
{
   RCC_APB2ENR |=IOPAEN;
   GPIOA_CRH &=~CRH_A13OUT_2MHZ;
   GPIOA_CRH |= CRH_A13OUT_2MHZ;
    /* Loop forever */
	for(;;)
	{
//u    s     i    n     g      Macros
		/*GPIOA_ODR^=(GPIOA_ODR11);
		for(int i =0;i<=50000;i++);*/

//u    s     i    n     g      unions

		GPIOA_ODR_REG->ODR.ODR13=1;
		for(int i =0;i<=75000;i++);
		GPIOA_ODR_REG->ODR.ODR13=0;
		for(int i =0;i<=75000;i++);

	}
	return 0;
}
