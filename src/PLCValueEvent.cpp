#include "PLCValueEvent.hpp"

#define PLCValueEvent_Constructor(name,littletype,valuetype) \
PLCValueEvent PLCValueEvent::name(littletype value)\
{\
	union PLCValue data;\
	data.valuetype = value;\
	struct timeval tv;\
	gettimeofday(&tv, NULL);\
	struct PLCTime time = PLCValueEvent::TimevalToTime(tv);\
	return PLCValueEvent(data, time);\
}\
PLCValueEvent PLCValueEvent::name(littletype value, struct PLCTime time)\
{\
	union PLCValue data;\
	data.valuetype = value;\
	return PLCValueEvent(data, time);\
}


PLCValueEvent_Constructor(FromBool, bool, v_bool)
PLCValueEvent_Constructor(FromBit, bool, v_bool)
PLCValueEvent_Constructor(FromByte, uint_fast8_t, v_byte)
PLCValueEvent_Constructor(FromInt, int_fast32_t, v_int)
PLCValueEvent_Constructor(FromUInt, uint_fast32_t, v_uint)
PLCValueEvent_Constructor(FromLong, int_fast64_t, v_long)
PLCValueEvent_Constructor(FromULong, uint_fast64_t, v_ulong)
PLCValueEvent_Constructor(FromFloat, float, v_float)
PLCValueEvent_Constructor(FromDouble, double, v_double)

struct PLCTime PLCValueEvent::getTime() const
{
	return this->time;
}
bool PLCValueEvent::isValid() const
{
	return this->getTime().sec > 0;
}
struct PLCTime PLCValueEvent::TimevalToTime(struct timeval time)
{
	struct PLCTime plctime{uint_fast64_t(time.tv_sec), uint_fast32_t(time.tv_usec)};
	return plctime;
}
struct PLCTime PLCValueEvent::earliest(const PLCValueEvent event1, const PLCValueEvent event2)
{
	return event1.getTime() | event2.getTime();
}
struct PLCTime PLCValueEvent::latest(const PLCValueEvent event1, const PLCValueEvent event2)
{
	return event1.getTime() & event2.getTime();
}


bool          PLCValueEvent::getBool()   const { return this->data.v_bool;   }
bool          PLCValueEvent::getBit()    const { return this->data.v_bool;   }
uint_fast8_t  PLCValueEvent::getByte()   const { return this->data.v_byte;   }
int_fast32_t  PLCValueEvent::getInt()    const { return this->data.v_int;    }
uint_fast32_t PLCValueEvent::getUInt()   const { return this->data.v_uint;   }
int_fast64_t  PLCValueEvent::getLong()   const { return this->data.v_long;   }
uint_fast64_t PLCValueEvent::getULong()  const { return this->data.v_ulong;  }
float         PLCValueEvent::getFloat()  const { return this->data.v_float;  }
double        PLCValueEvent::getDouble() const { return this->data.v_double; }


bool PLCValueEvent::operator ==(const PLCValueEvent &b) const { return getULong() == b.getULong(); }
bool PLCValueEvent::operator !=(const PLCValueEvent &b) const { return !(*this == b); }



PLCValueEvent::PLCValueEvent(): data(), time({0, 0}) {  }
PLCValueEvent::PLCValueEvent(union PLCValue _value, struct PLCTime _time): data(_value), time(_time) {  }