#ifndef ART_LPC_RTC_H
#define ART_LPC_RTC_H

#include <Art/Rtc.h>

namespace Art
{
	class LpcRtc : public Rtc
	{
	public:
		virtual Result getDate(DateTime& value);
		virtual Result getTime(DateTime& value);		
		virtual Result setDate(DateTime& value);
		virtual Result setTime(DateTime& value);
		virtual Result enable();
		virtual Result disable();
		void open() {}
	};
	
	extern LpcRtc rtc;
}

#endif
