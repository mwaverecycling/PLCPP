#include <iostream>

#include "builtin/debug/PLCChip_Print.hpp"
#include "PLCValues.hpp"

using namespace std;


PLCChip_Print::PLCChip_Print() {  }

PLCChip_Print::~PLCChip_Print() {  }

void PLCChip_Print::valueChanged(string name, struct PLCValueEvent event)
{
	cout << name << " = " << event.value.v_uint;
	//printf("%s = %llu\n", name, event.value.v_uint);
}
void PLCChip_Print::apply() {  }