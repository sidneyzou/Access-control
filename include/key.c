#include "key.h"

#define GPIO_KEY P2
/*********************************ȫ�ֱ��ʼ��***********************************/  
u8 KeyValue = 255;

/******************************************************************************/
/* ��������  : KEY_Delay                                                      */
/* ��������  : KEY��ʱ                                                        */
/* �������  : Void                                                           */
/* ��������  : ��                                                             */
/* ����ֵ    : ��                                                             */
/******************************************************************************/
void key_delay_ms(u16 xms)
{
	u8 i;
	for( ; xms > 0; xms--)
		for(i = 110; i > 0; i--);
}

/******************************************************************************/
/* ��������  : KEY_Scan                                                       */
/* ��������  : KEYɨ��                                                        */
/* �������  : Void                                                           */
/* ��������  : ��                                                             */
/* ����ֵ    : ��                                                             */
/******************************************************************************/	
void ReadKey(void)
{
	char a=0;
	GPIO_KEY=0x0f;
	if(GPIO_KEY!=0x0f)//��ȡ�����Ƿ���
	{
		key_delay_ms(5);//��ʱ10ms��������
		if(GPIO_KEY!=0x0f)//�ٴμ������Ƿ���
		{
			
			//������
			GPIO_KEY=0X0F;
			switch(GPIO_KEY)
			{
				case(0X07):	KeyValue=1;break;
				case(0X0b):	KeyValue=4;break;
				case(0X0d): KeyValue=7;break;
				case(0X0e):	KeyValue=10;break;
			}
			//������
			GPIO_KEY=0XF0;
			switch(GPIO_KEY)
			{
				case(0X70):	KeyValue=KeyValue+13;break;
				case(0Xb0):	KeyValue=KeyValue+2 ;break;
				case(0Xd0): KeyValue=KeyValue+1 ;break;
				case(0Xe0):	KeyValue=KeyValue+0 ;break;
			}
			if(KeyValue == 11) KeyValue = 0;
			while((a<50)&&(GPIO_KEY!=0xf0))	 //��ⰴ�����ּ��
			{
				key_delay_ms(500);
				a++;
			}
		}
	}
}

