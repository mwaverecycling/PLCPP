#ifndef PLCCHIP_PRINT_HPP
#define PLCCHIP_PRINT_HPP

#include <string>

#include <PLCValues.hpp>
#include <PLCChip.hpp>

class PLCChip_Print : public PLCChip
{
    public:
        PLCChip_Print();
        ~PLCChip_Print();
    	void valueChanged(string name, struct PLCValueEvent event) override;

    private:
    	void apply() override;
};

#endif // PLCCHIP_ADD2UINT_HPP
