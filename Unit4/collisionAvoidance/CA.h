/*
 * CA.h
 *
 *  Created on: Oct 18, 2022
 *      Author: OMAR
 */

#ifndef CA_H_
#define CA_H_


#include "states.h"
enum{
	CA_waiting,
	CA_driving
}CA_current_state;

STATE(CA_waiting_state_func);
STATE(CA_driving_state_func);

uint32_t get_dist(uint32_t l,uint32_t r,uint32_t count);

extern void (*CA_state_pointer)(void);
#endif /* CA_H_ */
