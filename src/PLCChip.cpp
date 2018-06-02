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
bool PLCChip::isValid() const
{
	vector<PLCValueEvent>::const_iterator vec_itr;
	for(vec_itr = this->inputs.begin(); vec_itr != this->inputs.end(); vec_itr++) {
	    if(!vec_itr->isValid()) { return false; }
	}
	return true;
}
void PLCChip::onChange(PLCValueEvent &event) { this->onChange(0, event); }
void PLCChip::onChange(uint_fast8_t index, PLCValueEvent &event)
{
	this->inputs.at(index) = event;
	if(this->isValid()) { this->handleApply(); }
}
void PLCChip::handleApply()
{
	vector<PLCValueEvent> old_outputs(this->outputs);

	this->apply();

	vector<PLCValueEvent>::iterator vec_itr;
	for(uint_fast8_t i = 0; i < old_outputs.size(); i++) {
	    if(old_outputs[i] != this->outputs[i]) {
	    	this->updateValue(i, this->outputs[i]);
	    }
	}
}
void PLCChip::updateValue(uint_fast8_t index, PLCValueEvent & event)
{
	this->listeners[index]->onChange(index, event);
}