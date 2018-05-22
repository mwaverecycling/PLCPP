#include <string>
#include <map>
#include <vector>

#include "PLCValues.hpp"
#include "PLCValueChanger.hpp"
#include "PLCValueListener.hpp"

using namespace std;

PLCValueChanger::PLCValueChanger() {  }
PLCValueChanger::~PLCValueChanger() {  }

void PLCValueChanger::addListener(PLCValueListener* listener, string name)
{
    this->listeners[name].push_back(listener);
}
void PLCValueChanger::removeListener(PLCValueListener* listener)
{
    map<string, vector<PLCValueListener *>>::iterator map_itr;
    for(map_itr = this->listeners.begin(); map_itr != this->listeners.end(); map_itr++)
    {
        this->removeListener(listener, map_itr->first);
    }
}
void PLCValueChanger::removeListener(PLCValueListener* listener, string name)
{
    if(this->listeners.find(name) != this->listeners.end()) {
        vector<PLCValueListener *>::iterator vec_itr;
        for(vec_itr = this->listeners[name].begin(); vec_itr != this->listeners[name].end(); vec_itr++) {
            if(*vec_itr == listener) {
                vec_itr = this->listeners[name].erase(vec_itr);
                vec_itr--;
            }
        }
    }
}
void PLCValueChanger::changeValue(string name, struct PLCValueEvent value)
{
    if(this->listeners.find(name) != this->listeners.end()) {
        vector<PLCValueListener *>::iterator set_itr;
        for(set_itr = this->listeners[name].begin(); set_itr != this->listeners[name].end(); set_itr++) {
            PLCValueListener* listr = *set_itr;
            listr->valueChanged(name, value);
        }
    }
}
