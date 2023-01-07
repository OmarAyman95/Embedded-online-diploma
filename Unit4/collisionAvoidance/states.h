/*
 * states.h
 *
 *  Created on: Oct 18, 2022
 *      Author: OMAR
 */

#ifndef STATES_H_
#define STATES_H_

#include "stdint.h"
#include "stdio.h"
#include "stdlib.h"

#define STATE(x)   void x(void)

void US_set_distance(int D);
void DC_motor(int S);

#endif /* STATES_H_ */
