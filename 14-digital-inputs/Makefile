CC := msp430-gcc -O3
CFLAGS := -mmcu=msp430g2553 -mdisable-watchdog

%:
	$(CC) -o a.out $@.c led.c $(CFLAGS)
#$(CC) -o a.out $@.c $(CFLAGS) && mspdebug rf2500 'prog a.out'

flash :
	@mspdebug rf2500 'prog a.out'
