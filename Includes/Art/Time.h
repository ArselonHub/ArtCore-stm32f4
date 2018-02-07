/*
 * Time.h
 *
 *  Created on: Jan 11, 2018
 *      Author: denizcan
 */

#ifndef ART_TIME_H_
#define ART_TIME_H_

#include <Art/Types.h>

namespace Art
{
	class DateTime;

	class Time
	{
	public:
		Time();
		Time(Word h, Word m);
		Time(Word h, Word m, Word s);
		Time(Word h, Word m, Word s, Word ms);

		Word hour() const;
		Word minute() const;
		Word second() const;
		Word milisecond() const;

		Time addHours(Int h) const;
		Time addMinutes(Int m) const;
		Time addSeconds(Int s) const;
		Time addMiliseconds(Int ms) const;
		void clear();
		Bool isValid() const;
		Bool isNull() const;

		Word setValue(Word h, Word m);
		Word setValue(Word h, Word m, Word s);
		Word setValue(Word h, Word m, Word s, Word ms);
		static const Time now();

		Bool operator ==(const Time& r) const;
		Bool operator !=(const Time& r) const;
		Bool operator <(const Time& r) const;
		Bool operator <=(const Time& r) const;
		Bool operator >(const Time& r) const;
		Bool operator >=(const Time& r) const;

	private:
		Time (Word* array);
		Time addArray(Word* array) const;

		Short	m_milisecond;
		Byte	m_hour;
		Byte	m_minute;
		Byte	m_second;

		friend class DateTime;
	};

	inline Word Time::hour() const
	{
		return m_hour;
	}

	inline Word Time::minute() const
	{
		return m_minute;
	}

	inline Word Time::second() const
	{
		return m_second;
	}

	inline Word Time::milisecond() const
	{
		return m_milisecond;
	}

} /* namespace Art */

#endif /* SOURCES_ART_TIME_H_ */
