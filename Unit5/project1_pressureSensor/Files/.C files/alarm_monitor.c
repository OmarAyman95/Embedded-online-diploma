#include "alarm_monitor.h"
#include "alarm.h"

static uint32_t alarm_timer;
static const uint32_t alarm_period = 60;//60 counts are roughly equal to 20 seconds
uint8_t high_pressure_detected(void)
{
	while(alarm_timer<=alarm_period)
	{
	start_alarm();
	alarm_timer++;
	}
	alarm_timer = 0 ;
	stop_alarm();
}
