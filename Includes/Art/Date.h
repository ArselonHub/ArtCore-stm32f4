/*
 * Date.h
 *
 *  Created on: Jan 10, 2018
 *      Author: denizcan
 */

#ifndef ART_DATE_H_
#define ART_DATE_H_

#include <Art/Types.h>

namespace Art
{

	enum DayOfWeek
	{
		DayOfWeekMonday,
		DayOfWeekTuesday,
		DayOfWeekWednesday,
		DayOfWeekThursday,
		DayOfWeekFriday,
		DayOfWeekSaturday,
		DayOfWeekSunday
	};

	class Date
	{
	public:
		Date();
		Date(Word y, Word m, Word d);
		Word year() const;
		Word month() const;
		Word day() const;
		DayOfWeek dayOfWeek() const;

		Date addYears(Word years) const;
		Date addMonths(Word months) const;
		Date addDays(Word days) const;

		Word daysTo(const Date& date) const;

		Bool isValid() const;
		Bool isNull() const;
		Bool isLeapYear() const;
		Int toJulianDays() const;

		Word clear();
		Word setValue(Word y, Word m, Word d);

		static Bool isLeapYear(Word year);
		static Date fromJulianDays(Int julianDay);

		Bool operator ==(const Date& r) const;
		Bool operator !=(const Date& r) const;
		Bool operator <(const Date& r) const;
		Bool operator <=(const Date& r) const;
		Bool operator >(const Date& r) const;
		Bool operator >=(const Date& r) const;
	private:
		Short	m_year;
		Byte	m_month;
		Byte	m_day;
	};

	inline Word Date::year() const
	{
		return m_year;
	}

	inline Word Date::month() const
	{
		return m_month;
	}

	inline Word Date::day() const
	{
		return m_day;
	}

} /* namespace Art */

#endif /* SOURCES_ART_DATE_H_ */
