#include <msp430.h>
#define LED1 BIT0
#define LED2 BIT6
#define TOGGLE(LED) (P1OUT ^= (LED))

void delay()
{
    unsigned int i = 0;
    while (++i < 60000);
}

main()
{
    P1DIR |= LED1 | LED2;
	TOGGLE(LED1);
    while (1) {
        TOGGLE(LED1);
        TOGGLE(LED2);
        delay();
    }
}
