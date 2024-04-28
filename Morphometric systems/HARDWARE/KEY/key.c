#include "key.h"



//按键初始化函数
void KEY_Init(void)
{
	GPIO_InitTypeDef GPIO_Initure;
  __HAL_RCC_GPIOG_CLK_ENABLE();           //开启GPIOG时钟
	GPIO_Initure.Pin=GPIO_PIN_9|GPIO_PIN_10|GPIO_PIN_11|GPIO_PIN_13; //PG9,10,11,13
  GPIO_Initure.Mode=GPIO_MODE_INPUT;      //输入
  GPIO_Initure.Pull=GPIO_PULLUP;          //上拉
  GPIO_Initure.Speed=GPIO_SPEED_HIGH;     //高速
  HAL_GPIO_Init(GPIOG,&GPIO_Initure);
	
	__HAL_RCC_GPIOA_CLK_ENABLE();
	GPIO_Initure.Pin=GPIO_PIN_0;
	GPIO_Initure.Pull=GPIO_PULLDOWN; 
	HAL_GPIO_Init(GPIOA,&GPIO_Initure);
}


/*按键扫描*/
u8 key_state;
void Key_Scan(void)
{
	switch(key_state)
	{
		case key_state_0:
			if(!KEY0)      										//按键按下，进入状态1
				key_state = key_state_1;
			break;
			case key_state_1:     
			if(!KEY0)     											//如果没有弹起进入状态2
																				//如果弹起则是为按键抖动，回到状态0重新检测
				key_state = key_state_2;
			else
				key_state=key_state_0;
			break;
			case key_state_2:    								//如果按键弹起，则视为按了一次，进行相应的数据处理，反之不进行任何处理
				if(KEY0)
				{
					key_state=key_state_0;
					//LED0 = 1;
				}
			break;
				
		}
}


