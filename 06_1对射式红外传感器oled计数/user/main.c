#include "stm32f10x.h"
#include "Delay.h"
#include "buzzep.h"
#include "light_sensor.h"
#include "OLED.h"
#include "countsensor.h"
int main(void){
	OLED_Init();
	countsensor_init();

	while (1) {
		
		OLED_ShowNum(1, 1, get_count(),5);
		
		
	}

}
