#ifndef PLCCHANGELISTENER_HPP
#define PLCCHANGELISTENER_HPP

#include <string>

#include <PLCValues.hpp>

using namespace std;

class PLCValueListener
{
    public:
        virtual void valueChanged(string name, struct PLCValueEvent event);
};

#endif // PLCCHANGELISTENER_HPP
