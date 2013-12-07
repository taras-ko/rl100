#include "Switch.h"
Switch::Switch(Periph unit) : Peripheral(unit)
{
	P1OUT |= pin_addr; // Hight level on pin
	P1REN |= pin_addr; // Enable pull-up resistor
	P1DIR &= ~pin_addr; // Configure for input direction
}

bool Switch::is_pressed()
{
	return !(P1IN & pin_addr); // High level on pin while button isn't pressed
}
