/*
 * DateTime.h
 *
 *  Created on: 05 Mar 2014
 *      Author: denizcan
 */

#ifndef ART_DATETIME_H_
#define ART_DATETIME_H_

#include <Art/Date.h>
#include <Art/Time.h>

namespace Art
{
	class DateTime
	{
	public:
		DateTime();
		DateTime(const Date& date, const Time& time);
		const Date& date() const;
		const Time& time() const;

		Word year();
		Word month();
		Word day();
		Word hour();
		Word minute();
		Word second();
		Word setDate(Word year, Word month, Word day);
		Word setTime(Word hour, Word minute);
		Word setTime(Word hour, Word minute, Word second);
		Word setTime(Word hour, Word minute, Word second, Word millisecond);
		Bool isValid() const;
		Bool isNull() const;

		DateTime addYears(Word years);
		DateTime addMonths(Word months);
		DateTime addDays(Word days);
		DateTime addHours(Word hours);
		DateTime addMinutes(Word minutes);
		DateTime addSeconds(Word seconds);
		DateTime addMilliseconds(Word milliseconds);

		Bool operator ==(const DateTime& r) const;
		Bool operator !=(const DateTime& r) const;
		Bool operator <(const DateTime& r) const;
		Bool operator <=(const DateTime& r) const;
		Bool operator >(const DateTime& r) const;
		Bool operator >=(const DateTime& r) const;

	private:
		DateTime addArray(Word* array);
		Date	m_date;
		Time	m_time;
	};

	inline Word DateTime::year()
	{
		return m_date.year();
	}

	inline Word DateTime::month()
	{
		return m_date.month();
	}

	inline Word DateTime::day()
	{
		return m_date.day();
	}

	inline Word DateTime::hour()
	{
		return m_time.hour();
	}

	inline Word DateTime::minute()
	{
		return m_time.minute();
	}

	inline Word DateTime::second()
	{
		return m_time.second();
	}

	inline const Date& DateTime::date() const
	{
		return m_date;
	}

	inline const Time& DateTime::time() const
	{
		return m_time;
	}

} /* namespace Art */
#endif /* DATETIME_H_ */
