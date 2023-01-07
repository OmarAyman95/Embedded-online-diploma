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
   interrupt_init();
    /* Loop forever */
	for(;;)
	{
	//pin06POLLING();	
	//pin13_TOGGLE();

	}
	return 0;
}

