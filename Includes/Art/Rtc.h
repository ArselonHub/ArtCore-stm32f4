#ifndef ART_RTC_H
#define ART_RTC_H

#include <Art/Device.h>
#include <Art/DateTime.h>

namespace Art
{
	class Rtc : public Device
	{
	public:
		Signal<void*> onTick() SIGNAL;

		DateTime dateTime();
		Date date();
		Time time();

		Word readDate(Date* date);
		Word readTime(Time* time);
		Word readDateTime(DateTime* dateTime);
		Word setDate(const Date& value);
		Word setTime(const Time& value);
		Word setDateTime(const DateTime& value);
		Word setDate(Word year, Word month, Word day);
		Word setTime(Word hour, Word minute, Word second);

	private:
		virtual Word readDeviceDateTime(DateTime* dateTime) = 0;
		virtual Word setDeviceTime(const Time& value) = 0;
		virtual Word setDeviceDate(const Date& value) = 0;
		virtual Word setDeviceDateTime(const DateTime& value) = 0;
	};
}

#if defined(LPC17XX)
#	include <Art/lpc/lpc17/LpcRtc-lpc17.h>
#elif defined(__STM32F4XX__)
#	include <Art/Private/stm32/stm32f4/StmRtc.h>
#endif

#endif
