#include <msp430.h>
#include <intrinsics.h>
#include <stdlib.h>

/* enable pull-up resistor for switch s */
#define enapupr(port, s) (port##REN = (s))
#define S2 0x8
#define LED1 0x0
#define sw_is_pressed(sw) ((sw) & P1IN)
#define toggle_led(l) { \
}

typedef struct {
	char *port;
	unsigned char val;
} Hunit; /* hardware unit */

main()
{
	enapupr("P1", S2);

	while (!sw_is_pressed(S2))
		;

	P1DIR |= LED1; /* configure for output */
	P1OUT |= LED1; /* led1 to high */
}
