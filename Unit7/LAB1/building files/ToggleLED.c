/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Omar Ayman
 * @brief          : Main program body
*/

#include "bspSM32.h"
 
int main(void)
{
	clock_init();
  	port_init();
    
    /* Loop forever */
	for(;;)
	{
		if(pinA01POLLING())
		{
			pinB01_TOGGLE();
			pinA01WAITING();
		}

		if(pinA13POLLING()) 
		{
			pinB13_TOGGLE();
		}
		delay_some_time();
	}
	return 0;
}

