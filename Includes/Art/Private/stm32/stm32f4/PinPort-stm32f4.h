#ifndef ART_PRIVATE_STM32_STM32F4XX_PINPORT_H
#define ART_PRIVATE_STM32_STM32F4XX_PINPORT_H

#include <Art/Types.h>

namespace Art
{		
	class Pin;
	
	enum PinFunction
	{
		PinFunctionAnalog	= 0x0B0,
		PinFunctionInput 	= 0x080,
		PinFunctionOutput 	= 0x090,
		PinFunctionOutput0	= 0x890,
		PinFunctionOutput1	= 0x990,
		PinFunction0		= 0x0A0,
		PinFunction1		= 0x0A1,
		PinFunction2		= 0x0A2,
		PinFunction3		= 0x0A3,
		PinFunction4		= 0x0A4,
		PinFunction5		= 0x0A5,
		PinFunction6		= 0x0A6,
		PinFunction7		= 0x0A7,
		PinFunction8		= 0x0A8,
		PinFunction9		= 0x0A9,
		PinFunction10		= 0x0AA,
		PinFunction11		= 0x0AB,
		PinFunction12		= 0x0AC,
		PinFunction13		= 0x0AD,
		PinFunction14		= 0x0AE,
		PinFunction15		= 0x0AF
	};
	
	enum PinPull
	{
		PinPullNone			= 0x8000,
		PinPullUp			= 0x9000,
		PinPullDown			= 0xA000
	};
	
	enum PinDrive
	{
		PinDrivePushPull	= 0x80000,
		PinDriveOpenDrain	= 0x90000
	};
	
	enum PinSpeed
	{
		PinSpeedLow			= 0x800000,
		PinSpeedMedium		= 0x900000,
		PinSpeedFast		= 0xA00000,
		PinSpeedHigh		= 0xB00000
	};

	class PortA
	{
	public:
		static void powerUp();
	};

	class PortB
	{
	public:
		static void powerUp();
	};

	class PortC
	{
	public:
		static void powerUp();
	};
	
	class PortD
	{
	public:
		static void powerUp();
	};
	
	class PortE
	{
	public:
		static void powerUp();
	};
	
	class PortF
	{
	public:
		static void powerUp();
	};
	
	class PortG
	{
	public:
		static void powerUp();
	};

	class PortH
	{
	public:
		static void powerUp();
	};

	static inline PortA* pa() { return ((PortA*)GPIOA); }
	static inline PortB* pb() { return ((PortB*)GPIOB); }
	static inline PortC* pc() { return ((PortC*)GPIOC); }
	static inline PortD* pd() { return ((PortD*)GPIOD); }
	static inline PortE* pe() { return ((PortE*)GPIOE); }
	static inline PortF* pf() { return ((PortF*)GPIOF); }
	static inline PortG* pg() { return ((PortG*)GPIOG); }
	static inline PortH* ph() { return ((PortH*)GPIOH); }
	
	extern Pin* pa0();
	extern Pin* pa1();
	extern Pin* pa2();
	extern Pin* pa3();
	extern Pin* pa4();
	extern Pin* pa5();
	extern Pin* pa6();
	extern Pin* pa7();
	extern Pin* pa8();
	extern Pin* pa9();
	extern Pin* pa10();
	extern Pin* pa11();
	extern Pin* pa12();
	extern Pin* pa13();
	extern Pin* pa14();
	extern Pin* pa15();

	extern Pin* pb0();
	extern Pin* pb1();
	extern Pin* pb2();
	extern Pin* pb3();
	extern Pin* pb4();
	extern Pin* pb5();
	extern Pin* pb6();
	extern Pin* pb7();
	extern Pin* pb8();
	extern Pin* pb9();
	extern Pin* pb10();
	extern Pin* pb11();
	extern Pin* pb12();
	extern Pin* pb13();
	extern Pin* pb14();
	extern Pin* pb15();

	extern Pin* pc0();
	extern Pin* pc1();
	extern Pin* pc2();
	extern Pin* pc3();
	extern Pin* pc4();
	extern Pin* pc5();
	extern Pin* pc6();
	extern Pin* pc7();
	extern Pin* pc8();
	extern Pin* pc9();
	extern Pin* pc10();
	extern Pin* pc11();
	extern Pin* pc12();
	extern Pin* pc13();
	extern Pin* pc14();
	extern Pin* pc15();
	
	extern Pin* pd0();
	extern Pin* pd1();
	extern Pin* pd2();
	extern Pin* pd3();
	extern Pin* pd4();
	extern Pin* pd5();
	extern Pin* pd6();
	extern Pin* pd7();
	extern Pin* pd8();
	extern Pin* pd9();
	extern Pin* pd10();
	extern Pin* pd11();
	extern Pin* pd12();
	extern Pin* pd13();
	extern Pin* pd14();
	extern Pin* pd15();

	extern Pin* pe0();
	extern Pin* pe1();
	extern Pin* pe2();
	extern Pin* pe3();
	extern Pin* pe4();
	extern Pin* pe5();
	extern Pin* pe6();
	extern Pin* pe7();
	extern Pin* pe8();
	extern Pin* pe9();
	extern Pin* pe10();
	extern Pin* pe11();
	extern Pin* pe12();
	extern Pin* pe13();
	extern Pin* pe14();
	extern Pin* pe15();

	extern Pin* pf0();
	extern Pin* pf1();
	extern Pin* pf2();
	extern Pin* pf3();
	extern Pin* pf4();
	extern Pin* pf5();
	extern Pin* pf6();
	extern Pin* pf7();
	extern Pin* pf8();
	extern Pin* pf9();
	extern Pin* pf10();
	extern Pin* pf11();
	extern Pin* pf12();
	extern Pin* pf13();
	extern Pin* pf14();
	extern Pin* pf15();

	extern Pin* pg0();
	extern Pin* pg1();
	extern Pin* pg2();
	extern Pin* pg3();
	extern Pin* pg4();
	extern Pin* pg5();
	extern Pin* pg6();
	extern Pin* pg7();
	extern Pin* pg8();
	extern Pin* pg9();
	extern Pin* pg10();
	extern Pin* pg11();
	extern Pin* pg12();
	extern Pin* pg13();
	extern Pin* pg14();
	extern Pin* pg15();
}

#endif
