#include <msp430.h>
#define LED1 BIT0
#define LED2 BIT6

#define TOGGLE_LED1 (P1OUT ^= LED1)
#define TOGGLE_LED2 (P1OUT ^= LED2)

#define SMCLK BIT9 // Sub Main Clock

/* IDx Input Divider */
#define NONE 0
#define BY2 BIT6
#define BY4 BIT7
#define BY8 BIT7 | BIT6

/* MCx Mode Control */
#define HALT 0
#define CONTM BIT5
#define UPMODE BIT4

/* TACTL INIT */
#define TASSELx CONTM
#define IDx BY8
#define MCx SMCLK

#define INIT_TA TACTL = TASSELx | IDx | MCx
#define CLEAR_TAIFG (TACTL &= ~BIT0)
#define _TAIFG (TACTL & BIT0)

main()
{
    P1DIR = BIT0 | BIT6;
    P1OUT = 0;
	TACCR0 = 0xffff;
	INIT_TA;
    while (1) {
		while (_TAIFG == 0)
			;
		CLEAR_TAIFG;
		TOGGLE_LED1;
		TOGGLE_LED2;
    }
}
