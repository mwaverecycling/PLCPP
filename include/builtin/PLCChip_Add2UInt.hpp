#ifndef PLCCHIP_ADD2UINT_HPP
#define PLCCHIP_ADD2UINT_HPP

#include <PLCChip.hpp>

class PLCChip_Add2UInt : public PLCChip
{
    public:
        PLCChip_Add2UInt();
        ~PLCChip_Add2UInt() = default;

    private:
    	virtual void apply() override;
};

#endif // PLCCHIP_ADD2UINT_HPP