/**
 ******************************************************************************
 * @file           : SPI application layer
 * @author         : Omar Ayman
 * @brief          : Main program body
*/
#include "GPIOSTM32.h"
#include "SPISTM32.h"

void delay_ms(int x);
void clock_init(void);
void port_init(void);
void SPI_ISR(struct IRQ_SRC irqSPI);

char text2[]={"123456789"};
SPI_config SPI_config0=
{
	SPI_FULL_DUBLEX_TxRx,
	SPI_MASTER,
	SPI_BR_32,
	SPI_FIRST_EDGE_0IDLE,
	SPI_8bit_DATA,
	SPI_LSB_DATA,
	SPI_NSS_SW_SET,
	SPI_EN,
	SPI_NONE_INTERRUPT,
	SPI_ISR
};


int main(void)
{
	uint16_t buffer[10],i=0;
	clock_init();
  	port_init();

  	//set NSS
  	GPIO_Set_Pin_Atomic(GPIOA,GPIO_PIN0);
  	//wait until receiver initiate its TX buffer
  	delay_ms(50);
  	//initializations SPI
  	SPIx_init(SPI_1, &SPI_config0);
  	//Reset NSS
  	GPIO_Reset_Pin_Atomic(GPIOA,GPIO_PIN0);


  	buffer[i++] = SPIx_TxRx(SPI_1,0x88,1);
  	buffer[i++] = SPIx_TxRx(SPI_1,0x66,1);
  	buffer[i++] = SPIx_TxRx(SPI_1,0x44,1);
  	buffer[i] = SPIx_TxRx(SPI_1,0x22,1);


  	//wait busy flag
  	while((SPI_1->SPI_SR & (1U<<1)) && (SPI_1->SPI_SR & (1U<<7)));;
  	//set NSS
  	GPIO_Set_Pin_Atomic(GPIOA,GPIO_PIN0);

    /* Loop forever */

	for(;;)
	{
		for(;i>=0;i--)
		{
			GPIO_Write_port(GPIOB,buffer[i]);
			delay_ms(1000);
		}
	}

	return 0;
}

void delay_ms(int x)
{
	int i,j;
	for(i=0;i<x;i++){
	for(j=0;j<530;j++){}
	}
}

void clock_init(void)
{
	RCC->APB2ENR |=(IOPAEN | IOPBEN | AFIOEN |IOPCEN );
}

void port_init(void)
{
	GPIO_Init_All_Output(GPIOB,OUTPUT_PUSH_PULL_2MHZ_ALL);
	GPIO_Init_Output_Pin(GPIOA, GPIO_PIN0, OUTPUT_PUSH_PULL_2MHZ);
}


void SPI_ISR(struct IRQ_SRC irqSPI)
{

	if(irqSPI.TXE)
	{

	}
	else if(irqSPI.RXNE)
	{

	}

}
