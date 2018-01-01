namespace Art
{
	enum PinFunction
	{
		PinFunctionAnalog	= 0x0D,
		PinFunctionInput 	= 0x0E,
		PinFunctionOutput 	= 0x0F,
		PinFunctionOutput0	= 0x8F,
		PinFunctionOutput1	= 0x9F,
		PinFunction0		= 0x08,
		PinFunction1		= 0x09,
		PinFunction2		= 0x0A,
		PinFunction3		= 0x0B
	};

	enum PinPull
	{
		PinPullNone		= 0x800,
		PinPullDown		= 0x900,
		PinPullUp		= 0xA00,
		PinPullRepeat	= 0xB00
	};

	enum PinDrive
	{
		PinDrivePushPull	= 0x8000,
		PinDriveOpenDrain	= 0x9000
	};

	enum PinHysteresis
	{
		PinHysteresisInactive	= 0x80000,
		PinHysteresisActive		= 0x90000

	};
}

#include <Art/Private/GpioPort.h>
#include <Art/Private/PinPort.h>

namespace Art
{
	class Port0
	{
	public:
		static const Pin& pin1();
		static const Pin& pin2();
		static const Pin& pin3();
		static const Pin& pin4();
		static const Pin& pin5();
		static const Pin& pin6();
		static const Pin& pin7();
		static const Pin& pin8();
		static const Pin& pin9();
		static const Pin& pin10();
		static const Pin& pin11();
	};

	class Port1
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
		static const Pin& pin8();
		static const Pin& pin9();
		static const Pin& pin10();
		static const Pin& pin11();
	};


	class Port2
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
		static const Pin& pin8();
		static const Pin& pin9();
		static const Pin& pin10();
		static const Pin& pin11();
	};

	class Port3
	{
	public:
		static const Pin& pin0();
		static const Pin& pin1();
		static const Pin& pin2();
		static const Pin& pin3();
		static const Pin& pin4();
		static const Pin& pin5();
	};

	static inline Port0& port0() { return *((Port0*)0x10); }
	static inline Port1& port1() { return *((Port1*)0x10); }
	static inline Port2& port2() { return *((Port2*)0x10); }
	static inline Port3& port3() { return *((Port3*)0x10); }
}
