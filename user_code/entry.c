#include "head.h"

extern u8 KeyValue;


static u16 _u8_limit(u16 now,u16 min, u16 max)
{
	if (now < min) now = min;
	if (now > max) now = max;
		
	return now;
}

/********************************************************** 
*函数名：
*功能： 程序运行
*返回值：
备 注： 
**********************************************************/
void entry(void)
{

	
	while(1){
		ReadKey();

	}
}