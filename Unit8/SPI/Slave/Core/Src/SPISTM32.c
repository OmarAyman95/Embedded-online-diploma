/*
 * SPISTM32.c
 *
 *  Created on: Dec 22, 2022
 *      Author: OMAR AYMAN
 */
#include "SPISTM32.h"

SPI_config *gSPI_config[2]={NULL,NULL};
uint8_t gTransmissiondone;

void SPIx_init(volatile SPI_t *SPIx,SPI_config *SPI_Config)
{
	uint16_t tempCR1 =0x0000;

	uint16_t tempCR2 =0x0000;


//SPI1 ? or SPI2?
	if(SPIx==SPI_1){
		gSPI_config[0] = SPI_Config;
		RCC_SPI1_CLOCK_EN();
	}
	else if (SPIx==SPI_2){
		gSPI_config[1] = SPI_Config;
		RCC_SPI2_CLOCK_EN();
	}
//Enable Serial Peripheral
	tempCR1|=SPI_Config->EnDisSpi;
//Device Mode
	tempCR1|= SPI_Config->Devicemode;
//MASTER or SLAVE ?
	tempCR1|= SPI_Config->MasterSlaveSlc;
//frame format
	tempCR1 |= SPI_Config->DataLength;
//clock/phase
	tempCR1|= SPI_Config->PolPhsClk;
//LSBMSB
	tempCR1|= SPI_Config->LsbMsb;

//NSS
	if(SPI_Config->NssPin == SPI_NSS_HW_MASTER_OUTPUT_DISABLE)
	{
		tempCR2 &= SPI_NSS_HW_MASTER_OUTPUT_DISABLE;
	}
	else if (SPI_Config->NssPin == SPI_NSS_HW_MASTER_OUTPUT_ENABLE)
	{
		tempCR2 |= SPI_NSS_HW_MASTER_OUTPUT_ENABLE;
	}
	else if (SPI_Config->NssPin == SPI_NSS_HW_SLAVE)
	{
		tempCR1 |= SPI_NSS_HW_SLAVE;
	}
	else if (SPI_Config->NssPin == SPI_NSS_SW_SET)
	{
		tempCR1|= SPI_NSS_SW_SET;
	}
	else if (SPI_Config->NssPin == SPI_NSS_SW_REST)
	{
		tempCR1|= SPI_NSS_SW_REST;
	}
	else
	{
		//DO NOTHING
	}
//BR
	tempCR1|= SPI_Config->BaudRate;
//IRQs
	if(SPI_Config->EnableIRQ != SPI_NONE_INTERRUPT)
	{
		tempCR2|= SPI_Config->EnableIRQ;

		if(SPIx == SPI_1)
		{
			SPI1_INTERRUPT_EN();

		}
		else if(SPIx == SPI_2)
		{
			 SPI2_INTERRUPT_EN();
		}

	}

	SPIx_Set_Pins(SPIx);
//write temp values to SPI registers
	SPIx->SPI_CR1= tempCR1;
	SPIx->SPI_CR2= tempCR2;

}

