#include "openmv.h"

/****************openmv数据解析******************/
/*数据格式：0XAA,0XAE,标志位，角度，距离，0x0D,0X0A
	有效数据：标志位state：用于判断小车的功能
						边长:物体实际边长
						距离：摄像头和目标物体的距离
*/
double side_length;
double distance;
int state;
void Data_Processing(u8 *data_buf,u8 num)   
{
	/*标志位*/
	state = (int)(*(data_buf+1)<<0) | (int)(*(data_buf+2)<<8) | (int)(*(data_buf+3)<<16) | (int)(*(data_buf+4)<<24) ;
	
	/*读取边长原始数据*/
  side_length = (int)(*(data_buf+5)<<0) | (int)(*(data_buf+6)<<8) | (int)(*(data_buf+7)<<16) | (int)(*(data_buf+8)<<24) ; 
	
	/*读取距离*/
	distance = (int)(*(data_buf+9)<<0) | (int)(*(data_buf+10)<<8) | (int)(*(data_buf+11)<<16) | (int)(*(data_buf+12)<<24) ;
}


/*************************************/
//用于对openmv发送过来的数据进行解析
//通过对两个帧头的判断进而判断数据的有效性
/*只有检测到0XAA,0XAE才会认为是有效数据，并对数据进行还原*/
/*************************************/
void Receive_Prepare(u8 data)    
{
	/*静态局部变量：接收缓存*/
	static u8 RxBuffer[10];
	
	/*数据长度：数组下标*/
  static u8 _data_cnt = 0;
	
	/*接受状态*/
  static u8 state = 0;
	
	/*帧头判断*/
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

