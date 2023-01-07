/*
 * SPISTM32.h
 *
 *  Created on: Dec 22, 2022
 *      Author: OMAR
 */

#ifndef SRC_SPISTM32_H_
#define SRC_SPISTM32_H_

#include "stdint.h"
#include "stdlib.h"
#include "GPIOSTM32.h"
#include "STM32F103.h"


struct IRQ_SRC
{
	uint8_t TXE 	: 1;
	uint8_t RXNE 	: 1;
	uint8_t ERRI 	: 1;
	uint8_t UNused 	: 5;
}gIRQ_SRC;

typedef struct
{
	uint16_t Devicemode;//SPI mode @ref SPI_DEVICE_MODE
	uint16_t MasterSlaveSlc;// @ref SPI_MSTR_SLV
	uint16_t BaudRate;//Baud Rate @ref SPI_BAUD_RATES
	uint16_t PolPhsClk;//Polarity and phase clock @ref SPI_POLARTITY_PHASE_CLK
	uint16_t DataLength;// @ref SPI_DATA_LENGHT
	uint16_t LsbMsb;// @ref SPI_MSBLSB
	uint16_t NssPin;// @ref SPI_NSS_CONFIG
	uint16_t EnDisSpi;// @ref SPI_ENABLE


	uint16_t EnableIRQ;// @ref SPI_INTERRUPTs

	void(*ptrOfISR)(struct IRQ_SRC irqSPI);
}SPI_config;

//SPI_MSTR_SLV
#define SPI_MASTER								 	(1U<<2)// at CR1
#define SPI_SLAVE                                	(0U<<2)// at CR1
//SPI_DEVICE_MODE
#define SPI_FULL_DUBLEX_TxRx	   					(0U<<15 | 0U<<10) // at CR1
#define SPI_FULL_DUBLEX_RxONLY	   					(0U<<15 | 1U<<10) // at CR1
#define SPI_HALF_DUBLEX_TxONLY		       			(1U<<14 | 1U<<15 ) // at CR1
#define SPI_HALF_DUBLEX_RxONLY		       			(0U<<14 | 1U<<15 ) // at CR1
// SPI_DATA_LENGHT
#define SPI_8bit_DATA 								(0U<<11) // at CR1
#define SPI_16bit_DATA								(1U<<11) // at CR1
//SPI_MSBLSB
#define SPI_MSB_DATA 								(0U<<7) // at CR1
#define SPI_LSB_DATA								(1U<<7) // at CR1
//SPI_POLARTITY_PHASE_CLK
#define SPI_FIRST_EDGE_0IDLE						(0U<<0 | 0U<<1 ) // at CR1
#define SPI_FIRST_EDGE_1IDLE						(0U<<0 | 1U<<1  ) // at CR1
#define SPI_SECOND_EDGE_0IDLE						(1U<<0 | 0U<<1  ) // at CR1
#define SPI_SECOND_EDGE_1IDLE						(1U<<0 | 1U<<1  ) // at CR1
//SPI_NSS_CONFIG
#define SPI_NSS_HW_SLAVE							(0U<<9) // at CR1
#define SPI_NSS_HW_MASTER_OUTPUT_DISABLE			(0U<<2) // at CR2
#define SPI_NSS_HW_MASTER_OUTPUT_ENABLE				(1U<<2) // at CR2
//SW_NSS_MASTER_AND_SLAVE
#define SPI_NSS_SW_SET								(1U<<9 | 1U<<8 ) // at CR1
#define SPI_NSS_SW_REST								(1U<<9) // at CR1
//SPI_BAUD_RATES
#define SPI_BR_2		                               (0U<<3) // at CR1
#define SPI_BR_4		                               (1U<<3) // at CR1
#define SPI_BR_8		                               (2U<<3) // at CR1
#define SPI_BR_16		                               (3U<<3) // at CR1
#define SPI_BR_32		                               (4U<<3) // at CR1
#define SPI_BR_64		                               (5U<<3) // at CR1
#define SPI_BR_128		                               (6U<<3) // at CR1
#define SPI_BR_256		                               (7U<<3) // at CR1
// SPI_INTERRUPTs
#define SPI_NONE_INTERRUPT							(0U<<5 | 0U<<6 | 0U<<7)
#define SPI_EN_TX_INTERRUPT							(1U<<7)
#define SPI_EN_RX_INTERRUPT							(1U<<6)
#define SPI_EN_ERROR_INTERRUPT						(1U<<5)

//SPI_ENABLE
#define SPI_EN										(1U<<6) // at CR1
#define SPI_DIS										(0U<<6) // at CR1

//prototypes
void SPIx_init(volatile SPI_t *SPIx,SPI_config *SPI_Config);
void SPIx_Dinit(volatile SPI_t *SPIx);
void SPIx_SendData(volatile SPI_t *SPIx,uint16_t DATA,uint8_t ISpolling);
uint16_t SPIx_RecData(volatile SPI_t *SPIx,uint8_t ISpolling);
uint16_t SPIx_TxRx(volatile SPI_t *SPIx,uint16_t DATA,uint8_t ISpolling);
void SPIx_Set_Pins(volatile SPI_t *SPIx);
void SPIx_Start_Transmission(volatile SPI_t *SPIx,uint16_t DATA);
#endif /* SRC_SPISTM32_H_ */
