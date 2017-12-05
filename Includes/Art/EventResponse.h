/*
 * EventResponse.h
 *
 *  Created on: Dec 6, 2016
 *      Author: denizcan
 */

#ifndef ART_EVENTRESPONSE_H_
#define ART_EVENTRESPONSE_H_

#include <Art/Response.h>
#include <Art/Event.h>

namespace Art
{

	class EventResponse : public Response
	{
	public:
		EventResponse();

		Event& event(); //TODO make this const
		Word wait();
		Word wait(Word timeout);
	private:
		virtual void clearTrigger();
		virtual void trigger();
		virtual void triggerSvc();

		Event	m_event;
	};

	inline Event& EventResponse::event()
	{
		return m_event;
	}

	inline Word EventResponse::wait()
	{
		return m_event.wait();
	}

	inline Word EventResponse::wait(Word timeout)
	{
		return m_event.wait(timeout);
	}
} /* namespace Art */

#endif /* SOURCE_ART_EVENTRESPONSE_H_ */
