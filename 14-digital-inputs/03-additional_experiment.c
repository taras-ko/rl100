#include <msp430.h>
#include <intrinsics.h>
#include <stdlib.h>

main()
{
	P1REN = 0x8;
	P1OUT = 0x8;
	P1DIR = 0x41;

	/* red led is on 0x9 */
	/* green led is on 0x48 */
	P1OUT = 0x9; /* initial default state */

	for (;;) {
		while ((P1IN >> 3) & 1)
			;
		while (!((P1IN >> 3) & 1))
			;
		P1OUT <<= 3;

		while ((P1IN >> 3) & 1)
			;
		while (!((P1IN >> 3) & 1))
			;
		P1OUT >>= 3;
	}
}
