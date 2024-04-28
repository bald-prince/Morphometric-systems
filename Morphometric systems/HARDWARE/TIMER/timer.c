#include "timer.h"


TIM_HandleTypeDef TIM3_Handler;      	//��ʱ����� 
TIM_HandleTypeDef TIM5_Handler; 
extern unsigned long ntick;

//ͨ�ö�ʱ��3�жϳ�ʼ��
//arr���Զ���װֵ��
//psc��ʱ��Ԥ��Ƶ��
//��ʱ�����ʱ����㷽��:Tout=((arr+1)*(psc+1))/Ft us.
//Ft=��ʱ������Ƶ��,��λ:Mhz
//����ʹ�õ��Ƕ�ʱ��3!(��ʱ��3����APB1�ϣ�ʱ��ΪHCLK/2)
void TIM3_Init(u16 arr,u16 psc)
{  
	TIM3_Handler.Instance=TIM3;                          //ͨ�ö�ʱ��3
  TIM3_Handler.Init.Prescaler=psc;                     //��Ƶϵ��
  TIM3_Handler.Init.CounterMode=TIM_COUNTERMODE_UP;    //���ϼ�����
  TIM3_Handler.Init.Period=arr;                        //�Զ�װ��ֵ
  TIM3_Handler.Init.ClockDivision=TIM_CLOCKDIVISION_DIV1;//ʱ�ӷ�Ƶ����
  HAL_TIM_Base_Init(&TIM3_Handler);
    
  HAL_TIM_Base_Start_IT(&TIM3_Handler); //ʹ�ܶ�ʱ��3�Ͷ�ʱ��3�����жϣ�TIM_IT_UPDATE   
}

void TIM5_Init(u16 arr,u16 psc)
{  
	TIM5_Handler.Instance=TIM5;                          //ͨ�ö�ʱ��3
  TIM5_Handler.Init.Prescaler=psc;                     //��Ƶϵ��
  TIM5_Handler.Init.CounterMode=TIM_COUNTERMODE_UP;    //���ϼ�����
  TIM5_Handler.Init.Period=arr;                        //�Զ�װ��ֵ
  TIM5_Handler.Init.ClockDivision=TIM_CLOCKDIVISION_DIV1;//ʱ�ӷ�Ƶ����
  HAL_TIM_Base_Init(&TIM5_Handler);
    
  HAL_TIM_Base_Start_IT(&TIM5_Handler); //ʹ�ܶ�ʱ��3�Ͷ�ʱ��3�����жϣ�TIM_IT_UPDATE   
}

//��ʱ���ײ�����������ʱ�ӣ������ж����ȼ�
//�˺����ᱻHAL_TIM_Base_Init()��������
void HAL_TIM_Base_MspInit(TIM_HandleTypeDef *htim)
{
  if(htim->Instance == TIM3)
	{
		__HAL_RCC_TIM3_CLK_ENABLE();            //ʹ��TIM3ʱ��
		HAL_NVIC_SetPriority(TIM3_IRQn,1,3);    //�����ж����ȼ�����ռ���ȼ�1�������ȼ�3
		HAL_NVIC_EnableIRQ(TIM3_IRQn);          //����ITM3�ж�   
	}
	
	if(htim->Instance == TIM5)
	{
		__HAL_RCC_TIM5_CLK_ENABLE();            //ʹ��TIM3ʱ��
		HAL_NVIC_SetPriority(TIM5_IRQn,1,3);    //�����ж����ȼ�����ռ���ȼ�1�������ȼ�3
		HAL_NVIC_EnableIRQ(TIM5_IRQn);          //����ITM3�ж�   
	}
}


//��ʱ��3�жϷ�����
void TIM3_IRQHandler(void)
{
	HAL_TIM_IRQHandler(&TIM3_Handler);
}

void TIM5_IRQHandler(void)
{
	HAL_TIM_IRQHandler(&TIM5_Handler);
}



//�ص���������ʱ���жϷ���������
int cnt = 0;
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
	if(htim == (&TIM3_Handler))
  {
		cnt++;
  }
}
