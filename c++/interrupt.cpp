#include <stdio.h>
#include <intrinsics.h>
#include "Timer.h"
#include "Led.h"
#include "Switch.h"

Led red_led(LED1, OFF);
Led green_led(LED2, OFF);
Led *pled;
Switch btn(S2);

Tactl tactl;
Timer t;
volatile int count = 0;

__attribute__((interrupt(TIMER0_A1_VECTOR)))
void timer_isr()
{
	count++;
	pled = (count % 2 == 0) ? &green_led : &red_led;
//	P1OUT ^= BIT0;
//	TACTL &= ~TAIFG;
	pled->toggle();
	t.taifg.clear_flag();
}

main()
{
	tactl.TASSELx = SMCLK;
	tactl.IDx = BY8;
	tactl.MCx = UPMODE;
	unsigned short taccr0 = 0xffff;

	t.init(tactl.val(), taccr0);

	while (1) {
		while (!btn.is_pressed())
			;

		__enable_interrupt();

		while (count < 10)
			;
		count = 0;
		__disable_interrupt();

		while (!btn.is_pressed())
			;
		green_led.off();
		red_led.off();
		while (btn.is_pressed())
			;
	}
}
