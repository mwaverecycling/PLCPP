#ifndef PLCCHIP_HPP
#define PLCCHIP_HPP

#include <vector>

#include "PLCValueEvent.hpp"
#include "PLCValueChanger.hpp"
#include "PLCValueListener.hpp"

using namespace std;

class PLCChip: public PLCValueChanger, public PLCValueListener
{
	public: 
		PLCChip(uint_fast8_t inputs, uint_fast8_t outputs);
		virtual ~PLCChip() = default;
        bool isValid() const;

        virtual void setListener(int_fast8_t index, PLCValueListener* listener);
        virtual void changeValue(int_fast8_t index, PLCValueEvent & event) override;
        virtual void valueChanged(int_fast8_t index, PLCValueEvent & event) override;

    protected:
        vector<PLCValueEvent> inputs;
        vector<PLCValueEvent> outputs;
        virtual void handleApply();
        virtual void apply() = 0;

    private:
        vector<PLCValueListener*> listeners;
};

#endif // PLCCHIP_HPP
