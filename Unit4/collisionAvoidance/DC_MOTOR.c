/*
 * CA.c
 *
 *  Created on: Oct 18, 2022
 *      Author: OMAR
 */
#include "DC_MOTOR.h"
static uint32_t DC_speed=0;
void (*DC_state_pointer)(void);
void DCMotor_init(void)
{
	printf("Motor_init.....Done\n");
}
void DC_motor(int S)
{
	DC_speed = S;
	DC_state_pointer = DC_busy_state_func;
	printf("DC_motor---------------speed = %d",DC_speed);
}
STATE(DC_idle_state_func)
{
	DC_current_state = DC_idle ;
	printf("DC_idle_state_func---------------speed = %d",DC_speed);

}
STATE(DC_busy_state_func)
{
	DC_current_state = DC_busy ;
	DC_state_pointer = DC_idle_state_func;
	printf("DC_busy_state_func---------------speed = %d",DC_speed);
}

