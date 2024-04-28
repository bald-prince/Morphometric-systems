#ifndef _TIMER_H
#define _TIMER_H
#include "sys.h"
	
extern TIM_HandleTypeDef TIM3_Handler;      //¶¨Ê±Æ÷¾ä±ú 
extern TIM_HandleTypeDef TIM5_Handler;


extern int cnt;

void TIM3_Init(u16 arr,u16 psc);
void TIM5_Init(u16 arr,u16 psc);


#endif
