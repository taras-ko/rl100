#include <msp430.h>
#include <intrinsics.h>

#include "led.h"
#include "switch.h"

__attribute__((interrupt(TIMER0_A1_VECTOR)))
void timer_isr(void)
{
	toggle_led(LED1);
	toggle_led(LED2);
	TACTL &= ~TAIFG;
}

void main(void)
{
	P1OUT = 0;
	init_led(LED1, OFF);
	init_led(LED2, ON);
	init_switch(S2);

	TACTL = TASSEL_2 | MC_2 | ID_3 | TAIE;
	int i = 0;
	for (i = 0; ;i++) { // Button press/release cycle
		while (!is_pressed(S2))
			;
		if (i % 2 == 0) // every cycle disable/enable isr
			__enable_interrupt();
		else
			__disable_interrupt();
		while (is_pressed(S2))
			;
	}
}
