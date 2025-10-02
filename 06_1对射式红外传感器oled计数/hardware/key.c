#include "stm32f10x.h"                  // Device header
#include "Delay.h"
void init_key(void)
{
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB,ENABLE);
	GPIO_InitTypeDef GPIO_InitStruct;
	GPIO_InitStruct.GPIO_Mode =  GPIO_Mode_IPU;
	GPIO_InitStruct.GPIO_Pin = GPIO_Pin_10 | GPIO_Pin_11;
	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOB, &GPIO_InitStruct);

}

uint8_t getKeyNum(void)
{
	uint8_t keyNum = 0;
	if (GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_10) == 0) {
		Delay_ms(30);
		while (GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_10) == 0);
		Delay_ms(30);
		keyNum = 1;
		
		
	}
	
	if (GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_11) == 0) {
		Delay_ms(30);
		while (GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_11) == 0);
		Delay_ms(30);
		keyNum = 11;
		
		
	}

	return keyNum;
}