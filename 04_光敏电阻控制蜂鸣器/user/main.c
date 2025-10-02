#include "stm32f10x.h"
#include "Delay.h"
#include "../buzzep.h"
#include "../light_sensor.h"

int main(void){
	uint8_t value = 0;
	buzzep_init();
	light_sensor_init();
	while (1) {
		value = light_sensor_get();
		if (value == 1) {
			buzzep_off();
		} else {
			
			buzzep_on();
		}
		
		
	}

}
