#include"bsp.h"
#include "pressure_sensor.h"

static uint32_t p_val;
static uint32_t Psensor_pull_time ;
void init_sensor(void)
{
	//Enable clock of GPIOA
	RCC_APB2ENR |=IOPAEN;
	//wait some time 
	WAIT(5000);
	//clear all bits 0~7
	GPIOA_CRL &= ~(0xffffffffU);
	//digital inputs
	GPIOA_CRL |=(0x88888888U);
}

uint32_t get_pressure_val(void)
{
	 // pull time [do nothing] about 20 second 
	while(Psensor_pull_time <=100){WAIT(30000);Psensor_pull_time++;}
	Psensor_pull_time=0;
	//start reading ...
	 p_val = GPIOA_IDR;
	 return p_val;
}
