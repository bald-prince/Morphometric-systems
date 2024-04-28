#include "key.h"



//������ʼ������
void KEY_Init(void)
{
	GPIO_InitTypeDef GPIO_Initure;
  __HAL_RCC_GPIOG_CLK_ENABLE();           //����GPIOGʱ��
	GPIO_Initure.Pin=GPIO_PIN_9|GPIO_PIN_10|GPIO_PIN_11|GPIO_PIN_13; //PG9,10,11,13
  GPIO_Initure.Mode=GPIO_MODE_INPUT;      //����
  GPIO_Initure.Pull=GPIO_PULLUP;          //����
  GPIO_Initure.Speed=GPIO_SPEED_HIGH;     //����
  HAL_GPIO_Init(GPIOG,&GPIO_Initure);
	
	__HAL_RCC_GPIOA_CLK_ENABLE();
	GPIO_Initure.Pin=GPIO_PIN_0;
	GPIO_Initure.Pull=GPIO_PULLDOWN; 
	HAL_GPIO_Init(GPIOA,&GPIO_Initure);
}


/*����ɨ��*/
u8 key_state;
void Key_Scan(void)
{
	switch(key_state)
	{
		case key_state_0:
			if(!KEY0)      										//�������£�����״̬1
				key_state = key_state_1;
			break;
			case key_state_1:     
			if(!KEY0)     											//���û�е������״̬2
																				//�����������Ϊ�����������ص�״̬0���¼��
				key_state = key_state_2;
			else
				key_state=key_state_0;
			break;
			case key_state_2:    								//���������������Ϊ����һ�Σ�������Ӧ�����ݴ�����֮�������κδ���
				if(KEY0)
				{
					key_state=key_state_0;
					//LED0 = 1;
				}
			break;
				
		}
}


