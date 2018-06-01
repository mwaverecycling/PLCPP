#include <iostream>

#include "builtin/debug/PLCChip_Print.hpp"

using namespace std;


PLCChip_Print::PLCChip_Print() : PLCChip(0, 0) {  }
void PLCChip_Print::valueChanged(__attribute__((unused)) int_fast8_t index, PLCValueEvent & event) { this->valueChanged(event); }
void PLCChip_Print::valueChanged(PLCValueEvent & event)
{
	cout << "value: " << event.getUInt() << endl;
}
void PLCChip_Print::apply() {  }