#include "my_usart.h"
#include "sys.h"
#include "string.h"
#include "openmv.h"

/**************����ͨ��IO������***************/
//PA9(TXD)--------P5(RXD)
//PA10(RXD)-------P4(TXD)
//OpenMv��STM32��Ҫ����
/*********************************************/

int fputc(int ch, FILE *f)
{ 	
	while( (USART1->SR&0X40) == 0);     //ѭ������,ֱ���������   
	USART1->DR = (u8) ch;      
	return ch;
}


UART_HandleTypeDef UART1_Handler;     //UART���
u8 USART_RX_BUF[USART_REC_LEN];       //���ջ���,���USART_REC_LEN���ֽ�.
                                      //����״̬
                                      //bit15��	������ɱ�־
                                      //bit14��	���յ�0x0d
                                      //bit13~0��	���յ�����Ч�ֽ���Ŀ
u16 USART_RX_STA = 0;                 //����״̬���

u8 aRxBuffer[RXBUFFERSIZE];           //HAL��ʹ�õĴ��ڽ��ջ���

void my_usart_init(u32 bound)
{
	UART1_Handler.Instance = USART1;					            
	UART1_Handler.Init.BaudRate = bound;				         
	UART1_Handler.Init.WordLength = UART_WORDLENGTH_8B;   
	UART1_Handler.Init.StopBits = UART_STOPBITS_1;	      
	UART1_Handler.Init.Parity = UART_PARITY_NONE;		      
	UART1_Handler.Init.HwFlowCtl = UART_HWCONTROL_NONE;   
	UART1_Handler.Init.Mode = UART_MODE_TX_RX;		        
	HAL_UART_Init(&UART1_Handler);					              
	
	__HAL_UART_ENABLE_IT(&UART1_Handler,UART_IT_RXNE);     
}

//UART�ײ��ʼ����ʱ��ʹ�ܣ��������ã��ж�����
//�˺����ᱻHAL_UART_Init()����
//huart:���ھ��
//PA9:TXD(����)   PA10:RXD�����գ�
void HAL_UART_MspInit(UART_HandleTypeDef *huart)
{
	GPIO_InitTypeDef GPIO_Initure;
	
	if(huart->Instance == USART1)                   
	{
		__HAL_RCC_GPIOA_CLK_ENABLE();			            
		__HAL_RCC_USART1_CLK_ENABLE();			          
	
		GPIO_Initure.Pin = GPIO_PIN_9;			         
		GPIO_Initure.Mode = GPIO_MODE_AF_PP;		      
		GPIO_Initure.Pull = GPIO_PULLUP;			        
		GPIO_Initure.Speed = GPIO_SPEED_FAST;		     
		GPIO_Initure.Alternate = GPIO_AF7_USART1;	    
		HAL_GPIO_Init(GPIOA,&GPIO_Initure);	   	     

		GPIO_Initure.Pin = GPIO_PIN_10;			          
		HAL_GPIO_Init(GPIOA,&GPIO_Initure);	   	      
		
		HAL_NVIC_EnableIRQ(USART1_IRQn);				      
		HAL_NVIC_SetPriority(USART1_IRQn,3,3);			  
	}
}

u8 len;	
u16 t;

void USART1_IRQHandler(void)                	
{ 
	u8 Res;
	if( (__HAL_UART_GET_FLAG(&UART1_Handler,UART_FLAG_RXNE) != RESET) )  //�����ж�(���յ������ݱ�����0x0d 0x0a��β)
	{
    HAL_UART_Receive(&UART1_Handler,&Res,1,1000); 
		if( (USART_RX_STA & 0x8000) == 0 )                          //����δ���
		{
			if( USART_RX_STA & 0x4000)                               //���յ���0x0d
			{
				if(Res != 0x0a)
					USART_RX_STA = 0;                                  //���մ���,���¿�ʼ
				else 
					USART_RX_STA |= 0x8000;	                      //��������� 
			}
			else                                                 //��û�յ�0X0D
			{	
				if(Res == 0x0d)
					USART_RX_STA |= 0x4000;
				else
				{
					USART_RX_BUF[USART_RX_STA & 0X3FFF] = Res ;
					USART_RX_STA++;
					if( USART_RX_STA > (USART_REC_LEN-1) )
						USART_RX_STA = 0;                             //�������ݴ���,���¿�ʼ����	  
				}		 
			}
		}
		if( USART_RX_STA & 0x8000 )
		{
			len = USART_RX_STA & 0x3FFF;
			for(t = 0;t < len;t++)
			{
				Receive_Prepare(USART_RX_BUF[t]);
				while( (USART1->SR & 0X40) == 0);
			}
			USART_RX_STA = 0;
			printf("��־λ:%d\r\n",state);
			printf("ֱ����%f\r\n",side_length);
			printf("���룺%f\r\n",distance);
			printf("\r\n");
		}
		HAL_UART_IRQHandler(&UART1_Handler);	
	} 
}
