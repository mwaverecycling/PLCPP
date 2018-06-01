#include <iostream>
#include <math.h>

#include "PLCValueEvent.hpp"
#include "builtin/PLCChip_Add2UInt.hpp"
#include "builtin/debug/PLCChip_Print.hpp"

int main()
{
	PLCChip_Add2UInt adder;
	PLCChip_Print printer;
	PLCValueEvent a_event = PLCValueEvent::FromUInt(9);
	PLCValueEvent b_event = PLCValueEvent::FromUInt(3);

	adder.setListener(0, &printer);
	adder.valueChanged(0, a_event);
	adder.valueChanged(1, b_event);
	b_event = PLCValueEvent::FromUInt(5);
	adder.valueChanged(1, b_event);
}