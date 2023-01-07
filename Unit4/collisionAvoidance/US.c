/*
 * CA.c
 *
 *  Created on: Oct 18, 2022
 *      Author: OMAR
 */
#include "US.h"
static uint32_t US_distance=0;

void (*US_state_pointer)(void);
void US_init(void)
{
	printf("US_init....Done\n");
}
STATE(US_busy_state_func)
{
	US_current_state=US_busy;
	US_distance = get_dist(45,55,1);
	printf("\nbusy_state \tUS_distance=%u\n",US_distance);
	US_set_distance(US_distance);
	US_state_pointer = US_busy_state_func;
}

uint32_t get_dist(uint32_t l,uint32_t r,uint32_t count)
{
	uint32_t i ;
	for(i=0;i<count;i++)
	{
		uint32_t randValue = (rand() % (r-l+1))+l;
		return (randValue);
	}
	return (50);
}
