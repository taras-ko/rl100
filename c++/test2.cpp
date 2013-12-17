#include <stdio.h>
#include "Timer.h"
#include "Led.h"
#include "Switch.h"

Led red_led(LED1, OFF);
Led green_led(LED2, OFF);
Led *pled;
Switch button(S2);

unsigned short taccr0 = 0xffff;
//Tactl tactl(SMCLK | BY8 | UPMODE);
Timer timer(SMCLK | BY8 | UPMODE, taccr0);

volatile int count = 0;

__attribute__((interrupt(TIMER0_A1_VECTOR)))
void timer_isr(void)
{
	count++;
	pled = (count % 2 == 0) ? &green_led : &red_led;
	pled->toggle();
	timer.taifg.clear_flag();
}


main()
{
	/*
	Tactl tactl;
	tactl.TASSELx = SMCLK;
	tactl.IDx = BY8;
	tactl.MCx = UPMODE;
	*/

	while (1) {
		while (!button.is_pressed())
			;
		timer.enable_interrupt();

		while (count < 10)
			;
		count = 0;
		
		timer.disable_interrupt();

		while (!button.is_pressed())
			;
		green_led.off();
		red_led.off();

		while(button.is_pressed())
			;
	}

}
