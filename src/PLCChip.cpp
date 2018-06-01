#include <vector>

#include "PLCChip.hpp"

using namespace std;


PLCChip::PLCChip(uint_fast8_t inputs, uint_fast8_t outputs) {
	this->inputs.resize(inputs);
	this->outputs.resize(outputs);
	this->listeners.resize(outputs);
}

void PLCChip::setListener(int_fast8_t index, PLCValueListener* listener)
{
	if(index >= 0) {
    	this->listeners.at(uint_fast8_t(index)) = listener;
	}
}
void PLCChip::changeValue(int_fast8_t index, PLCValueEvent & event)
{
	if(index >= 0) {
    	this->listeners[uint_fast8_t(index)]->valueChanged(index, event);
	}
}
bool PLCChip::isValid() const
{
	vector<PLCValueEvent>::const_iterator vec_itr;
	for(vec_itr = this->inputs.begin(); vec_itr != this->inputs.end(); vec_itr++) {
	    if(!vec_itr->isValid()) { return false; }
	}
	return true;
}
void PLCChip::valueChanged(int_fast8_t index, PLCValueEvent & event)
{
	if(index >= 0) {
		this->inputs[uint_fast8_t(index)] = event;
	}
	if(this->isValid()) { this->handleApply(); }
}
void PLCChip::handleApply()
{
	vector<PLCValueEvent> old_outputs(this->outputs);

	this->apply();

	vector<PLCValueEvent>::iterator vec_itr;
	for(uint_fast8_t i = 0; i < old_outputs.size(); i++) {
	    if(old_outputs[i] != this->outputs[i]) {
	    	this->changeValue(int_fast8_t(i), this->outputs[i]);
	    }
	}
}