#ifndef PLCCHANGELISTENER_HPP
#define PLCCHANGELISTENER_HPP

#include <PLCValueEvent.hpp>
#include <cstdint>

using namespace std;

class PLCValueListener
{
    public:
        virtual void valueChanged(PLCValueEvent & event) { this->valueChanged(-1, event); };
        virtual void valueChanged(int_fast8_t index, PLCValueEvent & event) = 0;
};

#endif // PLCCHANGELISTENER_HPP
