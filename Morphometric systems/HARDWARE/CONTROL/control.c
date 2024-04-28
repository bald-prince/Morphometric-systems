#include "control.h"


void Find_Shape(void)
{
	static int delay_cnt = 0;
	
	OLED_Task();
	
	switch(state)
	{
		case 0x01:
			if(delay_cnt<500)
				BEEP_LED = 1;
			else
			{
				BEEP_LED = 0;
				state = 11;
			}
			delay_cnt++;
		break;
		
		case 0x02:
			if(delay_cnt<500)
				BEEP_LED = 1;
			else
			{
				BEEP_LED = 0;
				state = 12;
			}
			delay_cnt++;
		break;
		
			
		case 0x03:
			if(delay_cnt<500)
				BEEP_LED = 1;
			else
			{
				BEEP_LED = 0;
				state = 13;
			}
			delay_cnt++;
		break;
		
			
		case 0x04:
			if(delay_cnt<500)
				BEEP_LED = 1;
			else
			{
				BEEP_LED = 0;
				state = 14;
			}
			delay_cnt++;
		break;
		
		case 0x05:
			if(delay_cnt<500)
				BEEP_LED = 1;
			else
			{
				BEEP_LED = 0;
				state = 15;
			}
			delay_cnt++;
		break;
		
		case 0x06:
			if(delay_cnt<500)
				BEEP_LED = 1;
			else
			{
				BEEP_LED = 0;
				state = 16;
			}
			delay_cnt++;
		break;

		default:
			BEEP_LED = 0;
			delay_cnt = 0;
			break;
	}
}


