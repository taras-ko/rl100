#ifndef __switch_h_
#define __switch_h_
#define S2 0x8
#define is_pressed(sw) (!((sw) & P1IN))
#define init_switch(sw) \
{ \
	P1REN |= (sw); \
	P1OUT |= (sw); \
}
#endif /* __switch_h_ */
