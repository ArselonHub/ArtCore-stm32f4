/*
 * Clock.h
 *
 *  Created on: Jan 2, 2015
 *      Author: denizcan
 */

#ifndef ART_LPC_LPC112X_CLOCK_H_
#define ART_LPC_LPC112X_CLOCK_H_

#include <Art/Mcu.h>
#include <Art/Private/lpc/Pmcc-lpc.h>
#include <Art/Sit.h>

namespace Art
{
	struct PmccProfile
	{
		const UartDivisor*	uartDivisorProfile;
		UWord				frequency;
		UWord				usLoop;
		UWord				sysTickValue;
		UWord				pitPrescaler;
		UWord				mainClkSel;
		UWord				sysPllClkSel;
	};

	extern const PmccProfile pmccProfileDefault;

	enum PLLClockSource
	{
		PLLClockSourceIRC = 0x0,
		PLLClockSourceSystemOscillator = 0x1,
	};

	enum SystemOscillatorConfig
	{
		SystemOscillatorConfigBypass = 1,
		SystemOscillatorConfigUpTo20Mhz = 0,
		SystemOscillatorConfigUpTo25MHz = 2
	};

	enum MainClockSource
	{
		MainClockSourceIRC = 0x0,
		MainClockSourcePLLInput = 0x1,
		MainClockSourceWDT = 0x2,
		MainClockSourcePLLOutput = 0x3
	};

	enum PLLPostDivider
	{
		PLLPostDivider2,
		PLLPostDivider4,
		PLLPostDivider8,
		PLLPostDivider16
	};

	enum ClockOutSource
	{
		ClockOutSourceIRC,
		ClockOutSourceSystemOscillator,
		ClockOutSourceWatchdogOscillator,
		ClockOutSourceMainClock
	};

	class Pmcc
	{
	public:
		static void setProfile(const PmccProfile& value);


		static void enableIRCOscillator();
		static void disableIRCOscillator();

		static void enableSystemOscillator(SystemOscillatorConfig config = SystemOscillatorConfigUpTo20Mhz);
		static void configurePLL(PLLClockSource source, UWord config);
		static void setMainClockSource(MainClockSource value);
		static void configureClockOut(ClockOutSource value, UWord divider = 1);

		/**
		 * m = FCLKOUT / FCLKIN
		 * FCCO = FCLKOUT * p = FCLKIN * m
		 * FCCO must be between 156MHz..320MHz, p must be 2, 4, 6, or 8
		 */
		static void configurePLL(PLLClockSource source, UWord m, PLLPostDivider psel)
		{
			configurePLL(source, ((m - 1) << 0) | (psel << 5));
		}

		static void configureDefault() { }
		static void configureToHighestSpeedUsingInternalOscillator();
		static const PmccProfile& profile() { return *profile_; }
	private:
		static const PmccProfile* profile_;
	};

	inline Pmcc& clock()
	{
		return *((Pmcc*)0);
	}
}

#endif /* SOURCE_ART_LPC_LPC112X_CLOCK_H_ */
