#ifndef PLCVALUES_HPP
#define PLCVALUES_HPP

#include <ctime>

union PLCValue
{
    bool v_bool;
    bool v_bit;
    unsigned char v_byte;
    long long int v_int;
    unsigned long long int v_uint;
    double v_float;
};

struct PLCTime
{
	unsigned long int usec;
	unsigned long long int sec;

	PLCTime operator | (const PLCTime& o) const {
		if(sec < o.sec) { return *this; }
		else if(sec > o.sec) { return o; }
		else if(usec < o.usec) { return *this; }
		else { return o; }
	}
};
struct PLCValueEvent
{
	struct PLCTime time;
	union PLCValue value;
};

#endif
