#ifndef __led_h_

#define __led_h_

#include <msp430.h>

typedef enum { OFF, ON } LedState;
#define LED1 BIT0
#define LED2 BIT6
#define toggle_led(led) (P1OUT ^= (led))
typedef struct {
	unsigned short pin;
	LedState state;
} LedDev;

typedef struct {
	void (*on)(LedDev *);
	void (*off)(LedDev *);
	void (*toggle)(LedDev *);
} LedDrv;

void led_drv_init(LedDrv *pdrv);
void led_dev_init(LedDev *pdev, unsigned short pin, LedState state);

#endif /* __led_h_ */
