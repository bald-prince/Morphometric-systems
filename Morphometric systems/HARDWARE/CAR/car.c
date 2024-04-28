#include "car.h"


PID_Class angle;


unsigned long ntick;            	//���ڿ�����ʱ���ɶ�ʱ���ж��޸�����ֵ��ÿ1ms��ֵ��+1
//***************************���õ������IO��***************************//
//�������L298Nģ��
//Ӳ������˵����
//PB6----ENA    �Һ��ֵ��PWM
//PC0----IN1    �����Һ��ֵ������
//PC1----IN2    

//PB7----ENB    ��ǰ�ֵ��PWM
//PC2----IN3    ������ǰ�ֵ������
//PC3----IN4 

//PB8----ENC    ����ֵ��PWM
//PA1----IN5    ��������ֵ������
//PA2----IN6    

//PB9----END    ����ֵ��PWM
//PC6----IN7    ��������ֵ������
//PC7----IN8   

//****************************************************************************************//

int i = 0;
double angle_output = 0;         
double angle_set = 0;            
int LeftCompare,RightCompare;

void CAR_Init(void)
{
	GPIO_InitTypeDef GPIO_Initure;
  __HAL_RCC_GPIOC_CLK_ENABLE();           
	__HAL_RCC_GPIOA_CLK_ENABLE(); 
	
  GPIO_Initure.Pin = GPIO_PIN_0|GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3|GPIO_PIN_6|GPIO_PIN_7; 
  GPIO_Initure.Mode = GPIO_MODE_OUTPUT_PP;  
  GPIO_Initure.Pull = GPIO_PULLUP;          
  GPIO_Initure.Speed = GPIO_SPEED_HIGH;    
  HAL_GPIO_Init(GPIOC,&GPIO_Initure);
	
	GPIO_Initure.Pin = GPIO_PIN_1|GPIO_PIN_2;
	HAL_GPIO_Init(GPIOA,&GPIO_Initure);
	
  HAL_GPIO_WritePin(GPIOC, GPIO_PIN_0|GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3|GPIO_PIN_6|GPIO_PIN_7,GPIO_PIN_SET);	
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_1|GPIO_PIN_2,GPIO_PIN_SET);
	
	
}

void Car_PID_Init(void)
{
	new_PID(&angle,&X,&angle_output,&angle_set,1.8,0,0,P_ON_E,DIRECT);		//PID������ʼ��������ģʽ�������
	/*
		//1.5  0.8    0
		//2.5  0.87   0
	*/
	PID_Initialize(&angle);																								//��ʼ��	
	PID_SetMode(&angle,AUTOMATIC);																				//�Զ�����ģʽ	
	PID_SetSampleTime(&angle,10);																					//����PID��������Ϊ10ms
	PID_SetOutputLimits(&angle,-40,40);																		//���output��ֵ�����Ʋ����������޸Ĵ˴�
}


void CAR_GoForward(void)    //ǰ��
{
	IN1 = 0;   IN2 = 1;
	IN3 = 0;   IN4 = 1;
	IN5 = 0;   IN6 = 1;
	IN7 = 0;   IN8 = 1;
}

void Car_Stop(void)        //ͣ��
{
	IN1 = 0;   IN2 = 0;
	IN3 = 0;   IN4 = 0;
	IN5 = 0;   IN6 = 0;
	IN7 = 0;   IN8 = 0;
}

/*С�����ƺ���*/
/************************************************/
//state = 0x01: Ѳ��

/*
	state = 0x02: ׷����
	����ⲻ���������С�������֮��ľ���С��50ʱ��
	С���Զ�ֹͣ
*/

/*
	state = 0x03: ׷С��
	����ⲻ��С�����С����С��֮��ľ���С��50ʱ��
	С���Զ�ֹͣ
*/


void Car_Contorl(void)
{
	OLED_Task();
	if(state == 0x01)
	{
		if( PID_Compute(&angle) == true )
		{
			LeftCompare = 500 - (12 * angle_output);
			RightCompare = 500 + (12 * angle_output);
			
			Set_LeftPwm_Compare(LeftCompare);
			Set_RightPwm_Compare(RightCompare);
			CAR_GoForward();
			
			i++;
			if(i == 15)
			{
				printf("RightCompare: %d\r\n",RightCompare);
				printf("LeftCompare: %d\r\n",LeftCompare);
				printf("angle_output: %f",angle_output);
				printf("\r\n");
				i = 0;
			}
		}
	}
	
	if(state == 0x02)
	{
		if( PID_Compute(&angle) == true )
		{
			if( distance < 50 )
			{
				Car_Stop();
			}
			else
			{
				LeftCompare = 500 - (12 * angle_output);
				RightCompare = 500 + (12 * angle_output);
			
				Set_LeftPwm_Compare(LeftCompare);
				Set_RightPwm_Compare(RightCompare);
				CAR_GoForward();
			}
		}
	}
	
	if(state == 0x03)
	{
		if( PID_Compute(&angle) == true )
		{
			if( distance < 10)
			{
				Car_Stop();
			}
			else
			{
				LeftCompare = 500 - (12 * angle_output);
				RightCompare = 500 + (12 * angle_output);
			
				Set_LeftPwm_Compare(LeftCompare);
				Set_RightPwm_Compare(RightCompare);
				CAR_GoForward();
			}
		}
	}
}




//*************************************************************************************************************
//�õ�ϵͳ��������������������ʱ�䵥λ ms��50 �������
unsigned long millis(void) 
{
	return ntick;
}
//*************************************************************************************************************






