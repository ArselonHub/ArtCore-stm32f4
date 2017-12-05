/*
 * Timer.h
 *
 *  Created on: 30 Oca 2015
 *      Author: denizcan
 */

#ifndef ART_TIMER_H_
#define ART_TIMER_H_

#include <Art/CoreTimer.h>
#include <Art/Object.h>
#include <Art/Requester.h>
#include <Art/Task.h>

namespace Art
{
	class Timer : private CoreTimer, private Object, public Requester
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
	protected:
		virtual void doTimeoutSvc();

	private:
		class TimeoutTask : public Task
		{
		public:
			virtual void execute();
		};

		Int			jiffies_;
		Short		interval_;
		TimeoutTask timeoutTask_;
		Bool		autoReset_;
	};

	inline void Timer::stop()
	{
		CoreTimer::stop();
	}

	inline void Timer::setAutoReset(Bool value)
	{
		this->autoReset_ = value;
	}

	inline Bool Timer::isRunning()
	{
		return CoreTimer::isRunning();
	}

} /* namespace Art */

#endif /* SOURCE_ART_TIMER_H_ */
