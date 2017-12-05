/*
 * WriterLog.h
 *
 *  Created on: Apr 19, 2016
 *      Author: denizcan
 */

#ifndef ART_STREAMLOG_H_
#define ART_STREAMLOG_H_

#include <Art/Log.h>
#include <Art/Stream.h>

namespace Art
{

	class StreamLog : public Log
	{
	public:
		Stream* stream() const;
		void setStream(Stream* stream);
	private:
		virtual Word writeLine(const String& s);
		virtual Word writeLine(const Expression& e);
		Stream* m_stream;
	};

	inline Stream* StreamLog::stream() const
	{
		return m_stream;
	}

	inline void StreamLog::setStream(Stream* stream)
	{
		m_stream = stream;
	}

} /* namespace Art */

#endif /* SOURCE_ART_STREAMLOG_H_ */
