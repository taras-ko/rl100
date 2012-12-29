#include <msp430.h>
#include <intrinsics.h>
#include <stdlib.h>

main()
{
	P1REN = 0x8;
	P1OUT = 0x8;
	
	while (P1IN & 0x8) {
		;
	}
	
	P1DIR = 1;
	P1OUT = 1;
}
