/*
 * CaptureDetector.h
 *
 *  Created on: May 28, 2016
 *      Author: denizcan
 */

#ifndef ART_CAPTUREDETECTOR_H_
#define ART_CAPTUREDETECTOR_H_

#include <Art/CoreCaptureDetector.h>
#include <Art/Object.h>
#include <Art/Thread.h>

namespace Art
{
	class CaptureDetector : public CoreCaptureDetector
	{
	public:
		Signal<void*> onEvent() SIGNAL;

		CaptureDetector();
		~CaptureDetector();
		Thread* thread();
		void setThread(Thread* thread);

	private:
		virtual void doEventSvc();

		class OnEventTask : public Task
		{
			virtual void execute();
		};

		Thread*				m_thread;
		OnEventTask			m_onEventTask;
	};

	inline Thread* CaptureDetector::thread()
	{
		return m_thread;
	}

	inline void CaptureDetector::setThread(Thread* thread)
	{
		m_thread = thread;
	}

} /* namespace Art */

#endif /* SOURCE_ART_CAPTUREDETECTOR_H_ */
