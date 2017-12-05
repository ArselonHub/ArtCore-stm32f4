/*
 * Clock-cc430f.h
 *
 *  Created on: 30 Ara 2014
 *      Author: denizcan
 */

#ifndef CLOCK_CC430F_H_
#define CLOCK_CC430F_H_

#include <Art/Mcu.h>

namespace Art
{
	struct UartConfig
	{
		UWord br;
		UWord mctl;
	};

	struct ClockProfile
	{
		const UartConfig* uartProfile;
		UInt	frequency;
		UWord usLoop;
		UWord msLoop;
	};

	enum MclkSource
	{
		MclkSourceXT1 = SELM_0,
		MclkSourceVLO = SELM_1,
		MclkSourceREFO = SELM_2,
		MclkSourceDCO = SELM_3,
		MclkSourceDCOCLKDIV = SELM_4,
		MclkSourceXT2 = SELM_5
	};

	enum AclkSource
	{
		AclkSourceXT1 = SELA_0,
		AclkSourceVLO = SELA_1,
		AclkSourceREFO = SELA_2,
		AclkSourceDCO = SELA_3,
		AclkSourceDCOCLKDIV = SELA_4,
		AclkSourceXT2 = SELA_5
	};

	enum SmclkSource
	{
		SmclkSourceXT1 = SELS_0,
		SmclkSourceVLO = SELS_1,
		SmclkSourceREFO = SELS_2,
		SmclkSourceDCO = SELS_3,
		SmclkSourceDCOCLKDIV = SELS_4,
		SmclkSourceXT2 = SELS_5
	};

	enum MclkDivider
	{
		MclkDivider1 = DIVM_0,
		MclkDivider2 = DIVM_1,
		MclkDivider4 = DIVM_2,
		MclkDivider8 = DIVM_3,
		MclkDivider16 = DIVM_4,
		MclkDivider32 = DIVM_5
	};

	enum AclkDivider
	{
		AclkDivider1 = DIVA_0,
		AclkDivider2 = DIVA_1,
		AclkDivider4 = DIVA_2,
		AclkDivider8 = DIVA_3,
		AclkDivider16 = DIVA_4,
		AclkDivider32 = DIVA_5
	};

	enum SmclkDivider
	{
		SmclkDivider1 = DIVS_0,
		SmclkDivider2 = DIVS_1,
		SmclkDivider4 = DIVS_2,
		SmclkDivider8 = DIVS_3,
		SmclkDivider16 = DIVS_4,
		SmclkDivider32 = DIVS_5
	};

	enum XT1Capacitor
	{
		X1Capacitor2pF = XCAP_0,
		X1Capacitor5_5pF = XCAP_1,
		X1Capacitor8_5pF = XCAP_2,
		X1Capacitor12pF = XCAP_3
	};

	enum XT1Drive
	{
		XT1DriveBypass = XT1BYPASS,
		XT1DriveLFLowestPower = XT1DRIVE_0,
		XT1DriveLFLowPower = XT1DRIVE_1,
		XT1DriveLFMediumPower = XT1DRIVE_2,
		XT1DriveLFHighPower = XT1DRIVE_3,
		XT1DriveUpTo8MHz = XT1DRIVE_0 | XTS,
		XT1DriveUpTo16MHz = XT1DRIVE_1 | XTS,
		XT1DriveUpTo24MHz = XT1DRIVE_2 | XTS,
		XT1DriveUpTO32MHz = XT1DRIVE_2 | XTS
	};

	enum FLLReference
	{
		FLLReferenceXT1 = 0x0,
		FLLReferenceREFO = 0x2,
		FLLReferenceXT2 = 0x9

	};

	enum FLLDivider
	{
		FLLDivider1 = FLLD_0,
		FLLDivider2 = FLLD_1,
		FLLDivider4 = FLLD_2,
		FLLDivider8 = FLLD_3,
		FLLDivider16 = FLLD_4,
		FLLDivider32 = FLLD_5
	};

	enum DCORange
	{
		DCORange0_20MHzTo0_70MHz = DCORSEL_0,
		DCORange0_36MHzTo1_47MHz = DCORSEL_1,
		DCORange0_75MHzTo3_17Mhz = DCORSEL_2,
		DCORange1_51MHzTo6_07MHz = DCORSEL_3,
		DCORange3_20MHzTo12_3MHz = DCORSEL_4,
		DCORange6_00MHzTo23_7Mhz = DCORSEL_5,
		DCORange10_7MHzTo39_0MHz = DCORSEL_6,
		DCORange19_6MHzTo60_0Mhz = DCORSEL_7
	};

	class Clock
	{
	public:
		Clock();

		inline void setAclkSource(AclkSource value)
		{
			UCSCTL4 = (UCSCTL4 & ~(0x7 << 8)) | value;
		}

		inline void setSmclkSource(SmclkSource value)
		{
			UCSCTL4 = (UCSCTL4 & ~(0x7 << 4)) | value;
		}

		inline void setMclkSource(MclkSource value)
		{
			UCSCTL4 = (UCSCTL4 & ~(0x7 << 0)) | value;
		}

		inline void setClockSources(MclkSource mclkSource,
				SmclkSource smclkSource, AclkSource aclkSource)
		{
			UCSCTL4 = mclkSource | smclkSource | aclkSource;
		}

		inline void setMclkDivider(MclkDivider value)
		{
			UCSCTL5 = (UCSCTL5 & ~(0x7 << 0)) | value;
		}

		inline void setSmclkDivider(SmclkDivider value)
		{
			UCSCTL5 = (UCSCTL5 & ~(0x7 << 4)) | value;
		}

		inline void setAclkDivider(AclkDivider value)
		{
			UCSCTL5 = (UCSCTL5 & ~(0x7 << 8)) | value;
		}

		inline void setClockDividers(MclkDivider mclkDivider, SmclkDivider smclkDivider, AclkDivider aclkDivider)
		{
			UCSCTL5 = mclkDivider | smclkDivider | aclkDivider;
		}

		inline void setXT1Capacitor(XT1Capacitor value)
		{
			UCSCTL6 = (UCSCTL6 & ~XCAP_3) | value;
		}

		inline void setXT1Drive(XT1Capacitor value)
		{
			UCSCTL6 = (UCSCTL6 & ~(XT1DRIVE_3 | XTS)) | value;
		}

		inline void disableXT1()
		{
			UCSCTL6 |= XT1OFF;
		}

		void enableXT1();
		void configureFLL(FLLReference reference, DCORange range, UWord factor);
		void configureMclkAndSmclkTo16MhzAclkTo32768HzFrom32768HzCrystalOnXT1();
		void configureMclkAndSmclkTo20MhzAclkTo32768HzFrom32768HzCrystalOnXT1();

		inline void configureToHighSpeedUsingDefaults()
		{
			configureMclkAndSmclkTo16MhzAclkTo32768HzFrom32768HzCrystalOnXT1();
		}

		inline void configureToHighestSpeedUsingDefaults()
		{
			configureMclkAndSmclkTo20MhzAclkTo32768HzFrom32768HzCrystalOnXT1();
		}

		void configureDefault() { configureToHighSpeedUsingDefaults(); }

		const ClockProfile* getProfile() { return profile; }

	private:
		const ClockProfile* profile;
	};

	extern const ClockProfile clockProfile16MHz;
	extern const ClockProfile clockProfile20MHz;
	extern const ClockProfile clockProfileDefault;

	extern Clock& clock();
}

#endif /* CLOCK_CC430F_H_ */
