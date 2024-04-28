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

//��ǰ�ֵ��
#define IN1 PCout(0)
#define IN2 PCout(1)

//����ֵ��
#define IN3 PCout(2)
#define IN4 PCout(3)

//��ǰ�ֵ��
#define IN5 PAout(1)
#define IN6 PAout(2)

//�Һ��ֵ��
#define IN7 PCout(6)
#define IN8 PCout(7)



void CAR_Init(void);
void CAR_GoForward(void);
void Car_Contorl(void);
void Car_Stop(void);
unsigned long millis(void);            //�õ�ϵͳ��������������������ʱ�䵥λ ms��50 �������
void Car_PID_Init(void);

extern int LeftCompare,RightCompare;

#endif
