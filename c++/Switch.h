#include "Peripheral.h"
class Switch : public Peripheral {
public:
	Switch(Periph unit);
	bool is_pressed();
};
