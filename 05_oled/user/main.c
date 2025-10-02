#include "stm32f10x.h"
#include "Delay.h"
#include "buzzep.h"
#include "light_sensor.h"
#include "OLED.h"
int main(void){
	OLED_Init();
	OLED_ShowChar(1, 1, 'A');
	OLED_ShowString(2, 1, "hello--world");
	Delay_s(3);
	OLED_Clear();
	while (1) {
		
		
		
	}

}
