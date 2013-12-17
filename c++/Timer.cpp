#include "Timer.h"

unsigned short Taifg::val()
{
	return TACTL & BIT0;
}

void Taifg::clear_flag()
{
	TACTL &= ~BIT0;
}

Tactl::Tactl(unsigned short _reg)
	: reg(_reg)
{
}

unsigned short Tactl::val()
{
	return TASSELx | IDx | MCx;
}

Timer::Timer(unsigned short tactl, unsigned short taccr0)
{
	TACCR0 = taccr0; 
	TACTL = tactl;
}

void Timer::enable_interrupt()
{
	TACTL |= TAIE;
	__enable_interrupt();
}

void Timer::disable_interrupt()
{
	TACTL &= ~TAIE;
	__disable_interrupt();
}
