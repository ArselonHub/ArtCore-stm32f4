/*
 * Rcc.h
 *
 *  Created on: May 25, 2017
 *      Author: denizcan
 */

#ifndef ART_PRIVATE_STM32_STM32F4_RCC_H_
#define ART_PRIVATE_STM32_STM32F4_RCC_H_

#include <Art/Types.h>

namespace Art
{
	enum PllClockSource
	{
		PllClockSourceHsi = 0,
		PllClockSourceHse = 1
	};

	enum PllPDivider
	{
		PllPDivider2 = 0,
		PllPDivider4 = 1,
		PllPDivider6 = 2,
		PllPDivider8 = 3
	};

	enum PllQDivider
	{
		PllQDivider1 = 1,
		PllQDivider2,
		PllQDivider3,
		PllQDivider4,
		PllQDivider5,
		PllQDivider6,
		PllQDivider7,
		PllQDivider8,
		PllQDivider9,
		PllQDivider10,
		PllQDivider11,
		PllQDivider12,
		PllQDivider13,
		PllQDivider14,
		PllQDivider15,
	};

	enum PllRDivider
	{
		PllRDivider2 = 2,
		PllRDivider3,
		PllRDivider4,
		PllRDivider5,
		PllRDivider6,
		PllRDivider7,
	};

	enum Apb2Prescaler
	{
		Apb2Prescaler1 = 0x0,
		Apb2Prescaler2 = 0x4,
		Apb2Prescaler4 = 0x5,
		Apb2Prescaler8 = 0x6,
		Apb2Prescaler16 = 0x7
	};

	enum Apb1Prescaler
	{
		Apb1Prescaler1 = 0x0,
		Apb1Prescaler2 = 0x4,
		Apb1Prescaler4 = 0x5,
		Apb1Prescaler8 = 0x6,
		Apb1Prescaler16 = 0x7
	};

	enum AhbPrescaler
	{
		AhbPrescaler1 = 0x0,
		AhbPrescaler2 = 0x8,
		AhbPrescaler8 = 0x9,
		AhbPrescaler16 = 0xA,
		AhbPrescaler32 = 0xB,
		AhbPrescaler64 = 0xC,
		AhbPrescaler128 = 0xD,
		AhbPrescaler256 = 0xE,
		AhbPrescaler512 = 0xF
	};

	enum MainClockSource
	{
		MainClockSourceHsi = 0,
		MainClockSourceHse = 1,
		MainClockSourcePll = 2
	};

	enum LcdClockPrescaler
	{
		LcdClockPrescaler2,
		LcdClockPrescaler4,
		LcdClockPrescaler8,
		LcdClockPrescaler16
	};

	enum Mco2Source
	{
		Mco2SourceSystem,
		Mco2SourcePllI2s,
		Mco2SourceHse,
		Mco2SourcePll
	};

	enum Mco2Prescaler
	{
		Mco2Prescaler1 = 0x0,
		Mco2Prescaler2 = 0x4,
		Mco2Prescaler3 = 0x5,
		Mco2Prescaler4 = 0x6,
		Mco2Prescaler5 = 0x7
	};

	enum FlashLatency
	{
		FlashLatency0,
		FlashLatency1,
		FlashLatency2,
		FlashLatency3,
		FlashLatency4,
		FlashLatency5,
		FlashLatency6,
		FlashLatency7
	};

	struct PllConfiguration
	{
		Word		n;
		PllPDivider	p;
		PllQDivider q;
	};

#define PLLCFG(n, p, q, r) (((n) << 6) | ((p) << 16) | ((q) << 24) | ((r) << 28))

	class Rcc
	{
	public:
		static MainClockSource mainClockSource();
		static Word setMainClockSource(MainClockSource value);

		static Word enableHse();
		static Word disableHse();

		static Word enableHsi();
		static Word disableHsi();

		static Bool isMainPllEnabled();
		static Word enableMainPll();
		static Word disableMainPll();
		static Word setMainPllCfg(UWord config);

		static PllClockSource pllSource();
		static Word setPllSource(PllClockSource value);
		static Word setPllSourceDivider(Word value);

		static Bool isSaiPllEnabled();
		static Word enableSaiPll();
		static Word disableSaiPll();
		static Word setSaiPllCfg(UWord config);
		static Word setSaiPllR(Word value);

		static AhbPrescaler ahbPrescaler();
		static Apb1Prescaler apb1Prescaler();
		static Apb2Prescaler apb2Prescaler();
		static void setAhbPrescaler(AhbPrescaler value);
		static void setApb1Prescaler(Apb1Prescaler value);
		static void setApb2Prescaler(Apb2Prescaler value);

		static Word setLcdClockPrescaler(LcdClockPrescaler value);
		static Word enablePowerControl();
		static Word enableOverDrive();
		static Word disableOverDrive();
		static Word enableMco2(Mco2Source source, Mco2Prescaler prescaler);
		static Word setFlashLatency(FlashLatency value);
	};

} /* namespace Art */

#endif /* SOURCE_ART_PRIVATE_STM32_STM32F4_RCC_H_ */
