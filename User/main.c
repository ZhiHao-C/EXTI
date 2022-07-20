#include "stm32f10x.h"                  // Device header
#include "bps_led.h"
#include "bps_exti.h"
void delay_ms(int n)//延时函数
{
	int i;
	while (n--)
	{
		for(i=0;i<5520;i++);
	}
}



int main()
{
//	LED_G_GPIO_Config();
//	while (1)
//	{
//		led(on);
//		delay_ms(1000);
//		led(off);
//		delay_ms(1000);
//	}
	LED_G_GPIO_Config();
	EXTI_KEY1_Config();
	while(1)
	{}
}
void EXTI0_IRQHandler ()//EXTI0中断函数名称（在startup查询）
{
	if(EXTI_GetFlagStatus(EXTI_Line0)==1)
	{
		LED_G_GPIO_PORT->ODR^=1;
	}
	EXTI_ClearITPendingBit(EXTI_Line0);
}
	
