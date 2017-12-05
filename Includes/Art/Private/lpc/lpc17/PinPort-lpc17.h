#ifndef ART_PRIVATE_LPC_PINPORT_LPC17_H
#define ART_PRIVATE_LPC_PINPORT_LPC17_H

#include <Art/Types.h>

namespace Art
{	
	class PinPort;

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

	extern PinPort* p0_0();
	extern PinPort* p0_1();
	extern PinPort* p0_2();
	extern PinPort* p0_3();
	extern PinPort* p0_4();
	extern PinPort* p0_5();
	extern PinPort* p0_6();
	extern PinPort* p0_7();
	extern PinPort* p0_8();
	extern PinPort* p0_9();
	extern PinPort* p0_10();
	extern PinPort* p0_11();
	extern PinPort* p0_15();
	extern PinPort* p0_16();
	extern PinPort* p0_17();
	extern PinPort* p0_18();

	extern PinPort* p0_22();
	extern PinPort* p0_25();
	extern PinPort* p0_26();
	extern PinPort* p0_29();
	extern PinPort* p0_30();

	extern PinPort* p1_4();
	extern PinPort* p1_5();
	extern PinPort* p1_6();
	extern PinPort* p1_7();
	extern PinPort* p1_8();
	extern PinPort* p1_9();
	extern PinPort* p1_10();
	extern PinPort* p1_11();
	extern PinPort* p1_18();
	extern PinPort* p1_23();
	extern PinPort* p1_24();
	extern PinPort* p1_25();
	extern PinPort* p1_26();
	extern PinPort* p1_28();
	extern PinPort* p1_29();
	extern PinPort* p1_30();

	extern PinPort* p2_0();
	extern PinPort* p2_1();
	extern PinPort* p2_2();
	extern PinPort* p2_3();
	extern PinPort* p2_4();
	extern PinPort* p2_5();
	extern PinPort* p2_6();
	extern PinPort* p2_7();
	extern PinPort* p2_8();
	extern PinPort* p2_9();
	extern PinPort* p2_10();

	extern PinPort* p3_25();
	extern PinPort* p3_26();

	extern PinPort* p4_28();
	extern PinPort* p4_29();

#if defined(__LQFP100__)
	extern PinPort* p0_19();
	extern PinPort* p0_20();
	extern PinPort* p0_21();
	extern PinPort* p0_23();
	extern PinPort* p0_24();
	extern PinPort* p0_27();
	extern PinPort* p0_28();
	extern PinPort* p1_20();
	extern PinPort* p1_23();
	extern PinPort* p1_24();
	extern PinPort* p2_11();
	extern PinPort* p2_12();
	extern PinPort* p2_13();
#endif
}

#include <Art/PinPort.h>

#endif
