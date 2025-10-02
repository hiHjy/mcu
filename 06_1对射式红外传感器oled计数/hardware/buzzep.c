#include "stm32f10x.h"                  // Device header

void buzzep_init(void)
{
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB,ENABLE);
	GPIO_InitTypeDef GPIO_InitStruct;
	GPIO_InitStruct.GPIO_Mode =  GPIO_Mode_Out_PP;
	GPIO_InitStruct.GPIO_Pin = GPIO_Pin_12;
	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOB, &GPIO_InitStruct);
	
}

void buzzep_on(void)
{
	GPIO_ResetBits(GPIOB, GPIO_Pin_12);

}

void buzzep_off(void)
{
	GPIO_SetBits(GPIOB, GPIO_Pin_12);

}
void buzzep_turn(void)
{
	if (GPIO_ReadOutputDataBit(GPIOB, GPIO_Pin_12) == 0) {
		buzzep_on();
	
	
	} else if (GPIO_ReadOutputDataBit(GPIOB, GPIO_Pin_12) == 1){
			buzzep_off();
	}


}