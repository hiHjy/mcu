#include "../led.h"
#include "stm32f10x.h"                  // Device header
#include "Delay.h"
#include <../key.h>
uint8_t key1_status = 0;
uint8_t key11_status = 0;
uint8_t keyNum = 0;
int main (void)
{
	init_led();
	init_key();
	while (1) {
		
//		led0_on();
//		Delay_ms(500);
//		led0_off();
//		Delay_ms(500);
//		led2_on();
//		Delay_ms(500);
//		led2_off();
//		Delay_ms(500);
		
		if (getKeyNum() == 1){
			led0_turn();
				
		}
		
		if (getKeyNum() == 11) {
			led2_turn();
		
		}
		
		
		
	}
	return 0;
}
