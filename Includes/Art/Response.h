/*
 * Response.h
 *
 *  Created on: Dec 6, 2016
 *      Author: denizcan
 */

#ifndef ART_RESPONSE_H_
#define ART_RESPONSE_H_

#include <Art/Types.h>

namespace Art
{

	class Response
	{
	public:
		void clear();
		Word value();
		Bool isPending();
		void setValue(Word value);
		void setValueSvc(Word value);
	private:
		virtual void clearTrigger() = 0;
		virtual void trigger() = 0;
		virtual void triggerSvc() = 0;

		Bool	m_pending;
		Word	m_value;
	};

	inline Word Response::value()
	{
		return m_value;
	}

	inline Bool Response::isPending()
	{
		return m_pending;
	}
} /* namespace Art */

#endif /* SOURCE_ART_RESPONSE_H_ */
