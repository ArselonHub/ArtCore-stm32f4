/*
 * PinPort.h
 *
 *  Created on: 04 Mar 2015
 *      Author: denizcan
 */

#ifndef ART_PINPORT_H_
#define ART_PINPORT_H_

#include <Art/Mcu.h>

#if defined(STM32F051)
	#include <Art/stm32/stm32f0/PinDefinitions-stm32f051.h>
#elif defined(__STM32F4XX__)
	#include <Art/Private/stm32/stm32f4/PinPort-stm32f4.h>
#elif defined(__LPC112X__)
	#include <Art/Private/lpc/lpc112x/Gpio-lpc112x.h>
#elif defined(__LPC17XX__)
	#include <Art/Private/lpc/lpc17/PinPort-lpc17.h>
#elif defined(MSP430)
	#include <Art/Private/msp430/Gpio-msp430.h>
#elif defined(__CC2541__)
	#include <Art/Private/cc254x/Gpio-cc254x.h>
#endif

namespace Art
{
	class Pin
	{
	public:
		void assign(Word value) const;
		Bool value() const;
		void setValue(Bool value) const;
		void set() const;
		void clear() const;
		void toggle() const;
		void configure(UWord configuration) const;
		void setDirection(Bool value) const;
		void setFunction(PinFunction function) const;
		void setPull(PinPull value) const;
		void setDrive(PinDrive value) const;

#if defined(__STM32F4XX__)
		void setSpeed(PinSpeed value) const;
#endif
	};

	inline void Pin::assign(Word value) const
	{
		setValue(value);
	}
}

#endif /* PINPORT_H_ */
