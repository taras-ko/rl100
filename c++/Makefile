CC := msp430-g++ -O3
CPPFLAGS = -mmcu=msp430g2553 -mdisable-watchdog -nodefaultlibs -std=c++0x

%:
	$(CC) -o a.out $@.cpp Timer.cpp Led.cpp Switch.cpp Peripheral.cpp $(CPPFLAGS)

flash :
	@mspdebug rf2500 'prog a.out'
