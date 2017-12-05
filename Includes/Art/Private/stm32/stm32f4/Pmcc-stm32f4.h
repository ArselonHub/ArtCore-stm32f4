/*
 * Power Management and Clocks
 *
 *  Created on: Aug 16, 2015
 *      Author: denizcan
 */

#ifndef ART_PRIVATE_STM32_STM32F4_PMCC_STM32F4_H_
#define ART_PRIVATE_STM32_STM32F4_PMCC_STM32F4_H_

#include <Art/Mcu.h>

namespace Art
{
	struct PmccProfile
	{
		MainClockSource	mainClockSource;
		PllClockSource	pllClockSource;
		Word			pllInputFrequency;
		UWord			mainPllConfig;
		UWord			saiPllConfig;
		UWord			i2sPllConfig;
	};

	extern const PmccProfile* pmccProfileDefault();
	extern const PmccProfile* pmccProfile168MhzFromHsi();
	extern const PmccProfile* pmccProfile192MhzFromHsi();
	extern const PmccProfile* pmccProfileHighestFromHsi();

	extern const PmccProfile* pmccProfile168MhzFromHse();
	extern const PmccProfile* pmccProfile192MhzFromHse();
	extern const PmccProfile* pmccProfileHighestFromHse();

	class Pmcc
	{
	public:
		Pmcc();
		const PmccProfile* profile();
		Word setProfile(const PmccProfile* value);
		Word coreFrequency();

		Word hseFrequency() const;
		void setHseFrequency(Word value);
		
		Word lcdClockFrequency() const;
		Word setLcdClockFrequency(Word value);
		Word enableLcdClock();
		Word disableLcdClock();
		Word ahbClockFrequency();
		Word apb1ClockFrequency();
		Word apb2ClockFrequency();

	private:
		Word updateClocks();
		Word fallback(Word result);

		const PmccProfile* m_profile;
		Word	m_hseFrequency;
		Word	m_coreFrequency;
		Word	m_lcdClockFrequency;

		Bool	m_usbClockEnabled: 1;
		Bool	m_i2sClockEnabled: 1;
		Bool	m_lcdClockEnabled: 1;
		Bool	m_recalcSai: 1;
	};
		
	inline const PmccProfile* Pmcc::profile() 
	{
		return m_profile; 
	}

	inline Word Pmcc::coreFrequency()
	{
		return m_coreFrequency;
	}


	inline Word Pmcc::hseFrequency() const
	{
		return m_hseFrequency;
	}

	inline void Pmcc::setHseFrequency(Word value)
	{
		m_hseFrequency = value;
	}

	extern Pmcc* pmcc();

	inline Word Pmcc::lcdClockFrequency() const
	{
		return m_lcdClockFrequency;
	}

}

#endif /* SOURCE_ART_PRIVATE_STM32_STM32F4_CLOCK_STM32F4_H_ */
