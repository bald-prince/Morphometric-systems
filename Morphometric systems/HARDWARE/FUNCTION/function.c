#include "function.h"

void ALL_Init(void)
{
	/*��س�ʼ��*/
  HAL_Init();                    	  
  Stm32_Clock_Init(336,8,2,7);    	        
	delay_init(168);               
	my_usart_init(115200);	
	OLED_Init();
	TIM3_Init(1000-1,84-1);       					//84M/84=1M    
																					//����ʱ�ӷ�Ƭ��pid��������
	GPIO_Init();
	KEY_Init();
}
