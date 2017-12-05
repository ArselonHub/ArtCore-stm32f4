#ifndef ART_EVENT_H
#define ART_EVENT_H

#include <Art/Delay.h>
#include <Art/Private/WaitObject.h>

namespace Art
{
	class Event : public Private::WaitObject
	{
	public:
		Event();
		Event(Bool value);
		Event(Bool value, Bool autoReset);
		Bool isAutoReset();
		Bool isSet() const;
		void setAutoReset(Bool value);
		void set();
		void setSvc();
		void clear();
		Word wait();
		Word wait(Word timeout);
		static Word waitForAny(Event* event0, Word timeout = 0);
		static Word waitForAny(Event* event0, Event* event1, Word timeout = 0);
	private:
		Bool	m_value;
		Bool	m_autoReset;

		friend class EventTask;

		static void waitSvcImp(Event* event, Private::WaitHandler* waitHandler, Word interval);
		static void waitMultipleSvcImp(Private::WaitHandler* waitHandler, Word interval);
		static void setSvcImp(Event* event);
	};	

	inline Event::Event(Bool value)
	{
		m_value = value;
		m_autoReset = 1;
	}

	inline Event::Event(Bool value, Bool autoReset)
	{
		m_value = value;
		m_autoReset = autoReset;
	}

	inline Bool Event::isAutoReset()
	{
		return m_autoReset;
	}

	inline Bool Event::isSet() const
	{
		 return m_value;
	}

	inline void Event::setSvc()
	{
		 setSvcImp(this);
	}
	
	inline void Event::setAutoReset(Bool value)
	{
		m_autoReset = value;
	}

	inline Word Event::waitForAny(Event* event0, Word timeout)
	{
		return event0->wait(timeout);
	}
}

#endif
