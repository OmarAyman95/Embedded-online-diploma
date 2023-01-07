/*
 * CA.c
 *
 *  Created on: Oct 18, 2022
 *      Author: OMAR
 */
#include "CA.h"
static uint32_t CA_speed=0;
static uint32_t CA_distance=0;
static uint32_t CA_threshould=50;
void (*CA_state_pointer)(void);
void US_set_distance(int D)
{
	CA_distance=D;
	if (CA_distance <= CA_threshould)
	{
		CA_state_pointer = CA_waiting_state_func;
	}
	else
	{
		CA_state_pointer = CA_driving_state_func;
	}
	printf("US---------------distance = %d------>CA",CA_distance);
}
STATE(CA_waiting_state_func)
{
	CA_current_state = CA_waiting;
	printf("\nwaiting_state \tCA_distance=%u\tCA_speed=%u\n",CA_distance,CA_speed);
	CA_speed = 0 ;
	DC_motor(CA_speed);
}
STATE(CA_driving_state_func)
{
	CA_current_state = CA_driving;
	printf("\ndriving_state \tCA_distance=%u\tCA_speed=%u\n",CA_distance,CA_speed);
	CA_speed = 30 ;
	DC_motor(CA_speed);
}

