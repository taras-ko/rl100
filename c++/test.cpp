#include <msp430.h>

#include "Led.h"
#include "Switch.h"

void delay()
{
    unsigned int i = 0;
    while (++i < 60000);
}

void error()
{
	Led red_led(LED1, OFF);
	while (1) {
		red_led.toggle();
		delay();
	}
}

int main()
{
	Led red_led(LED1, ON);
	Led green_led(LED2, OFF);
	Switch button(S2);

	while (1) {
		while (!button.is_pressed())
			;

		red_led.toggle();
		green_led.toggle();

		while (button.is_pressed())
			;
	}
}
