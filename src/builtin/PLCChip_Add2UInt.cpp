#include "builtin/PLCChip_Add2UInt.hpp"



using namespace std;


PLCChip_Add2UInt::PLCChip_Add2UInt() {  }

PLCChip_Add2UInt::~PLCChip_Add2UInt() {  }

void PLCChip_Add2UInt::valueChanged(string name, struct PLCValueEvent event)
{
	if(name == "a") { this->c_input.a = &event; }
	else if(name == "b") { this->c_input.b = &event; }

	if(this->c_input.a != NULL && this->c_input.b != NULL) { this->apply(); }
}
void PLCChip_Add2UInt::apply()
{
	union PLCValue value = { this->c_input.a->value.v_uint + this->c_input.a->value.v_uint };
	struct PLCTime timestamp = this->c_input.a->time | this->c_input.b->time;
	struct PLCValueEvent event = { timestamp, value };
	this->changeValue("c", event);
}