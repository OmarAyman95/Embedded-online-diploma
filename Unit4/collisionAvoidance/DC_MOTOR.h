/*
 * DC.h
 *
 *  Created on: Oct 18, 2022
 *      Author: OMAR
 */

#ifndef DC_H_
#define DC_H_

#include "states.h"
enum{
	DC_idle,
	DC_busy
}DC_current_state;

STATE(DC_idle_state_func);
STATE(DC_busy_state_func);
void DCMotor_init(void);

extern void (*DC_state_pointer)(void);
#endif /* DC_H_ */
