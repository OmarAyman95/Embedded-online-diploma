#ifndef ALARM_MONITOR_H_
#define ALARM_MONITOR_H_

#include "stdint.h"
void start_alarm(void);
void stop_alarm(void);

uint8_t high_pressure_detected(void);

#endif /* ALARM_MONITOR_H_ */