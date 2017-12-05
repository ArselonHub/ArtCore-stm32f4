#ifndef _ART_BSP_LANDTIGET_H
#define _ART_BSP_LANDTIGET_H

#include <Art/Pin.h>
#include <Art/SerialPort.h>
#include <Art/Pit.h>

namespace Art
{
	namespace Bsp
	{
		const PinId led0Pin = P2_0;
		const PinId led1Pin = P2_1;
		const PinId led2Pin = P2_2;
		const PinId button0Pin = P2_10;
		const PinId button1Pin = P2_12;
		const PinId button2Pin = P2_1;
		static SerialPort& serialPort0 = uart0;		
	}
	
}

#endif
