/*
 * clockSTM32.h
 *
 *  Created on: Dec 30, 2022
 *      Author: OMAR
 */

#ifndef SRC_CLOCKSTM32_H_
#define SRC_CLOCKSTM32_H_

#include "STM32F103.h"
#include "GPIOSTM32.h"

//clock_source
//======================================================
#define HSI 				(0U<<1 | 0U<<0)//CFGR
#define HSE 				(0U<<1 | 1U<<0)//CFGR
#define PLL 				(1U<<1 | 0U<<0)//CFGR

//Turn On clock source
//======================================================
#define HSION               (1U<<0)//CR
#define HSEON               (1U<<16)//CR
#define PLLON               (1U<<24)//CR

//PLL SOURCE
//========================================================
#define HSI_DEV_BY2_AS_PLLSRC 				(0U<<16) //CFGR
#define HSE_AS_PLLSRC 						(1U<<16)//CFGR
#define HSE_DEV_BY2_AS_PLLSRC 				(1U<<16 | 1U<<17)//CFGR

//PLL MULTIPLAYER
//===================================================================================
#define PLLMUL02								(0U<<18 | 0U<<19 | 0U<<20 | 0U<<21)//CFGR
#define PLLMUL03								(0U<<18 | 0U<<19 | 0U<<20 | 1U<<21)//CFGR
#define PLLMUL04								(0U<<18 | 0U<<19 | 1U<<20 | 0U<<21)//CFGR
#define PLLMUL05								(0U<<18 | 0U<<19 | 1U<<20 | 1U<<21)//CFGR
#define PLLMUL06								(0U<<18 | 1U<<19 | 0U<<20 | 0U<<21)//CFGR
#define PLLMUL07								(0U<<18 | 1U<<19 | 0U<<20 | 1U<<21)//CFGR
#define PLLMUL08								(0U<<18 | 1U<<19 | 1U<<20 | 0U<<21)//CFGR
#define PLLMUL09								(0U<<18 | 1U<<19 | 1U<<20 | 1U<<21)//CFGR
#define PLLMUL10								(1U<<18 | 0U<<19 | 0U<<20 | 0U<<21)//CFGR
#define PLLMUL11								(1U<<18 | 0U<<19 | 0U<<20 | 1U<<21)//CFGR
#define PLLMUL12								(1U<<18 | 0U<<19 | 1U<<20 | 0U<<21)//CFGR
#define PLLMUL13								(1U<<18 | 0U<<19 | 1U<<20 | 1U<<21)//CFGR
#define PLLMUL14								(1U<<18 | 1U<<19 | 0U<<20 | 0U<<21)//CFGR
#define PLLMUL15								(1U<<18 | 1U<<19 | 0U<<20 | 1U<<21)//CFGR
#define PLLMUL16								(1U<<18 | 1U<<19 | 1U<<20 | 0U<<21)//CFGR

// AHB prescaler
//========================================================
#define AHB_PS001									(0b0000<<4)//CFGR
#define AHB_PS002									(0b1000<<4)//CFGR
#define AHB_PS004									(0b1001<<4)//CFGR
#define AHB_PS008									(0b1010<<4)//CFGR
#define AHB_PS016									(0b1011<<4)//CFGR
#define AHB_PS064									(0b1100<<4)//CFGR
#define AHB_PS128									(0b1101<<4)//CFGR
#define AHB_PS256									(0b1110<<4)//CFGR
#define AHB_PS512									(0b1111<<4)//CFGR

// APB1 prescaler
//========================================================
#define APB1_PS01									(0b000<<8)//CFGR
#define APB1_PS02									(0b100<<8)//CFGR
#define APB1_PS04									(0b101<<8)//CFGR
#define APB1_PS08									(0b110<<8)//CFGR
#define APB1_PS16									(0b111<<8)//CFGR

// APB2 prescaler
//========================================================
#define APB2_PS01									(0b000<<11)//CFGR
#define APB2_PS02									(0b100<<11)//CFGR
#define APB2_PS04									(0b101<<11)//CFGR
#define APB2_PS08									(0b110<<11)//CFGR
#define APB2_PS16									(0b111<<11)//CFGR

// Mcu_clock_output
//===========================================
#define SYSCLK                 						(0b100<<24)//CFGR
#define HSICLK                 						(0b101<<24)//CFGR
#define HSECLK                 						(0b110<<24)//CFGR
#define PLLCLK                 						(0b111<<24)//CFGR


void RCC_clock_source_select(uint32_t clock_source);
void RCC_HSE_select_BYBASS(void);
void RCC_Set_Prescaler_Of_Buses(uint32_t AHBps,uint32_t APB1ps,uint32_t APB2ps);
void RCC_Set_PLL(uint32_t PLLsrc,uint32_t PLLmulfactor);
uint8_t RCC_current_clock_source(void);
void RCC_MCO_setting(uint32_t Mcu_clock_output);
#endif /* SRC_CLOCKSTM32_H_ */
