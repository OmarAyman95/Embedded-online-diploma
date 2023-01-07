#ifndef __bspSM32_H_
#define __bspSM32_H_

#include "stdint.h"



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

//NVIC
#define NVIC_ISER0   (1U<<6)
#define NVIC_ISER (*((volatile uint32_t  *)(0xE000E100U)))



//AFIO
#define AFIO_BASE   0x40010000U
#define AFIO_EXTICR1 (*((volatile uint32_t  *)(AFIO_BASE+0x08U)))

/*
0x00 EXTI_IMR Reserved MR[19:0]
0x04 EXTI_EMR Reserved MR[19:0]
0x08 EXTI_RTSR Reserved TR[19:0]
0x0C EXTI_FTSR Reserved TR[19:0]
0x10 EXTI_SWIER Reserved SWIER[19:0]
0x14 EXTI_PR Reserved PR[19:0]
*/

//EXTI
#define EXTI_BASE    0x40010400U
#define EXTI_IMR 	 (*((volatile uint32_t  *)(EXTI_BASE+0x00U)))
#define EXTI_EMR 	 (*((volatile uint32_t  *)(EXTI_BASE+0x04U)))
#define EXTI_RTSR 	 (*((volatile uint32_t  *)(EXTI_BASE+0x08U)))
#define EXTI_FTSR 	 (*((volatile uint32_t  *)(EXTI_BASE+0x0CU)))
#define EXTI_SWIER	 (*((volatile uint32_t  *)(EXTI_BASE+0x10U)))
#define EXTI_PR	     (*((volatile uint32_t  *)(EXTI_BASE+0x14U)))

//GPIOA
#define GPIOA_BASE  0x40010800U
#define GPIOA_CRH    (*((volatile uint32_t  *)(GPIOA_BASE+0x04U)))
#define GPIOA_CRL    (*((volatile uint32_t  *)(GPIOA_BASE+0x00U)))
#define GPIOA_ODR    (*((volatile uint32_t  *)(GPIOA_BASE+0x0CU)))

//RCC
#define RCC_BASE    0x40021000U
#define RCC_APB2ENR  (*((volatile uint32_t  *)(RCC_BASE+0x18U)))
#define IOPAEN (0x04U)
#define AFIOEN (0x01U)




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
	}IDR;
}GPIOA_IDR_t;

//volatile GPIOA_IDR_t * GPIOA_IDR_REG = ((volatile GPIOA_IDR_t *)(GPIOA_BASE+0x08U));


void clock_init(void);
void port_init(void);
void pin13_TOGGLE(void);
void pin06POLLING(void);
void interrupt_init(void);
#endif