#include "stm32f10x.h"
#include "Delay.h"
unsigned int count = 0;
/*配置中断*/
void countsensor_init(void)
{
	/*开启时钟*/
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO, ENABLE);
	
	/*配置GPIO(输入模式)*/
	
	GPIO_InitTypeDef GPIO_InitStruct;
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_IPU; //上拉，默认高电平
	GPIO_InitStruct.GPIO_Pin = GPIO_Pin_12;
	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOB, &GPIO_InitStruct);
	
	/*配置AFIO(配置使用GPIOB的 12号引脚作为中断线)*/
	
	GPIO_EXTILineConfig(GPIO_PortSourceGPIOB, GPIO_PinSource12);
	
	/*配置exti外部中断*/
	
	EXTI_InitTypeDef EXTI_InitStruct;
	EXTI_InitStruct.EXTI_Line = EXTI_Line12;
	EXTI_InitStruct.EXTI_LineCmd = ENABLE;
	EXTI_InitStruct.EXTI_Mode = EXTI_Mode_Interrupt;
	EXTI_InitStruct.EXTI_Trigger =  EXTI_Trigger_Rising;
	EXTI_Init(&EXTI_InitStruct);
	
	/*配置nvic*/
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);//非抢占式
	
	NVIC_InitTypeDef NVIC_InitStruct;
	NVIC_InitStruct.NVIC_IRQChannel = EXTI15_10_IRQn; //exti（10 - 15都是这个）使用这个通道
	NVIC_InitStruct.NVIC_IRQChannelCmd = ENABLE; //使能
	NVIC_InitStruct.NVIC_IRQChannelPreemptionPriority = 1;
	NVIC_InitStruct.NVIC_IRQChannelSubPriority = 1;
	
	NVIC_Init(&NVIC_InitStruct);
	
}	

void EXTI15_10_IRQHandler(void)
{
	Delay_ms(20);
	if (EXTI_GetITStatus(EXTI_Line12) == SET) {
		if (GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_12) == 1)
			count++;		
	
	}
	EXTI_ClearITPendingBit(EXTI_Line12);

}
uint32_t get_count(void)
{

	return count;

}