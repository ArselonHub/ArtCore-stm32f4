/*
 * Clock.h
 *
 *  Created on: Jan 2, 2015
 *      Author: denizcan
 */

#ifndef ART_LPC_LPC17_PMCC_LPC17_H_
#define ART_LPC_LPC17_PMCC_LPC17_H_

#include <Art/Private/lpc/Pmcc-lpc.h>
#include <Art/Sit.h>

namespace Art
{
	enum Pll0ClockSource
	{
		Pll0ClockSourceIRC = 0x0,
		Pll0ClockSourceMainOscillator = 0x1,
		Pll0ClockSourceRtcOscillator = 0x2
	};

	enum MainOscillatorRange
	{
		MainOscillatorRangeUpTo20Mhz = (0 << 4),
		MainOscillatorRangeUpTo25MHz = (1 << 4)
	};

	struct PmccProfile
	{
		const UartDivisor*	uartDivisorProfile;
		UWord				frequency;
		UWord				usLoop;
		UWord				msLoop;
		UWord				sysTickValue;
		UWord				pitPrescaler;
		UWord				flashConfiguration;
		Pll0ClockSource		pll0Source;
		UWord				pll0Configuration;
		UWord				clockConfiguration;
		UWord				pll1Configuration;
		UWord				usbClockConfiguration;
	};

	extern const UartDivisor uartProfile12Mhz[];
	extern const PmccProfile* pmccProfileInternal12Mhz();
	extern const PmccProfile* pmccProfileDefault();
	extern const PmccProfile* pmccProfile96MhzFrom12MhzMainOscillator();

	class Pmcc
	{
	public:
		Pmcc();
		void setMainOscillatorRange(MainOscillatorRange range);
		const PmccProfile* profile();
		void setProfile(const PmccProfile* value);
		
	private:
		const PmccProfile* profile_;
	};

	inline const PmccProfile* Pmcc::profile()
	{
		return profile_;
	}
	
	inline Pmcc* pmcc()
	{
		static Pmcc instance;
		return &instance;
	}

}


#endif /* SOURCE_ART_LPC_LPC112X_CLOCK_H_ */
