#include "PLCChannel.hpp"

using namespace std;

void PLCChannel::addCallback(t_PLCCallback callback)
{
    this->callbacks.push_back(callback);
}
void PLCChannel::addListener(PLCValueListener* listener, int_fast8_t channel)
{
	this->listeners.push_back(make_pair(listener, channel));
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

void PLCChannel::onChange(PLCValueEvent &event) { this->updateValue(event); };
void PLCChannel::onChange(__attribute__((unused)) uint_fast8_t index, PLCValueEvent &event) { this->updateValue(event); };
void PLCChannel::updateValue(PLCValueEvent &event)
{
	vector<t_PLCListenerPair>::iterator listr_itr;
    for(listr_itr = this->listeners.begin(); listr_itr != this->listeners.end(); listr_itr++) {
        t_PLCListenerPair listr_pair = *listr_itr;
        listr_pair.first->onChange(listr_pair.second, event);
    }

    vector<t_PLCCallback>::iterator cb_itr;
    for(cb_itr = this->callbacks.begin(); cb_itr != this->callbacks.end(); cb_itr++) {
        (*cb_itr)(event);
    }
}