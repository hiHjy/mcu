#include "stm32f10x.h"
#include "led.h"
void init_led(void)
{
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);
	GPIO_InitTypeDef GPIO_InitStruct;
	GPIO_InitStruct.GPIO_Mode =  GPIO_Mode_Out_PP;
	GPIO_InitStruct.GPIO_Pin = GPIO_Pin_0 | GPIO_Pin_2;
	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA, &GPIO_InitStruct);
	GPIO_SetBits(GPIOA, GPIO_Pin_0);
	GPIO_SetBits(GPIOA, GPIO_Pin_2);
}

void led0_on(void)
{
	GPIO_ResetBits(GPIOA, GPIO_Pin_0);

}

void led0_off(void)
{
	GPIO_SetBits(GPIOA, GPIO_Pin_0);

}

void led2_on(void)
{
	GPIO_ResetBits(GPIOA, GPIO_Pin_2);

}

void led2_off(void)
{
	GPIO_SetBits(GPIOA, GPIO_Pin_2);

}

void led0_turn(void)
{
	if (GPIO_ReadOutputDataBit(GPIOA, GPIO_Pin_0) == 0) {
		led0_off();
	
	
	} else if (GPIO_ReadOutputDataBit(GPIOA, GPIO_Pin_0) == 1){
		led0_on();
	}


}

void led2_turn(void)
{
	if (GPIO_ReadOutputDataBit(GPIOA, GPIO_Pin_2) == 0) {
		led2_off();
	
	
	} else if (GPIO_ReadOutputDataBit(GPIOA, GPIO_Pin_2) == 1){
		led2_on();
	}


}