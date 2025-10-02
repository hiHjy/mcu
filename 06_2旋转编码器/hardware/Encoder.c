#include "stm32f10x.h"
#include "Delay.h"
int16_t EncoderCount = 0;

void encoder_init(void)
{
	/*开启时钟*/
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO, ENABLE);
	
	/*配置GPIO(输入模式)*/
	
	GPIO_InitTypeDef GPIO_InitStruct;
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_IPU; //上拉，默认高电平
	GPIO_InitStruct.GPIO_Pin = GPIO_Pin_0 | GPIO_Pin_1;
	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOB, &GPIO_InitStruct);
	
	
	/*配置AFIO(配置使用GPIOB的 0号和1号引脚作为中断线)*/
	
	GPIO_EXTILineConfig(GPIO_PortSourceGPIOB, GPIO_PinSource0);
	GPIO_EXTILineConfig(GPIO_PortSourceGPIOB, GPIO_PinSource1);
	
	/*配置exti外部中断*/
	
	EXTI_InitTypeDef EXTI_InitStruct;
	EXTI_InitStruct.EXTI_Line = EXTI_Line0 | EXTI_Line1;
	EXTI_InitStruct.EXTI_LineCmd = ENABLE;
	EXTI_InitStruct.EXTI_Mode = EXTI_Mode_Interrupt;
	EXTI_InitStruct.EXTI_Trigger =  EXTI_Trigger_Falling;
	EXTI_Init(&EXTI_InitStruct);
	
	/*配置nvic*/
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);//非抢占式
	
	NVIC_InitTypeDef NVIC_InitStruct;
	NVIC_InitStruct.NVIC_IRQChannel = EXTI0_IRQn; //exti（10 - 15都是这个）使用这个通道
	NVIC_InitStruct.NVIC_IRQChannelCmd = ENABLE; //使能
	NVIC_InitStruct.NVIC_IRQChannelPreemptionPriority = 1;
	NVIC_InitStruct.NVIC_IRQChannelSubPriority = 1;
	NVIC_Init(&NVIC_InitStruct);
	
	NVIC_InitStruct.NVIC_IRQChannel = EXTI1_IRQn; //exti（10 - 15都是这个）使用这个通道
	NVIC_InitStruct.NVIC_IRQChannelCmd = ENABLE; //使能
	NVIC_InitStruct.NVIC_IRQChannelPreemptionPriority = 1;
	NVIC_InitStruct.NVIC_IRQChannelSubPriority = 2;
	NVIC_Init(&NVIC_InitStruct);
}



void EXTI0_IRQHandler(void)
{
	Delay_ms(5);
	if (EXTI_GetITStatus(EXTI_Line0) == SET) {
		if (GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_1) == 0) {
			EncoderCount--;
			
		}
		EXTI_ClearITPendingBit(EXTI_Line0);
	}
	



}

void EXTI1_IRQHandler(void)
{
	Delay_ms(5);
	if (EXTI_GetITStatus(EXTI_Line1) == SET) {
		
		if (GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_0) == 0) {
			EncoderCount++;
			
		}
		
		EXTI_ClearITPendingBit(EXTI_Line1);
	}



}
int16_t get_count(void) 
{
	int tmp = EncoderCount;
	EncoderCount = 0;
	return tmp;
}