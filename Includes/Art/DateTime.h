/*
 * DateTime.h
 *
 *  Created on: 05 Mar 2014
 *      Author: denizcan
 */

#ifndef ART_DATETIME_H_
#define ART_DATETIME_H_

#include <Art/Types.h>

namespace Art
{

	enum Month
	{
		MonthJanuary = 1,
		MonthFebruary,
		MonthMarch,
		MonthApril,
		MonthMay,
		MonthJune,
		MonthJuly,
		MonthAugust,
		MonthSeptember,
		MonthOctober,
		MonthNovember,
		MonthDecember
	};

	enum Day
	{
		DayMonday,
		DayTuesday,
		DayWednesday,
		DayThursday,
		DayFriday,
		DaySaturday,
		DaySunday
	};

	class DateTime
	{
	public:
		DateTime();
		UShortL year();
		UWord month();
		UWord day();
		UWord hour();
		UWord minute();
		UWord second();
		void setDate(UShortL year, Word month, Word day);
		void setTime(Word hour, Word minute, Word second);
		void setYear(UShortL value);
		void setMonth(Month value);
		void setMonth(UWord value);
		void setDay(UWord value);
		void setHour(UWord value);
		void setMinute(UWord value);
		void setSecond(UWord value);

	private:
		UShort 	year_;
		UByte	month_;
		UByte	day_;
		UByte	hour_;
		UByte	minute_;
		UByte	second_;
	};

	inline UShortL DateTime::year()
	{
		return year_;
	}

	inline UWord DateTime::month()
	{
		return month_;
	}

	inline UWord DateTime::day()
	{
		return day_;
	}

	inline UWord DateTime::minute()
	{
		return minute_;
	}

	inline UWord DateTime::second()
	{
		return second_;
	}

	inline void DateTime::setDate(UShortL year, Word month, Word day)
	{
		year_ = year;
		month_ = month;
		day_= day;
	}

	inline void DateTime::setTime(Word hour, Word minute, Word second)
	{
		this->hour_ = hour;
		this->minute_ = minute;
		this->second_ = second;
	}

	inline void DateTime::setYear(UShortL value)
	{
		year_ = value;
	}

	inline void DateTime::setMonth(Month value)
	{
		month_ = value;
	}

	inline void DateTime::setMonth(UWord value)
	{
		month_ = value;
	}

	inline void DateTime::setDay(UWord value)
	{
		day_ = value;
	}

	inline void DateTime::setHour(UWord value)
	{
		hour_ = value;
	}

	inline void DateTime::setMinute(UWord value)
	{
		minute_ = value;
	}

	inline void DateTime::setSecond(UWord value)
	{
		second_ = value;
	}
} /* namespace Art */
#endif /* DATETIME_H_ */
