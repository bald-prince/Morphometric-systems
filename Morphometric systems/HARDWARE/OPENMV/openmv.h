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
//��������ȫ�ֱ������ڱ���ƫ�Ƴߴ硢ƫ�ƽǶ��Լ��߳�
//theta_org:ƫ�ƽǶ�     �Ƕ�ƫ��
//����ֵ��ƽ��Y���λ�ã�0��

//rgo_ort:ƫ�Ƴߴ�       ����ƫ�ƾ���
//����ֵ����Ұ���루��ȵ�һ�룬���ݲ�ͬ�����سߴ���䣩

//line_date:�߳�
/*****************************************************/
extern double side_length;
extern double distance;
extern int state;

#endif
