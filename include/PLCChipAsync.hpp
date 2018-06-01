#ifndef PLCCHIPASYNC_HPP
#define PLCCHIPASYNC_HPP

#include "PLCChip.hpp"

using namespace std;


class PLCChipAsync: public PLCChip
{
	public: 
		PLCChipAsync(uint_fast8_t inputs, uint_fast8_t outputs);
		virtual ~PLCChipAsync() = default;

    protected:
        virtual void handleApply();
        virtual void apply() = 0;
};

#endif // PLCCHIPASYNC_HPP
