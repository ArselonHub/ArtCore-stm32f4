/*
 * WaitData.h
 *
 *  Created on: Oct 28, 2016
 *      Author: denizcan
 */

#ifndef SOURCE_ART_PRIVATE_WAITHANDLER_H_
#define SOURCE_ART_PRIVATE_WAITHANDLER_H_

#include <Art/CoreTimer.h>

namespace Art
{
	class Thread;
	class Event;

	namespace Private
	{
		class WaitLink;
		class WaitHandler : private CoreTimer
		{
		public:
			WaitHandler(Thread* thread);

			void suspendSvc(Word timeout);
			void abortSvc();
			void wakeSvc();
			virtual void setSvc(WaitLink* waitLink);
			Thread* thread();
			Word result();
			void setResult(Word value);
		private:
	        virtual void doTimeoutSvc();

	        void removeUnsetLinks();

			Thread*		m_thread;
			WaitLink*	m_links;
			Word		m_result;

			friend class Art::Event;
			friend class WaitLink;
		};

		inline WaitHandler::WaitHandler(Thread* thread)
		{
			m_thread = thread;
			m_links = 0;
		}

		inline Thread* WaitHandler::thread()
		{
			return m_thread;
		}

		inline Word WaitHandler::result()
		{
			return m_result;
		}

		inline void WaitHandler::setResult(Word value)
		{
			m_result = value;
		}

	}

}
#endif /* SOURCE_ART_PRIVATE_WAITHANDLER_H_ */
