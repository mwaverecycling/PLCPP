#ifndef PLCCHANGELISTENER_HPP
#define PLCCHANGELISTENER_HPP

#include <PLCValueEvent.hpp>
#include <cstdint>

using namespace std;

class PLCValueListener
{
    public:
        virtual void onChange(PLCValueEvent &event) = 0;
        virtual void onChange(uint_fast8_t index, PLCValueEvent &event) = 0;
};

#endif // PLCCHANGELISTENER_HPP
