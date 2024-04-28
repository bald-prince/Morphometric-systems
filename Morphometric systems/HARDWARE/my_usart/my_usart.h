#ifndef _MY_USART_H
#define _MY_USART_H
#include "sys.h"
#include "stdio.h"	

#define USART_REC_LEN  			200  	             //�����������ֽ��� 200
#define EN_USART1_RX 			1		                 //ʹ�ܣ�1��/��ֹ��0������1����
#define MAX_DATA_LENS       10
#define RXBUFFERSIZE   1  

extern UART_HandleTypeDef UART1_Handler;       //UART���

void my_usart_init(u32 bound);

	  	 
extern u8  USART_RX_BUF[USART_REC_LEN];        //���ջ���,���USART_REC_LEN���ֽ�.ĩ�ֽ�Ϊ���з� 
extern u16 USART_RX_STA;         		           //����״̬���	
extern u8 control_data[MAX_DATA_LENS];

extern u8 OpenMV_Rx_BUF[8];

                     //�����С
extern u8 aRxBuffer[RXBUFFERSIZE];             //HAL��USART����Buffer

#endif



