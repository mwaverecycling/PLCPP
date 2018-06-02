#ifndef PLCCHIP_PRINT_HPP
#define PLCCHIP_PRINT_HPP

#include <PLCValueEvent.hpp>
#include <PLCChip.hpp>

class PLCChip_Print : public PLCChip
{
    public:
        PLCChip_Print();
        ~PLCChip_Print() = default;
        virtual void onChange(PLCValueEvent &event) override;
        virtual void onChange(__attribute__((unused)) uint_fast8_t index, PLCValueEvent &event) override;

    private:
    	virtual void apply() override;
};

#endif // PLCCHIP_ADD2UINT_HPP
