#include "Peripheral.h"
enum States { ON, OFF };
class Led : public Peripheral {
public:
	Led(Periph unit, States state);
	void on();
	void off();
	void toggle();
};
