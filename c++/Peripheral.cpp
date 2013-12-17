#include "Peripheral.h"
Peripheral::Peripheral(Periph unit)
{
	switch (unit) {
		case LED1:
			pin_addr = BIT0;
			break;
		case LED2:
			pin_addr = BIT6;
			break;
		case S2:
			pin_addr = BIT3;
			break;
		default:
//			extern void error();
			pin_addr = 0x0;
//			error();
			break;
	}
}
