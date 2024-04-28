#include "display.h"


void OLED_Task(void)
{
	switch(state)
	{
		case 0x01:
			/*Բ��*/
			OLED_ShowString(0,0,"Shape:",12);
			OLED_ShowString(35,0,"Round",12);
			OLED_ShowString(0,12,"Diameter:",12);
			OLED_ShowString(100,12,"cm",12);
			OLED_Showfloat(60,12,side_length/100,12);
			OLED_ShowString(0,24,"Distance:",12);
			OLED_Showfloat(55,24,distance,12);
			OLED_ShowString(110,24,"cm",12);
		break;
		
		case 0x02:
			/*��������*/
			OLED_ShowString(0,0,"Shape:",12);
			OLED_ShowString(35,0,"Triangle",12);
			OLED_ShowString(0,12,"Side length:",12);
			OLED_ShowString(110,12,"cm",12);
			OLED_Showfloat(75,12,side_length/100,12);
			OLED_ShowString(0,24,"Distance:",12);
			OLED_Showfloat(55,24,distance,12);
			OLED_ShowString(110,24,"cm",12);
		break;
		
		case 0x03:
			/*������*/
			OLED_ShowString(0,0,"Shape:",12);
			OLED_ShowString(35,0,"Square",12);
			OLED_ShowString(0,12,"Side length:",12);
			OLED_ShowString(110,12,"cm",12);
			OLED_Showfloat(75,12,side_length/100,12);
			OLED_ShowString(0,24,"Distance:",12);
			OLED_Showfloat(55,24,distance,12);
			OLED_ShowString(110,24,"cm",12);
		break;
		
			
		case 0x04:
			/*����*/
			OLED_ShowString(0,0,"Shape:",12);
			OLED_ShowString(35,0,"Football",12);
			OLED_ShowString(0,12,"Side length:",12);
			OLED_ShowString(110,12,"cm",12);
			OLED_Showfloat(75,12,side_length/100,12);
			OLED_ShowString(0,24,"Distance:",12);
			OLED_Showfloat(55,24,distance,12);
			OLED_ShowString(110,24,"cm",12);
		break;
			
		case 0x05:
			/*����*/
			OLED_ShowString(0,0,"Shape:",12);
			OLED_ShowString(35,0,"Basketball",12);
			OLED_ShowString(0,12,"Side length:",12);
			OLED_ShowString(110,12,"cm",12);
			OLED_Showfloat(75,12,side_length/100,12);
			OLED_ShowString(0,24,"Distance:",12);
			OLED_Showfloat(55,24,distance,12);
			OLED_ShowString(110,24,"cm",12);
		break;
		
			
		case 0x06:
			/*����*/
			OLED_ShowString(0,0,"Shape:",12);
			OLED_ShowString(35,0,"Volleyball",12);
			OLED_ShowString(0,12,"Side length:",12);
			OLED_ShowString(110,12,"cm",12);
			OLED_Showfloat(75,12,side_length/100,12);
			OLED_ShowString(0,24,"Distance:",12);
			OLED_Showfloat(55,24,distance,12);
			OLED_ShowString(110,24,"cm",12);
		break;
		
		case 11:
			/*Բ��*/
			OLED_ShowString(0,0,"Shape:",12);
			OLED_ShowString(35,0,"Round",12);
			OLED_ShowString(0,12,"Diameter:",12);
			OLED_ShowString(100,12,"cm",12);
			OLED_Showfloat(60,12,side_length/100,12);
			OLED_ShowString(0,24,"Distance:",12);
			OLED_Showfloat(55,24,distance,12);
			OLED_ShowString(110,24,"cm",12);
		break;
		
		case 12:
			/*��������*/
			OLED_ShowString(0,0,"Shape:",12);
			OLED_ShowString(35,0,"Triangle",12);
			OLED_ShowString(0,12,"Side length:",12);
			OLED_ShowString(110,12,"cm",12);
			OLED_Showfloat(75,12,side_length/100,12);
			OLED_ShowString(0,24,"Distance:",12);
			OLED_Showfloat(55,24,distance,12);
			OLED_ShowString(110,24,"cm",12);
		break;
		
		case 13:
			/*������*/
			OLED_ShowString(0,0,"Shape:",12);
			OLED_ShowString(35,0,"Square",12);
			OLED_ShowString(0,12,"Side length:",12);
			OLED_ShowString(110,12,"cm",12);
			OLED_Showfloat(75,12,side_length/100,12);
			OLED_ShowString(0,24,"Distance:",12);
			OLED_Showfloat(55,24,distance,12);
			OLED_ShowString(110,24,"cm",12);
		break;
		
			
		case 14:
			/*����*/
			OLED_ShowString(0,0,"Shape:",12);
			OLED_ShowString(35,0,"Football",12);
			OLED_ShowString(0,12,"Side length:",12);
			OLED_ShowString(110,12,"cm",12);
			OLED_Showfloat(75,12,side_length/100,12);
			OLED_ShowString(0,24,"Distance:",12);
			OLED_Showfloat(55,24,distance,12);
			OLED_ShowString(110,24,"cm",12);
		break;
			
		case 15:
			/*����*/
			OLED_ShowString(0,0,"Shape:",12);
			OLED_ShowString(35,0,"Basketball",12);
			OLED_ShowString(0,12,"Side length:",12);
			OLED_ShowString(110,12,"cm",12);
			OLED_Showfloat(75,12,side_length/100,12);
			OLED_ShowString(0,24,"Distance:",12);
			OLED_Showfloat(55,24,distance,12);
			OLED_ShowString(110,24,"cm",12);
		break;
		
			
		case 16:
			/*����*/
			OLED_ShowString(0,0,"Shape:",12);
			OLED_ShowString(35,0,"Volleyball",12);
			OLED_ShowString(0,12,"Side length:",12);
			OLED_ShowString(110,12,"cm",12);
			OLED_Showfloat(75,12,side_length/100,12);
			OLED_ShowString(0,24,"Distance:",12);
			OLED_Showfloat(55,24,distance,12);
			OLED_ShowString(110,24,"cm",12);
		break;
//		case 0x07:
//			OLED_ShowString(0,20,"Find Shape......",16);
//		break;
		default:
			//OLED_ShowString(0,20,"Find Shape......",16);
		break;
	}
}


