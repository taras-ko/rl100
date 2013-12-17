#include <msp430.h>
#include <intrinsics.h>

#include "switch.h"
#include "led.h"

volatile int count = 0;
LedDev green_led, red_led, *pled;
LedDrv led;

__attribute__((interrupt(TIMER0_A1_VECTOR)))
void timer_isr(void)
{
	count++;
	pled = (count % 2 == 0) ? &green_led : &red_led;
	led.toggle(pled);
	TACTL &= ~TAIFG;
}

void main(void)
{
	P1OUT = 0;
	led_drv_init(&led);
	led_dev_init(&red_led, LED1, OFF);
	led_dev_init(&green_led, LED2, ON);

	init_switch(S2);

	TACTL = TASSEL_2 | MC_2 | ID_3 | TAIE;
	while (1) {
		while (!is_pressed(S2))
			;
		__enable_interrupt();
		while (count < 10)
			;
		count = 0;
		__disable_interrupt();
		led.on(&green_led);
		while(!is_pressed(S2));
			;

		led.off(&green_led);
		led.off(&red_led);
		while(is_pressed(S2))
			;
	}
}
