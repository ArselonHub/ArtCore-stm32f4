#ifndef ART_PRIVATE_LPC_PINPORT_LPC17_H
#define ART_PRIVATE_LPC_PINPORT_LPC17_H

#include <Art/Types.h>

namespace Art
{	
	class Pin;

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
		PinPullNone		= 0xA00,
		PinPullDown		= 0xB00,
		PinPullUp		= 0x800,
		PinPullRepeat	= 0x900
	};

	enum PinDrive
	{
		PinDrivePushPull	= 0x8000,
		PinDriveOpenDrain	= 0x9000
	};

	extern Pin* p0_0();
	extern Pin* p0_1();
	extern Pin* p0_2();
	extern Pin* p0_3();
	extern Pin* p0_4();
	extern Pin* p0_5();
	extern Pin* p0_6();
	extern Pin* p0_7();
	extern Pin* p0_8();
	extern Pin* p0_9();
	extern Pin* p0_10();
	extern Pin* p0_11();
	extern Pin* p0_15();
	extern Pin* p0_16();
	extern Pin* p0_17();
	extern Pin* p0_18();

	extern Pin* p0_22();
	extern Pin* p0_25();
	extern Pin* p0_26();
	extern Pin* p0_29();
	extern Pin* p0_30();

	extern Pin* p1_4();
	extern Pin* p1_5();
	extern Pin* p1_6();
	extern Pin* p1_7();
	extern Pin* p1_8();
	extern Pin* p1_9();
	extern Pin* p1_10();
	extern Pin* p1_11();
	extern Pin* p1_18();
	extern Pin* p1_23();
	extern Pin* p1_24();
	extern Pin* p1_25();
	extern Pin* p1_26();
	extern Pin* p1_28();
	extern Pin* p1_29();
	extern Pin* p1_30();

	extern Pin* p2_0();
	extern Pin* p2_1();
	extern Pin* p2_2();
	extern Pin* p2_3();
	extern Pin* p2_4();
	extern Pin* p2_5();
	extern Pin* p2_6();
	extern Pin* p2_7();
	extern Pin* p2_8();
	extern Pin* p2_9();
	extern Pin* p2_10();

	extern Pin* p3_25();
	extern Pin* p3_26();

	extern Pin* p4_28();
	extern Pin* p4_29();

#if defined(__LQFP100__)
	extern Pin* p0_19();
	extern Pin* p0_20();
	extern Pin* p0_21();
	extern Pin* p0_23();
	extern Pin* p0_24();
	extern Pin* p0_27();
	extern Pin* p0_28();
	extern Pin* p1_20();
	extern Pin* p1_23();
	extern Pin* p1_24();
	extern Pin* p2_11();
	extern Pin* p2_12();
	extern Pin* p2_13();
#endif
}

#endif
