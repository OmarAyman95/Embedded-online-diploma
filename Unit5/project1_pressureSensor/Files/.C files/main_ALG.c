#include "pressure_sensor.h"
#include "alarm.h"
#include "alarm_monitor.h"
#include "stdint.h"
static uint32_t p_val;
static const uint32_t threshould = 0x14;

int main(void)
{
    /* Modules initializations*/
    init_sensor();
    init_alarm();
	/* Loop forever */
	for(;;)
	{
	p_val = get_pressure_val();
    if(p_val > threshould) {high_pressure_detected();}
	}
	return 0;
}


