/*
 * MatchDetector.h
 *
 *  Created on: May 22, 2016
 *      Author: denizcan
 */

#ifndef SOURCE_ART_MATCHDETECTOR_H_
#define SOURCE_ART_MATCHDETECTOR_H_

#include <Art/CoreMatchDetector.h>
#include <Art/Thread.h>

namespace Art
{
	class MatchDetector : public CoreMatchDetector
	{
	public:
		Signal<void*> onEvent() SIGNAL;

		MatchDetector();
		virtual ~MatchDetector();

		Thread* thread();
		void setThread(Thread* thread);

	private:
		virtual void doEventSvc();

		class OnEventTask : public Task
		{
			virtual void execute();
		};

		Thread*				m_thread;
		OnEventTask 		m_onEventTask;
	};

	inline Art::Thread* MatchDetector::thread()
	{
		return m_thread;
	}

	inline void MatchDetector::setThread(Thread* thread)
	{
		m_thread = thread;
	}

} /* namespace Art */

#endif /* SOURCE_ART_MATCHDETECTOR_H_ */