void SPIx_Set_Pins(volatile SPI_t *SPIx)
{
	if(SPIx == SPI_2)
	{
		if(gSPI_config[1]->MasterSlaveSlc==SPI_MASTER)
		{
			GPIO_Init_Output_Pin(GPIOB,GPIO_PIN13,OUTPUT_ALT_PUSH_PULL_2MHZ);//SCK
			GPIO_Init_Output_Pin(GPIOB,GPIO_PIN15,OUTPUT_ALT_PUSH_PULL_2MHZ);//MOSI
			GPIO_Init_Input_Pin(GPIOB,GPIO_PIN14,INPUT_FLOATING,0);//MISO
			GPIO_Init_Output_Pin(GPIOB,GPIO_PIN12,OUTPUT_ALT_PUSH_PULL_2MHZ);//NSS
		}
		else if (gSPI_config[1]->MasterSlaveSlc==SPI_SLAVE)
		{
			GPIO_Init_Input_Pin(GPIOB,GPIO_PIN13,INPUT_FLOATING,0);//SCK
			GPIO_Init_Input_Pin(GPIOB,GPIO_PIN15,INPUT_FLOATING,0);//MOSI
			GPIO_Init_Output_Pin(GPIOB,GPIO_PIN14,OUTPUT_ALT_PUSH_PULL_2MHZ);//MISO
			GPIO_Init_Input_Pin(GPIOB,GPIO_PIN12,INPUT_FLOATING,0);//NSS
		}
	}
	else if(SPIx == SPI_1)
	{
		if(gSPI_config[0]->MasterSlaveSlc==SPI_MASTER)
		{
			GPIO_Init_Output_Pin(GPIOA,GPIO_PIN5,OUTPUT_ALT_PUSH_PULL_2MHZ);//SCK
			GPIO_Init_Output_Pin(GPIOA,GPIO_PIN7,OUTPUT_ALT_PUSH_PULL_2MHZ);//MOSI
			GPIO_Init_Input_Pin(GPIOA,GPIO_PIN6,INPUT_FLOATING,0);//MISO
			GPIO_Init_Output_Pin(GPIOA,GPIO_PIN4,OUTPUT_ALT_PUSH_PULL_2MHZ);//SS
		}
		else if (gSPI_config[0]->MasterSlaveSlc==SPI_SLAVE)
		{
			GPIO_Init_Input_Pin(GPIOA,GPIO_PIN5,INPUT_FLOATING,0);//SCK
			GPIO_Init_Input_Pin(GPIOA,GPIO_PIN7,INPUT_FLOATING,0);//MOSI
			GPIO_Init_Output_Pin(GPIOA,GPIO_PIN6,OUTPUT_ALT_PUSH_PULL_2MHZ);//MISO
			GPIO_Init_Input_Pin(GPIOA,GPIO_PIN4,INPUT_FLOATING,0);//NSS
		}
	}
}
void SPIx_Dinit(volatile SPI_t *SPIx)
{
	if(SPIx==SPI_1)
	{
		SPI1_INTERRUPT_DIS();
		RCC_SPI1_RESET();
	}
	else if(SPIx==SPI_1)
	{
		SPI2_INTERRUPT_DIS();
		RCC_SPI2_RESET();
	}

}
void SPIx_SendData(volatile SPI_t *SPIx,uint16_t DATA,uint8_t ISpolling)
{
	if(ISpolling==1)
	while(!(SPIx->SPI_SR & (1U<<1)));//wait until buffer be empty
    SPIx->SPI_DR = DATA;
}

uint16_t SPIx_RecData(volatile SPI_t *SPIx,uint8_t ISpolling)
{
	if(ISpolling==1)
	while(!(SPIx->SPI_SR & (1U<<0)));//wait until buffer be not empty
    return (SPIx->SPI_DR);
}


uint16_t SPIx_TxRx(volatile SPI_t *SPIx,uint16_t DATA,uint8_t ISpolling)
{
	if(ISpolling==1)
		while(!(SPIx->SPI_SR & (1U<<1)));//wait until buffer be empty
	SPIx->SPI_DR = DATA;
	if(ISpolling==1)
		while(!(SPIx->SPI_SR & (1U<<0)));//wait until buffer be not empty
    return (SPIx->SPI_DR);

}

void SPIx_Start_Transmission(volatile SPI_t *SPIx,uint16_t DATA)
{
	while(!(SPIx->SPI_SR & (1U<<1)));//wait until buffer be empty
	SPIx->SPI_DR = DATA;
}

void SPI1_IRQHandler(void)
{

	//TX
	if(SPI_1->SPI_SR & (1U<<1))
	{
		//Wait until TXE=1 and write the second data item to be transmitted
		gIRQ_SRC.TXE = 1 ;
		gSPI_config[0]->ptrOfISR(gIRQ_SRC);
	}
	else if(SPI_1->SPI_SR & (1U<<0))
	{
		gIRQ_SRC.RXNE = 1 ;
		gSPI_config[0]->ptrOfISR(gIRQ_SRC);
	}
}
