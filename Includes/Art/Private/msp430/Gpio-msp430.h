/*
 * Gpio-msp430.h
 *
 *  Created on: 04 Mar 2015
 *      Author: denizcan
 */

#ifndef ART_PRIVATE_MSP430_GPIO_MSP430_H_
#define ART_PRIVATE_MSP430_GPIO_MSP430_H_

#include <Art/Types.h>

namespace Art
{
	enum PinDirection
	{
		PinDirectionInput = 0x08,
		PinDirectionOutput = 0x0C,
		PinDirectionOutput0 = 0x0E,
		PinDirectionOutput1 = 0x0F
	};

	enum PinMode
	{
		PinModePullUp = 0x30,
		PinModePullDown = 0x20
	};

	enum PinFunction
	{
	};
}

#include <Art/Private/PinPort.h>
#include <Art/Private/GpioPort.h>

namespace Art
{

	class Port1 : public GpioPort
	{
	public:
		static const Pin& pin0();
		static const Pin& pin1();
		static const Pin& pin2();
		static const Pin& pin3();
		static const Pin& pin4();
		static const Pin& pin5();
		static const Pin& pin6();
		static const Pin& pin7();
	};

	class Port2 : public GpioPort
	{
	public:
		static const Pin& pin0();
		static const Pin& pin1();
		static const Pin& pin2();
		static const Pin& pin3();
		static const Pin& pin4();
		static const Pin& pin5();
		static const Pin& pin6();
		static const Pin& pin7();
	};

	inline Port1& port1() { return *((Port1*)1); }
	inline Port2& port2() { return *((Port2*)2); }

} /* namespace Art */

#endif /* GPIO_MSP430_H_ */
