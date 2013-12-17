#include <msp430.h>
#include <intrinsics.h>
#pragma once

class Interrupt {
public:
	static void enable_interrupt() // Globally enables interrupt for msp430
	{
		__enable_interrupt();
	}
	static void disable_interrupt()
	{
		__disable_interrupt();
	}
};
