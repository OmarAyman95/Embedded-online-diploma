/*
 * US.h
 *
 *  Created on: Oct 18, 2022
 *      Author: OMAR
 */

#ifndef US_H_
#define US_H_

#include "states.h"
enum{
	US_busy
}US_current_state;

STATE(US_busy_state_func);
uint32_t get_dist(uint32_t l,uint32_t r,uint32_t count);

void US_init(void);
extern void (*US_state_pointer)(void);
#endif /* US_H_ */
