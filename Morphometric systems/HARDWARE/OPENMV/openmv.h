#ifndef _OPENMV_H
#define _OPENMV_H
#include "sys.h"


#define QQQVGA  80
#define QQVGA   160
#define QVGA    320
#define VGA     640

void Data_Processing(u8 *data_buf,u8 num) ;
void Receive_Prepare(u8 data);




/*****************************************************/
//定义三个全局变量用于保存偏移尺寸、偏移角度以及线长
//theta_org:偏移角度     角度偏移
//期望值：平行Y轴的位置（0）

//rgo_ort:偏移尺寸       左右偏移距离
//期望值：视野中央（宽度的一半，根据不同的像素尺寸而变）

//line_date:线长
/*****************************************************/
extern double side_length;
extern double distance;
extern int state;

#endif
