#include <msp430.h>
#pragma once
enum Periph { LED1, LED2, S1, S2 };

class Peripheral {
protected:
	unsigned short pin_addr;
public:
	Peripheral(Periph unit);
};