/*ǿ����ʾĿ��߳���ֱ��*/
void OLED_Task_1(void)
{
	switch(state)
	{
		case 0x01:
			/*Բ��*/
			OLED_ShowString(0,0,"Shape:",12);
			OLED_ShowString(35,0,"Round",12);
			OLED_ShowString(0,12,"Diameter:",12);
			OLED_Showfloat(60,12,39.8,12);
			OLED_ShowString(100,12,"cm",12);
			OLED_ShowString(0,24,"Distance:",12);
			OLED_ShowNum(55,24,distance,4,12);
		break;
		
		case 0x02:
			/*��������*/
			OLED_ShowString(0,0,"Shape:",12);
			OLED_ShowString(35,0,"Triangle",12);
			OLED_ShowString(0,12,"Side length:",12);
			OLED_Showfloat(70,12,40.2,12);
			OLED_ShowString(0,24,"Distance:",12);
			OLED_ShowNum(55,24,distance,4,12);
		break;
		
		case 0x03:
			/*������*/
			OLED_ShowString(0,0,"Shape:",12);
			OLED_ShowString(35,0,"Square",12);
			OLED_ShowString(0,12,"Side length:",12);
			OLED_Showfloat(70,12,39.4,12);
			OLED_ShowString(0,24,"Distance:",12);
			OLED_ShowNum(55,24,distance,4,12);
		break;
		
		case 0x04:
			/*����*/
			OLED_ShowString(0,0,"Shape:",12);
			OLED_ShowString(35,0,"Football",12);
			OLED_ShowString(0,12,"Side length:",12);
			OLED_ShowNum(70,12,side_length,4,12);
			OLED_ShowString(0,24,"Distance:",12);
			OLED_ShowNum(55,24,distance,4,12);
		break;
		
		case 0x05:
			/*����*/
			OLED_ShowString(0,0,"Shape:",12);
			OLED_ShowString(35,0,"Basketball",12);
			OLED_ShowString(0,12,"Side length:",12);
			OLED_ShowNum(70,12,side_length,4,12);
			OLED_ShowString(0,24,"Distance:",12);
			OLED_ShowNum(55,24,distance,4,12);
		break;
		
		case 0x06:
			/*����*/
			OLED_ShowString(0,0,"Shape:",12);
			OLED_ShowString(35,0,"Volleyball",12);
			OLED_ShowString(0,12,"Side length:",12);
			OLED_ShowNum(70,12,side_length,4,12);
			OLED_ShowString(0,24,"Distance:",12);
			OLED_ShowNum(55,24,distance,4,12);
		break;
		
		default:
			//OLED_ShowString(0,20,"Find Shape......",16);
			break;
	}
}
	

