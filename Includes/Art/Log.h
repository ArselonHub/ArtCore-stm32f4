/*
 * Log.h
 *
 *  Created on: Apr 19, 2016
 *      Author: denizcan
 */

#ifndef ART_LOG_H_
#define ART_LOG_H_

#include <Art/String.h>

namespace Art
{
	enum LogLevel
	{
		LogLevelNone,
		LogLevelError,
		LogLevelWarning,
		LogLevelInfo,
		LogLevelDebug,
		LogLevelVerbose
	};

	class Log
	{
	public:
		Log();
		LogLevel level() const;
		void setLevel(LogLevel level);
//		void error(const String s);
//		void warning(const String s);
//		void info(const String s);
		void debug(const String& s);
		void debug(const Expression& e);
//		void verbose(const String s);
	private:
		virtual Word writeLine(const String& s) = 0;
		virtual Word writeLine(const Expression& e) = 0;
		LogLevel m_level;
	};

	inline Log::Log()
	{
		m_level = LogLevelVerbose;
	}

	inline LogLevel Log::level() const
	{
		return m_level;
	}

	inline void Log::setLevel(LogLevel level)
	{
		m_level = level;
	}

}

#endif /* SOURCE_ART_LOG_H_ */
