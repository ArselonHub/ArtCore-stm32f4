/*
 * Timer.h
 *
 *  Created on: 30 Oca 2015
 *      Author: denizcan
 */

#ifndef ART_TIMER_H_
#define ART_TIMER_H_

#include <Art/Object.h>
#include <Art/CoreTimer.h>
#include <Art/Task.h>
#include <Art/Thread.h>

namespace Art
{
	class Timer : public Object
	{
	public:
		virtual ~Timer();
		Signal<void*> onTimeout() SIGNAL;

		Timer();
	  	void start();
		void start(ShortL interval);
		void stop();
		void setInterval(ShortL value);
		void setAutoReset(Bool value);
		Bool isRunning();

		Thread* thread() const;
		void setThread(Thread* value);

	private:
		class CoreTimer : public Art::CoreTimer
		{
			virtual void doTimeoutSvc();
		};

		class TimeoutTask : public Task
		{
		public:
			virtual void execute();
		};

		Int			m_jiffies;
		Short		m_interval;
		TimeoutTask m_timeoutTask;
		Bool		m_autoReset;
		CoreTimer	m_coreTimer;
		Thread*		m_thread;
	};

	inline Thread* Timer::thread() const
	{
		return m_thread;
	}

	inline void Timer::setThread(Thread* value)
	{
		m_thread = value;
	}

} /* namespace Art */

#endif /* SOURCE_ART_TIMER_H_ */
