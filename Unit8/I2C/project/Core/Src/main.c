/**
 ******************************************************************************
 * @file           : I2C application layer
 * @author         : Omar Ayman
 * @brief          : Main program body
*/
#include "GPIOSTM32.h"
#include "clockSTM32.h"
#include "I2CSTM32.h"
#include "EEPROM_I2C.h"

//prototypes
void delay_ms(int x);
void clock_En_init(void);
void port_init(void);

int main(void)
{
	clock_En_init();
	port_init();
	uint8_t myName[33]="24AA64 EEPROM I2C";

	//_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_ I2C init _*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*
	//======================================================================================================
	I2C_config I2C_struct_config;
	I2C_struct_config.ClockStretchingEnable = I2C_STRETCHING_EN;
	I2C_struct_config.I2CAckEnable = I2C_ACK_EN;
	I2C_struct_config.General_Call_Address_Detection=I2C_GEN_CALL_EN;
	I2C_struct_config.I2CBusSpeed = I2C_CLOCK_SM_100K;
	I2C_struct_config.I2CDeviceMode = I2C_I2C_MODE;
	I2C_struct_config.ptrToSlaveEventISR = NULL;
	I2C_init(I2C_1, &I2C_struct_config);
	//======================================================================================================

	//_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_ HAL CALL _*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*
	//======================================================================================================
	//____________________________________________WRITE___________________________________________________
/*	uint16_t i ;
	for(i=0x1000;i<=0x1500;i+=32)
	{
	EEPROM_I2C_Ext_Write(EEPROM3_ADDRESS, i,myName,sizeof(myName));
	delay_ms(20);
	}
*/

//_________________________________________________READ_____________________________________________________


	uint8_t i, data_buffer[32];
	EEPROM_I2C_Ext_Read(EEPROM0_ADDRESS,0x1000,data_buffer,12);

//_________________________________________________PRINT____________________________________________________

	for(i=0;i<=11;i++)
	{
	GPIO_Write_port(GPIOA,data_buffer[i]);
	delay_ms(500);
	}


	//======================================================================================================
	for(;;)
	{
		//just to check the HAL is DONE
		GPIO_Toggle_Pin(GPIOA,GPIO_PIN14);
		delay_ms(100);
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
void clock_En_init(void)
{
	RCC->APB2ENR |=(IOPBEN | IOPAEN);
}

void port_init(void)
{
	GPIO_Init_All_Output(GPIOA,OUTPUT_PUSH_PULL_10MHZ_ALL);
}

