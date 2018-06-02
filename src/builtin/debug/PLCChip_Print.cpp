#include <iostream>

#include "builtin/debug/PLCChip_Print.hpp"

using namespace std;


PLCChip_Print::PLCChip_Print() : PLCChip(0, 0) {  }
void PLCChip_Print::onChange(__attribute__((unused)) uint_fast8_t index, PLCValueEvent &event) {
    this->onChange(event); }
void PLCChip_Print::onChange(PLCValueEvent &event)
{
	cout << "value: " << event.getUInt() << endl;
}
void PLCChip_Print::apply() {  }