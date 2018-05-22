#ifndef PLCCHIP_ADD2UINT_HPP
#define PLCCHIP_ADD2UINT_HPP

#include <string>

#include <PLCValues.hpp>
#include <PLCChip.hpp>



struct s_PLC_Add2UInt_Input {
	struct PLCValueEvent* a;
	struct PLCValueEvent* b;
};
struct s_PLC_Add2UInt_Output {
	struct PLCValueEvent c;
};

class PLCChip_Add2UInt : public PLCChip
{
    public:
        PLCChip_Add2UInt();
        ~PLCChip_Add2UInt();
    	void valueChanged(string name, struct PLCValueEvent event) override;

    private:
    	struct s_PLC_Add2UInt_Input c_input;
    	void apply() override;
};

#endif // PLCCHIP_ADD2UINT_HPP
