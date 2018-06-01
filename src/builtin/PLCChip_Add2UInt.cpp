#include "builtin/PLCChip_Add2UInt.hpp"

using namespace std;

PLCChip_Add2UInt::PLCChip_Add2UInt() : PLCChip(2, 1) {  }
void PLCChip_Add2UInt::apply()
{
	this->outputs[0] = PLCValueEvent::FromUInt(
		this->inputs[0].getUInt() + this->inputs[1].getUInt(),
		PLCValueEvent::earliest(this->inputs[0], this->inputs[1]));
}