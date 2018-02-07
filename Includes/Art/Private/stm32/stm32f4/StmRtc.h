/*
 * StmRtc.h
 *
 *  Created on: Jan 11, 2018
 *      Author: denizcan
 */

#ifndef ART_PRIVATE_STM32_STM32F4_STMRTC_H_
#define ART_PRIVATE_STM32_STM32F4_STMRTC_H_

#include <Art/Rtc.h>
#include <Art/Task.h>

namespace Art
{
	extern "C" void RTC_Alarm_IRQHandler();
	extern "C" void RTC_WKUP_IRQHandler();

	class StmRtc : public Rtc
	{
	public:
		StmRtc();
		virtual ~StmRtc();

	private:
		virtual Word openDevice();
		virtual Word closeDevice();
		virtual Word enableDevice();
		virtual Word disableDevice();

		void startInitialization();
		void finishInitialization();

		void writeDate(const Date& date);
		void writeTime(const Time& time);

		void processAlarmInterruptSvc();
		void processWakeUpInterruptSvc();

		virtual Word readDeviceDateTime(DateTime* dateTime);
		virtual Word setDeviceTime(const Time& value);
		virtual Word setDeviceDate(const Date& value);
		virtual Word setDeviceDateTime(const DateTime& value);
		Bool checkDate(const Date& value);

		class TickTask : public Task
		{
			virtual void execute();
		};

		TickTask	m_tickTask;

		friend void RTC_Alarm_IRQHandler();
		friend void RTC_WKUP_IRQHandler();
	};

	extern StmRtc* rtc();
} /* namespace Art */

#endif /* SOURCES_ART_PRIVATE_STM32_STM32F4_STMRTC_H_ */
