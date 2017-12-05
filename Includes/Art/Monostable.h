/*
 * Monostable.h
 *
 *  Created on: May 28, 2016
 *      Author: denizcan
 */

#ifndef ART_MONOSTABLE_H_
#define ART_MONOSTABLE_H_

#include <Art/Device.h>
#include <Art/Pit.h>

namespace Art
{

	class Monostable : public Device
	{
	public:
		Bool defaultValue() const;
		MatchChannel* port() const;
		UWord interval() const;

		void setDefaultValue(Bool defaultValue);
		void setPort(MatchChannel* value);
		void setInterval(UWord value);
		void trigger();
	private:
		void updateMatchMode();
		virtual Word openDevice();
		virtual Word closeDevice();
		virtual Word enableDevice();
		virtual Word disableDevice();

		MatchChannel*	m_port;
		UWord		m_interval;
		Bool		m_defaultValue;
	};

	inline MatchChannel* Monostable::port() const
	{
		return m_port;
	}

	inline Bool Monostable::defaultValue() const
	{
		return m_defaultValue;
	}

	inline UWord Monostable::interval() const
	{
		return m_interval;
	}

	inline void Monostable::setInterval(UWord value)
	{
		m_interval = value;
	}

	inline void Monostable::setPort(MatchChannel* value)
	{
		m_port = value;
	}

} /* namespace Art */

#endif /* SOURCE_ART_MONOSTABLE_H_ */
