#include "gpio.h"

void GPIO_Init(void)
{
	GPIO_InitTypeDef GPIO_Initure;
  __HAL_RCC_GPIOB_CLK_ENABLE();    
	__HAL_RCC_GPIOC_CLK_ENABLE(); 	
	
  GPIO_Initure.Pin=GPIO_PIN_0;						  		
  GPIO_Initure.Mode=GPIO_MODE_OUTPUT_PP;  							
  GPIO_Initure.Pull=GPIO_PULLUP;          						
  GPIO_Initure.Speed=GPIO_SPEED_HIGH;     							
  HAL_GPIO_Init(GPIOB,&GPIO_Initure);
	
	GPIO_Initure.Pin=GPIO_PIN_0;	
	HAL_GPIO_Init(GPIOC,&GPIO_Initure);

  HAL_GPIO_WritePin(GPIOB,GPIO_PIN_0,GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOC,GPIO_PIN_0,GPIO_PIN_RESET);
}

