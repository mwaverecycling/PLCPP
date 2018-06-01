#include "PLCChannel.hpp"


using namespace std;

void PLCChannel::addListener(PLCValueListener* listener, uint_fast8_t index)
{
	this->listeners.push_back(make_pair(listener, index));
}
void PLCChannel::removeListener(PLCValueListener* listener)
{
	vector<t_PLCListenerPair>::iterator vec_itr;
    for(vec_itr = this->listeners.begin(); vec_itr != this->listeners.end(); vec_itr++) {
        if(vec_itr->first == listener) {
            vec_itr = this->listeners.erase(vec_itr);
            vec_itr--;
        }
    }
}

void PLCChannel::valueChanged(PLCValueEvent & event) { this->changeValue(event); };
void PLCChannel::valueChanged(__attribute__((unused)) int_fast8_t index, PLCValueEvent & event) { this->valueChanged(event); };
void PLCChannel::changeValue(__attribute__((unused)) int_fast8_t index, PLCValueEvent & event) { this->changeValue(event); };
void PLCChannel::changeValue(PLCValueEvent & event)
{
	vector<t_PLCListenerPair>::iterator vec_itr;
    for(vec_itr = this->listeners.begin(); vec_itr != this->listeners.end(); vec_itr++) {
        t_PLCListenerPair listr_pair = *vec_itr;
        listr_pair.first->valueChanged(listr_pair.second, event);
    }
}