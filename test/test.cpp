#include <cstdio>
#include <sys/time.h>
#include <math.h>

#include "builtin/PLCChip_Add2UInt.hpp"
#include "builtin/debug/PLCChip_Print.hpp"

int main()
{
	PLCChip_Add2UInt* adder = new PLCChip_Add2UInt;
	PLCChip_Print* printer = new PLCChip_Print;

	struct timeval now_tv;
	gettimeofday(&now_tv, NULL);

	struct PLCTime now((unsigned long int)now_tv.tv_usec, (unsigned long long int)now_tv.tv_sec);
	
	//unsigned long long int a = 4;
	//unsigned long long int b = 3;
	union PLCValue a_val(4ULL);
	union PLCValue b_val(3ULL);

	struct PLCChangeEvent a_event(now, a_val);
	struct PLCChangeEvent b_event(now, b_val);

	adder->addListener(printer, "c");
	adder->valueChanged("a", a_event);
	adder->valueChanged("b", b_event);

	delete adder;
	delete printer;
}