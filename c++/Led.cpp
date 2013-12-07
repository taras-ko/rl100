#include <msp430.h>
#include "Led.h"
Led::Led(Periph unit, States state) : Peripheral(unit)
{
	P1DIR |= pin_addr;
	switch (state) {
		case ON:
			this->on();
			break;
		default:
			break;
	}
}

void Led::on()
{
	P1OUT |= pin_addr;
}

void Led::off()
{
	P1OUT &= ~pin_addr;
}

void Led::toggle()
{
	P1OUT ^= pin_addr;
}
