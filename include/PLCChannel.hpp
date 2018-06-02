#ifndef PLCCHANNEL_HPP
#define PLCCHANNEL_HPP

#include <vector>
#include <utility>
#include <functional>

#include "PLCValueListener.hpp"

using namespace std;


typedef function<void(PLCValueEvent & event)> t_PLCCallback;
typedef pair<PLCValueListener*, int_fast8_t> t_PLCListenerPair;

class PLCChannel: public PLCValueListener
{
    public:
        virtual void addCallback(t_PLCCallback callback);
        virtual void addListener(PLCValueListener* listener, int_fast8_t channel);
        virtual void removeListener(PLCValueListener* listener);

        virtual void onChange(PLCValueEvent &event);
        virtual void onChange(__attribute__((unused)) uint_fast8_t index, PLCValueEvent &event);

    protected:
        virtual void updateValue(PLCValueEvent &event);

    private:
        vector<t_PLCCallback> callbacks;
        vector<t_PLCListenerPair> listeners;
};

#endif