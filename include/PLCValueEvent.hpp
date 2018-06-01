#ifndef PLCVALUEEVENT_HPP
#define PLCVALUEEVENT_HPP

#include <cstdint>
#include <sys/time.h>

union PLCValue
{
    bool v_bool;
	uint_fast8_t v_byte;
	int_fast32_t v_int;
	uint_fast32_t v_uint;
	int_fast64_t v_long;
	uint_fast64_t v_ulong;
	float v_float;
	double v_double;
};
struct PLCTime
{
	// Seconds since epoch
	uint_fast64_t sec;
	// Microseconds after second
	uint_fast32_t usec;

	PLCTime operator | (const PLCTime& o) const {
		if(sec < o.sec) { return *this; }
		else if(sec > o.sec) { return o; }
		else if(usec < o.usec) { return *this; }
		else { return o; }
	}
	PLCTime operator & (const PLCTime& o) const {
		if(sec > o.sec) { return *this; }
		else if(sec < o.sec) { return o; }
		else if(usec > o.usec) { return *this; }
		else { return o; }
	}
};

class PLCValueEvent
{
	public:
		static PLCValueEvent FromBool(bool value);
		static PLCValueEvent FromBit(bool value);
		static PLCValueEvent FromByte(uint_fast8_t value);
		static PLCValueEvent FromInt(int_fast32_t value);
		static PLCValueEvent FromUInt(uint_fast32_t value);
		static PLCValueEvent FromLong(int_fast64_t value);
		static PLCValueEvent FromULong(uint_fast64_t value);
		static PLCValueEvent FromFloat(float value);
		static PLCValueEvent FromDouble(double value);

        static PLCValueEvent FromBool(bool value, struct PLCTime time);
        static PLCValueEvent FromBit(bool value, struct PLCTime time);
        static PLCValueEvent FromByte(uint_fast8_t value, struct PLCTime time);
        static PLCValueEvent FromInt(int_fast32_t value, struct PLCTime time);
        static PLCValueEvent FromUInt(uint_fast32_t value, struct PLCTime time);
        static PLCValueEvent FromLong(int_fast64_t value, struct PLCTime time);
        static PLCValueEvent FromULong(uint_fast64_t value, struct PLCTime time);
        static PLCValueEvent FromFloat(float value, struct PLCTime time);
        static PLCValueEvent FromDouble(double value, struct PLCTime time);

		PLCValueEvent();
		~PLCValueEvent() = default;
		struct PLCTime getTime() const;
		bool isValid() const;
		static struct PLCTime TimevalToTime(struct timeval time);
		static struct PLCTime earliest(const PLCValueEvent event1, const PLCValueEvent event2);
		static struct PLCTime latest(const PLCValueEvent event1, const PLCValueEvent event2);

		bool getBool() const;
		bool getBit() const;
		uint_fast8_t getByte() const;
		int_fast32_t getInt() const;
		uint_fast32_t getUInt() const;
		int_fast64_t getLong() const;
		uint_fast64_t getULong() const;
		float getFloat() const;
		double getDouble() const;

		bool operator ==(const PLCValueEvent &b) const;
		bool operator !=(const PLCValueEvent &b) const;

	private:
		PLCValueEvent(const union PLCValue _value, const struct PLCTime _time);
		union PLCValue data;
		struct PLCTime time;
};

#endif
