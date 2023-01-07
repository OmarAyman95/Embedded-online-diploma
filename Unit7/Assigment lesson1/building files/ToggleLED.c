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
		pinB01_TOGGLE();delay_some_time(500);pinB01_TOGGLE();
		pinB13_TOGGLE();delay_some_time(500);pinB13_TOGGLE();
		pinB14_TOGGLE();delay_some_time(500);pinB14_TOGGLE();
		pinB15_Speaker();
	}
	return 0;
}

