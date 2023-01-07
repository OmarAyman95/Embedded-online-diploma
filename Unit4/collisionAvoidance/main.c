/*
 ============================================================================
 Name        : Collision.c
 Author      : OMAR_AYMAN
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include "CA.h"
#include "US.h"
#include "DC_MOTOR.h"

void setup(void)
{
	US_init();
	DCMotor_init();
	/*init_:: Drivers:::IRQs:::HAL:::BLOCK*/
	CA_state_pointer = CA_waiting_state_func;
	US_state_pointer = US_busy_state_func;
	DC_state_pointer = DC_idle_state_func ;
}


int main(void) {

	setup();
	uint32_t i = 0 ;
	for(;i<=20;i++)
	{
		US_state_pointer();
		CA_state_pointer();
		DC_state_pointer();
	}
	return 0;
}
