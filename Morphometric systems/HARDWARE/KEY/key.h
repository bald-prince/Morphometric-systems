#ifndef _KEY_H
#define _KEY_H
#include "sys.h"
#include "delay.h"
#include "gpio.h"


#define key_state_0  0
#define key_state_1  1
#define key_state_2  2

#define lock        0
#define unlock      1


//����ķ�ʽ��ͨ��ֱ�Ӳ���HAL�⺯����ʽ��ȡIO
#define KEY0        HAL_GPIO_ReadPin(GPIOG,GPIO_PIN_9)    			//KEY0����PE4



void KEY_Init(void);
u8 KEY_Scan(u8 mode);
void Key_Scan(void);


#endif
