#include <msp430.h>
#include <stdlib.h>

#define LED1 BIT0
#define LED2 BIT6
#define TOGGLE(LED) (P1OUT ^= (LED))

main()
{
	TOGGLE(LED1);

	for (;;) {
		while (P1IN & 0x8)
			;

		TOGGLE(LED1);
		TOGGLE(LED2);

		while (!(P1IN & 0x8))
			;
	}
}
