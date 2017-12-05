/*
 * WaitLink.h
 *
 *  Created on: Oct 27, 2016
 *      Author: denizcan
 */

#ifndef SOURCE_ART_PRIVATE_WAITLINK_H_
#define SOURCE_ART_PRIVATE_WAITLINK_H_

#include <Art/BasicList.h>
#include <Art/Private/WaitHandler.h>

namespace Art
{

	class Thread;
	class Event;

	namespace Private
	{
		class WaitLink
		{
		public:
			WaitLink(WaitHandler* waitHandler);
			WaitHandler* waitHandler();
		private:
			WaitLink*		m_next;
			WaitLink*		m_previous;
			WaitLink*		m_nextLink;
			WaitHandler*	m_waitHandler;

			friend class BasicList<WaitLink>;
			friend class WaitHandler;
			friend class EventWaitHandler;
			friend class Art::Event;
		};

		inline WaitLink::WaitLink(WaitHandler* waitHandler)
		{
			m_waitHandler = waitHandler;
			m_nextLink = waitHandler->m_links;
			waitHandler->m_links = this;
		}

		inline WaitHandler* WaitLink::waitHandler()
		{
			return m_waitHandler;
		}

}

} /* namespace Art */

#endif /* SOURCE_ART_PRIVATE_WAITLINK_H_ */
