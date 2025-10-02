#include "stm32f10x.h"
#include "Encoder.h"
#include "OLED.h"
int num = 0;
int main(void){
	OLED_Init();
	encoder_init();

	while (1) {
		num +=  get_count();
		OLED_ShowSignedNum(1, 1, num,5);
		
		
	}

}
