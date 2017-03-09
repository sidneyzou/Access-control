#include "head.h"

void main() {
	
	u16 count = 0;
    /* 定时器初始化 */
//     TimerInit();
    
    /* 串口初始化 */
	Uart1Init();
		
	/* EEPROM初始化 */
	IapInit();	
	
	/* ADC初始化 */
	InitADC();
	
	/* 打开总中断 */
//     EA = 1;

    while(1){
        entry();
    }
}

