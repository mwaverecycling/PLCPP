#ifndef PLCCHIP_HPP
#define PLCCHIP_HPP

#include <PLCValueChanger.hpp>
#include <PLCValueListener.hpp>

class PLCChip: public PLCValueChanger, public PLCValueListener
{
    public:

    protected:

    private:
    	virtual void apply();
};

#endif // PLCCHIP_HPP
