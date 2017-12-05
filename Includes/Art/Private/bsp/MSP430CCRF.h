#ifndef ART_BSP_MSP430CCRF_H
#define ART_BSP_MSP430CCRF_H

#include <Art/Pin.h>
#include <Art/SerialPort.h>

namespace Art
{
	namespace Bsp
	{
		const PinPort& led0PinPort = Port1::pin0;
		const PinPort& button0Pin = Port1::pin1;
		static SerialPort& serialPort0 = uscia0Uart;
	}
	
}

#endif
