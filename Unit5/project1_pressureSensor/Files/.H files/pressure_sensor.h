#ifndef PRESSURE_SENSOR_H_
#define PRESSURE_SENSOR_H_

#include "stdint.h"
void init_sensor(void);
uint32_t get_pressure_val(void);

#endif /* PRESSURE_SENSOR_H_ */