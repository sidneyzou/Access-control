#include "key.h"

#define GPIO_KEY P2
/*********************************全局变初始化***********************************/  
u8 KeyValue = 255;

/******************************************************************************/
/* 函数名称  : KEY_Delay                                                      */
/* 函数描述  : KEY延时                                                        */
/* 输入参数  : Void                                                           */
/* 参数描述  : 无                                                             */
/* 返回值    : 无                                                             */
/******************************************************************************/
void key_delay_ms(u16 xms)
{
	u8 i;
	for( ; xms > 0; xms--)
		for(i = 110; i > 0; i--);
}

/******************************************************************************/
/* 函数名称  : KEY_Scan                                                       */
/* 函数描述  : KEY扫描                                                        */
/* 输入参数  : Void                                                           */
/* 参数描述  : 无                                                             */
/* 返回值    : 无                                                             */
/******************************************************************************/	
void ReadKey(void)
{
	char a=0;
	GPIO_KEY=0x0f;
	if(GPIO_KEY!=0x0f)//读取按键是否按下
	{
		key_delay_ms(5);//延时10ms进行消抖
		if(GPIO_KEY!=0x0f)//再次检测键盘是否按下
		{
			
			//测试列
			GPIO_KEY=0X0F;
			switch(GPIO_KEY)
			{
				case(0X07):	KeyValue=1;break;
				case(0X0b):	KeyValue=4;break;
				case(0X0d): KeyValue=7;break;
				case(0X0e):	KeyValue=10;break;
			}
			//测试行
			GPIO_KEY=0XF0;
			switch(GPIO_KEY)
			{
				case(0X70):	KeyValue=KeyValue+13;break;
				case(0Xb0):	KeyValue=KeyValue+2 ;break;
				case(0Xd0): KeyValue=KeyValue+1 ;break;
				case(0Xe0):	KeyValue=KeyValue+0 ;break;
			}
			if(KeyValue == 11) KeyValue = 0;
			while((a<50)&&(GPIO_KEY!=0xf0))	 //检测按键松手检测
			{
				key_delay_ms(500);
				a++;
			}
		}
	}
}

