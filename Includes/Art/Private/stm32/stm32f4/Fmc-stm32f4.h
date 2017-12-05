/*
 * Fmc.h
 *
 *  Created on: Oct 18, 2016
 *      Author: denizcan
 */

#ifndef SOURCE_ART_PRIVATE_STM32_STM32F4_FMC_STM32F4_H_
#define SOURCE_ART_PRIVATE_STM32_STM32F4_FMC_STM32F4_H_

#include <Art/Pin.h>
#include <Art/Private/stm32/stm32f4/SdramController-stm32f4.h>

namespace Art
{

	class Fmc
	{
	public:
		Fmc();
		Pin* sdcke0Pin() const;
		void setSdcke0Pin(Pin* sdcke1Pin);
		Pin* sdcke1Pin() const;
		void setSdcke1Pin(Pin* sdcke1Pin);
		Pin* sdne0Pin() const;
		void setSdne0Pin(Pin* sdne0Pin);
		Pin* sdne1Pin() const;
		void setSdne1Pin(Pin* sdne1Pin);

		SdramController* sdramController0();
		SdramController* sdramController1();
	private:
		enum DataBusWidth
		{
			DataBusWidth8Bits,
			DataBusWidth16Bits,
			DataBusWidth32Bits
		};

		enum AdressBusWidth
		{
			AdressBusWidth10Bits,
			AdressBusWidth11Bits,
			AdressBusWidth12Bits,
			AdressBusWidth13Bits
		};

		static void powerUp();
		static void configurePin(Pin* pinPort);
		static void configurePins(AdressBusWidth addressBusWidth, DataBusWidth dataBusWidth);

		Pin*		m_sdcke0Pin;
		Pin*		m_sdcke1Pin;
		Pin*		m_sdne0Pin;
		Pin*		m_sdne1Pin;
		SdramController	m_sdramController0;
		SdramController	m_sdramController1;

		friend class SdramController;
	};

	inline Pin* Fmc::sdcke0Pin() const
	{
		return m_sdcke0Pin;
	}

	inline void Fmc::setSdcke0Pin(Pin* value)
	{
		m_sdcke0Pin = value;
	}

	inline Pin* Fmc::sdcke1Pin() const
	{
		return m_sdcke1Pin;
	}

	inline void Fmc::setSdcke1Pin(Pin* value)
	{
		m_sdcke1Pin = value;
	}

	inline Pin* Fmc::sdne0Pin() const
	{
		return m_sdne0Pin;
	}

	inline void Fmc::setSdne0Pin(Pin* value)
	{
		m_sdne0Pin = value;
	}

	inline Pin* Fmc::sdne1Pin() const
	{
		return m_sdne1Pin;
	}

	inline void Fmc::setSdne1Pin(Pin* value)
	{
		m_sdne1Pin = value;
	}

	inline SdramController* Fmc::sdramController0()
	{
		return &m_sdramController0;
	}

	inline SdramController* Fmc::sdramController1()
	{
		return &m_sdramController1;
	}

	inline void Fmc::configurePin(Pin* pinPort)
	{
		pinPort->configure(PinSpeedHigh | PinFunction12);
	}

	extern Fmc* fmc();

} /* namespace Art */

#endif /* SOURCE_ART_PRIVATE_STM32_STM32F4_FMC_STM32F4_H_ */
