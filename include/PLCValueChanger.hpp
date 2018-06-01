#ifndef PLCVALUECHANGER_HPP
#define PLCVALUECHANGER_HPP

#include <string>

#include <PLCValueEvent.hpp>
#include <PLCValueListener.hpp>

using namespace std;


class PLCValueChanger
{
    public:
        virtual void changeValue(PLCValueEvent & event) { this->changeValue(-1, event); };
        virtual void changeValue(int_fast8_t index, PLCValueEvent & event) = 0;
};

#endif // PLCVALUECHANGER_HPP
