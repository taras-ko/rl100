#include <msp430.h>
#include <intrinsics.h>

// TASSELx Source select
typedef enum {
	SMCLK = BIT9 // Sub Main Clock
} SourceSelect;

/* IDx Input Divider */
typedef enum {
	NONE,
	BY2 = BIT6,
	BY4 = BIT7,
	BY8 = BIT7 | BIT6
} InputDivider;

/* MCx Mode Control */
typedef enum {
	HALT,
	CONTM = BIT5,
	UPMODE = BIT4
} ModeControl;

class Taifg {
public:
	unsigned short val();
	void clear_flag();
};

class Tactl {
	unsigned short reg;
public:
	Tactl(unsigned short _reg);
	SourceSelect TASSELx;
	InputDivider IDx;
	ModeControl MCx;
	unsigned short val();
};

class Timer {
public:
	Timer(unsigned short tactl, unsigned short taccr0);
	void enable_interrupt();
	void disable_interrupt();
	unsigned short taccr0;
	Taifg taifg;
};

