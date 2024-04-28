#ifndef __OLED_H
#define __OLED_H
#include "sys.h"
//////////////////////////////////////////////////////////////////////////////////	 
//������ֻ��ѧϰʹ�ã�δ��������ɣ��������������κ���;
//ALIENTEK STM32F429������
//OLED��������	   
//����ԭ��@ALIENTEK
//������̳:www.openedv.com
//��������:2016/1/6
//�汾��V1.0
//��Ȩ���У�����ؾ���
//Copyright(C) ������������ӿƼ����޹�˾ 2014-2024
//All rights reserved									  
////////////////////////////////////////////////////////////////////////////////// 	
//OLEDģʽ����
//0: 4�ߴ���ģʽ  ��ģ���BS1��BS2����GND��
//1: ����8080ģʽ ��ģ���BS1��BS2����VCC��
#define OLED_MODE 	0
		    						  
//-----------------OLED�˿ڶ���----------------  		
#define OLED_CS 	PBout(12)
#define OLED_RST  PBout(10)	
#define OLED_RS 	PBout(11)
#define OLED_WR 	PAout(4)		  
#define OLED_RD 	PDout(7) 
//ʹ��4�ߴ��нӿ�ʱʹ�� 
#define OLED_SCLK 	PDout(12)    //D0
#define OLED_SDIN 	PDout(13)    //D1
		     
#define OLED_CMD  	0		//д����
#define OLED_DATA 	1		//д����

//OLED�����ú���
void OLED_WR_Byte(u8 dat,u8 cmd);	    
void OLED_Display_On(void);
void OLED_Display_Off(void);
void OLED_Refresh_Gram(void);		   
							   		    
void OLED_Init(void);
void OLED_Clear(void);
void OLED_DrawPoint(u8 x,u8 y,u8 t);
void OLED_Fill(u8 x1,u8 y1,u8 x2,u8 y2,u8 dot);
void OLED_ShowChar(u8 x,u8 y,u8 chr,u8 size,u8 mode);
void OLED_ShowNum(u8 x,u8 y,u32 num,u8 len,u8 size);
void OLED_ShowString(u8 x,u8 y,const u8 *p,u8 size);
void OLED_ShowChinese(u8 x,u8 y,u8 chr,u8 size,u8 mode);
void OLED_ShowChinese2424(u16 x,u16 y,u8 index,u8 size);
void OLED_Set_Pos(unsigned char x, unsigned char y) ;
void OLED_Showfloat(u8 x,u8 y,float num,u8 size);

#endif
