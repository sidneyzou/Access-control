#include "head.h"

void main() {
	
	u16 count = 0;
    /* ��ʱ����ʼ�� */
//     TimerInit();
    
    /* ���ڳ�ʼ�� */
	Uart1Init();
		
	/* EEPROM��ʼ�� */
	IapInit();	
	
	/* ADC��ʼ�� */
	InitADC();
	
	/* �����ж� */
//     EA = 1;

    while(1){
        entry();
    }
}

