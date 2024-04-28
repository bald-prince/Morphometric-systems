#include "my_usart.h"
#include "sys.h"
#include "string.h"
#include "openmv.h"

/**************串口通信IO口连接***************/
//PA9(TXD)--------P5(RXD)
//PA10(RXD)-------P4(TXD)
//OpenMv与STM32需要共地
/*********************************************/

int fputc(int ch, FILE *f)
{ 	
	while( (USART1->SR&0X40) == 0);     //循环发送,直到发送完毕   
	USART1->DR = (u8) ch;      
	return ch;
}


UART_HandleTypeDef UART1_Handler;     //UART句柄
u8 USART_RX_BUF[USART_REC_LEN];       //接收缓冲,最大USART_REC_LEN个字节.
                                      //接收状态
                                      //bit15，	接收完成标志
                                      //bit14，	接收到0x0d
                                      //bit13~0，	接收到的有效字节数目
u16 USART_RX_STA = 0;                 //接收状态标记

u8 aRxBuffer[RXBUFFERSIZE];           //HAL库使用的串口接收缓冲

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

//UART底层初始化，时钟使能，引脚配置，中断配置
//此函数会被HAL_UART_Init()调用
//huart:串口句柄
//PA9:TXD(发送)   PA10:RXD（接收）
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
	if( (__HAL_UART_GET_FLAG(&UART1_Handler,UART_FLAG_RXNE) != RESET) )  //接收中断(接收到的数据必须是0x0d 0x0a结尾)
	{
    HAL_UART_Receive(&UART1_Handler,&Res,1,1000); 
		if( (USART_RX_STA & 0x8000) == 0 )                          //接收未完成
		{
			if( USART_RX_STA & 0x4000)                               //接收到了0x0d
			{
				if(Res != 0x0a)
					USART_RX_STA = 0;                                  //接收错误,重新开始
				else 
					USART_RX_STA |= 0x8000;	                      //接收完成了 
			}
			else                                                 //还没收到0X0D
			{	
				if(Res == 0x0d)
					USART_RX_STA |= 0x4000;
				else
				{
					USART_RX_BUF[USART_RX_STA & 0X3FFF] = Res ;
					USART_RX_STA++;
					if( USART_RX_STA > (USART_REC_LEN-1) )
						USART_RX_STA = 0;                             //接收数据错误,重新开始接收	  
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
			printf("标志位:%d\r\n",state);
			printf("直径：%f\r\n",side_length);
			printf("距离：%f\r\n",distance);
			printf("\r\n");
		}
		HAL_UART_IRQHandler(&UART1_Handler);	
	} 
}
