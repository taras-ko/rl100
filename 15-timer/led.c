#include "led.h"

static void on(LedDev *pdev)
{
	P1OUT |= pdev->pin;
	pdev->state = ON;
}

static void off(LedDev *pdev)
{
	P1OUT &= ~pdev->pin;
	pdev->state = OFF;
}

static void toggle(LedDev *pdev)
{
	P1OUT ^= pdev->pin;
	pdev->state = (pdev->state == ON) ? OFF : ON;
}


void led_drv_init(LedDrv *pdrv)
{
	pdrv->on = on;
	pdrv->off = off;
	pdrv->toggle = toggle;
}

void led_dev_init(LedDev *pdev, unsigned short pin, LedState state)
{
	P1DIR |= pin;
	pdev->pin = pin;
	pdev->state = state;
}
