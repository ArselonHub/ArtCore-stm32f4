/*
 * EdgeMonitor.h
 *
 *  Created on: 29 Oca 2015
 *      Author: denizcan
 */

#ifndef ART_EDGEDETECTOR_H_
#define ART_EDGEDETECTOR_H_

#include <Art/CoreEdgeDetector.h>
#include <Art/Thread.h>

namespace Art
{

	class EdgeDetector : public CoreEdgeDetector
	{
	public:
		EdgeDetector();
		Signal<void*> onEvent() SIGNAL;

		Thread* thread();
		void setThread(Thread* value);
	private:
		virtual void doEventSvc();

		class OnEventTask : public Task
		{
			virtual void execute();
		};

		Thread*				m_thread;
		OnEventTask			m_onEventTask;

	};

	inline Thread* EdgeDetector::thread()
	{
		return m_thread;
	}

	inline void EdgeDetector::setThread(Thread* value)
	{
		m_thread = value;
	}
} /* namespace Art */

#endif /* SOURCE_ART_EDGEMONITOR_H_ */
