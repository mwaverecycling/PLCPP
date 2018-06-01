#ifndef PLCCHANNEL_HPP
#define PLCCHANNEL_HPP

#include <vector>
#include <utility>
#include "PLCValueListener.hpp"
#include "PLCValueChanger.hpp"

using namespace std;


typedef pair<PLCValueListener*, int_fast8_t> t_PLCListenerPair;

class PLCChannel: public PLCValueListener, public PLCValueChanger
{
    public:
        virtual void addListener(PLCValueListener* listener, uint_fast8_t index);
        virtual void removeListener(PLCValueListener* listener);

        virtual void valueChanged(PLCValueEvent & event);
        virtual void valueChanged(__attribute__((unused)) int_fast8_t index, PLCValueEvent & event);
        virtual void changeValue(PLCValueEvent & event);
        virtual void changeValue(__attribute__((unused)) int_fast8_t index, PLCValueEvent & event);

    private:
        vector<t_PLCListenerPair> listeners;
};

#endif