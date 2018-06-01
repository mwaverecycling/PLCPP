#include <iostream>

#include <PLCValueEvent.hpp>
#include <PLCChip.hpp>

using namespace std;

class PLCChip_Add2UInt : public PLCChip
{
    public:
        PLCChip_Add2UInt();
        ~PLCChip_Add2UInt() = default;

    private:
    	virtual void apply() override;
};