#include "car.h"


PID_Class angle;


unsigned long ntick;            	//用于开机计时，由定时器中断修改它的值，每1ms数值会+1
//***************************配置电机驱动IO口***************************//
//电机驱动L298N模块
//硬件连接说明：
//PB6----ENA    右后轮电机PWM
//PC0----IN1    控制右后轮电机正反
//PC1----IN2    

//PB7----ENB    右前轮电机PWM
//PC2----IN3    控制右前轮电机正反
//PC3----IN4 

//PB8----ENC    左后轮电机PWM
//PA1----IN5    控制左后轮电机正反
//PA2----IN6    

//PB9----END    左后轮电机PWM
//PC6----IN7    控制左后轮电机正反
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
	new_PID(&angle,&X,&angle_output,&angle_set,1.8,0,0,P_ON_E,DIRECT);		//PID参数初始化，正常模式，正相关
	/*
		//1.5  0.8    0
		//2.5  0.87   0
	*/
	PID_Initialize(&angle);																								//初始化	
	PID_SetMode(&angle,AUTOMATIC);																				//自动计算模式	
	PID_SetSampleTime(&angle,10);																					//设置PID计算周期为10ms
	PID_SetOutputLimits(&angle,-40,40);																		//如果output的值被限制不能增大，则修改此处
}


void CAR_GoForward(void)    //前进
{
	IN1 = 0;   IN2 = 1;
	IN3 = 0;   IN4 = 1;
	IN5 = 0;   IN6 = 1;
	IN7 = 0;   IN8 = 1;
}

void Car_Stop(void)        //停车
{
	IN1 = 0;   IN2 = 0;
	IN3 = 0;   IN4 = 0;
	IN5 = 0;   IN6 = 0;
	IN7 = 0;   IN8 = 0;
}

/*小车控制函数*/
/************************************************/
//state = 0x01: 巡线

/*
	state = 0x02: 追红外
	当检测不到红外或者小车与红外之间的距离小于50时，
	小车自动停止
*/

/*
	state = 0x03: 追小球
	当检测不到小球或者小车与小球之间的距离小于50时，
	小车自动停止
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
//得到系统从启动到现在所经历的时间单位 ms。50 天后清零
unsigned long millis(void) 
{
	return ntick;
}
//*************************************************************************************************************






