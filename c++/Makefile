CC := msp430-g++
CPPFLAGS = -mmcu=msp430g2553 -mdisable-watchdog -nodefaultlibs -std=c++0x

%:
	$(CC) -o a.out $@.cpp Led.cpp Switch.cpp Peripheral.cpp $(CPPFLAGS)

flash :
	@mspdebug rf2500 'prog a.out'
