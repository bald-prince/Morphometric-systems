#include "openmv.h"

/****************openmv���ݽ���******************/
/*���ݸ�ʽ��0XAA,0XAE,��־λ���Ƕȣ����룬0x0D,0X0A
	��Ч���ݣ���־λstate�������ж�С���Ĺ���
						�߳�:����ʵ�ʱ߳�
						���룺����ͷ��Ŀ������ľ���
*/
double side_length;
double distance;
int state;
void Data_Processing(u8 *data_buf,u8 num)   
{
	/*��־λ*/
	state = (int)(*(data_buf+1)<<0) | (int)(*(data_buf+2)<<8) | (int)(*(data_buf+3)<<16) | (int)(*(data_buf+4)<<24) ;
	
	/*��ȡ�߳�ԭʼ����*/
  side_length = (int)(*(data_buf+5)<<0) | (int)(*(data_buf+6)<<8) | (int)(*(data_buf+7)<<16) | (int)(*(data_buf+8)<<24) ; 
	
	/*��ȡ����*/
	distance = (int)(*(data_buf+9)<<0) | (int)(*(data_buf+10)<<8) | (int)(*(data_buf+11)<<16) | (int)(*(data_buf+12)<<24) ;
}


/*************************************/
//���ڶ�openmv���͹��������ݽ��н���
//ͨ��������֡ͷ���жϽ����ж����ݵ���Ч��
/*ֻ�м�⵽0XAA,0XAE�Ż���Ϊ����Ч���ݣ��������ݽ��л�ԭ*/
/*************************************/
void Receive_Prepare(u8 data)    
{
	/*��̬�ֲ����������ջ���*/
	static u8 RxBuffer[10];
	
	/*���ݳ��ȣ������±�*/
  static u8 _data_cnt = 0;
	
	/*����״̬*/
  static u8 state = 0;
	
	/*֡ͷ�ж�*/
  if(state == 0 && data == 0xAA)
  {
		state = 1;
  } 
  else if(state==1 && data == 0xAE)
	{
		state = 2;
    _data_cnt = 0; 
  }
  else if(state == 2)  
  {
    RxBuffer[++_data_cnt] = data;
    if(_data_cnt >= 12)
    { 
			state = 0;
      Data_Processing(RxBuffer,_data_cnt);
		}
  } 
  else
		state = 0;   
}

