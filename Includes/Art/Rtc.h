#ifndef RTC_H
#define RTC_H

#include <Art/DateTime.h>

namespace Art
{
	class Rtc
	{
	public:
		virtual Result getDateTime(DateTime& value);
		virtual Result setDateTime(DateTime& value);

		virtual Result getDate(DateTime& value) = 0;
		virtual Result getTime(DateTime& value) = 0;		
		virtual Result setDate(DateTime& value) = 0;
		virtual Result setTime(DateTime& value) = 0;
		virtual Result enable() = 0;
		virtual Result disable() = 0;
	
		Result setDate(UShortL year, Word month, Word day);
		Result setTime(Word hour, Word minute, Word second);
	protected:
	
	};
}

#if defined(LPC17XX)
#	include <Art/lpc/lpc17/LpcRtc-lpc17.h>
#endif

#endif
