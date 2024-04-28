#ifndef _CAR_H
#define _CAR_H
#include "sys.h"
#include "pid.h"
#include "openmv.h"
#include "timer.h"
#include "pwm.h"
#include "adc.h"
#include "my_usart.h"
#include "display.h"

//左前轮电机
#define IN1 PCout(0)
#define IN2 PCout(1)

//左后轮电机
#define IN3 PCout(2)
#define IN4 PCout(3)

//右前轮电机
#define IN5 PAout(1)
#define IN6 PAout(2)

//右后轮电机
#define IN7 PCout(6)
#define IN8 PCout(7)



void CAR_Init(void);
void CAR_GoForward(void);
void Car_Contorl(void);
void Car_Stop(void);
unsigned long millis(void);            //得到系统从启动到现在所经历的时间单位 ms。50 天后清零
void Car_PID_Init(void);

extern int LeftCompare,RightCompare;

#endif
