/* bsp.h  Created on: Sep 28, 2022   Author: OMAR   */
#ifndef BSP_H_
#define BSP_H_
#include "stdint.h"
#define RCC_BASE    0x40021000U
#define GPIOA_BASE  0x40010800U
#define RCC_APB2ENR  (*((volatile uint32_t  *)(RCC_BASE+0x18U)))
#define GPIOA_CRL    (*((volatile uint32_t  *)(GPIOA_BASE+0x00U)))
#define GPIOA_CRH    (*((volatile uint32_t  *)(GPIOA_BASE+0x04U)))
#define GPIOA_IDR    (*((volatile uint32_t  *)(GPIOA_BASE+0x08U)))
#define GPIOA_ODR    (*((volatile uint32_t  *)(GPIOA_BASE+0x0CU)))
#define IOPAEN (0x04U)
#define WAIT(x) for(uint64_t i =0;i<=x;i++)//wait some time
#define LEFT_LIMIT  0x8000
#define RIGHT_LIMIT 0x0100

#define GPIOA_ODR00  (1U<<0)
#define GPIOA_ODR01  (1U<<1)
#define GPIOA_ODR02  (1U<<2)
#define GPIOA_ODR03  (1U<<3)
#define GPIOA_ODR04  (1U<<4)
#define GPIOA_ODR05  (1U<<5)
#define GPIOA_ODR06  (1U<<6)
#define GPIOA_ODR07  (1U<<7)
#define GPIOA_ODR08  (1U<<8)
#define GPIOA_ODR09  (1U<<9)
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
	}ODR;}GPIOA_ODR_t;
//volatile GPIOA_ODR_t * GPIOA_ODR_REG = ((volatile GPIOA_ODR_t *)(GPIOA_BASE+0x0CU));
typedef union{
	uint32_t volatile GPIOA_IDR_REG;
	struct{
		uint32_t volatile IDR00 :1;
		uint32_t volatile IDR01 :1;
		uint32_t volatile IDR02 :1;
		uint32_t volatile IDR03 :1;
		uint32_t volatile IDR04 :1;
		uint32_t volatile IDR05 :1;
		uint32_t volatile IDR06 :1;
		uint32_t volatile IDR07 :1;
		uint32_t volatile IDR08 :1;
		uint32_t volatile IDR09 :1;
		uint32_t volatile IDR10 :1;
		uint32_t volatile IDR11 :1;
		uint32_t volatile IDR12 :1;
		uint32_t volatile IDR13 :1;
		uint32_t volatile IDR14 :1;
		uint32_t volatile IDR15 :1;
		uint32_t volatile reserved:16;
	}IDR;}GPIOA_IDR_t;
//volatile GPIOA_IDR_t * GPIOA_IDR_REG = ((volatile GPIOA_IDR_t *)(GPIOA_BASE+0x08U));
#endif /* BSP_H_ */
