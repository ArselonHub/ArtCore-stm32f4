#ifndef ART_BSP_STM32F0DISCOVERY_H
#define ART_BSP_STM32F0DISCOVERY_H

#include <Art/Pin.h>
#include <Art/SerialPort.h>

namespace Art
{	
	class STM32F0Discovery
	{
	public:
		static void initialize();
	};
	typedef STM32F0Discovery bsp;

	class Led0 : public Pin
	{
	public:
		void open();
	};

	//extern Led0 led0;
	
}

#define BSP_LED0	PC9
#define BSP_UART	usart1

#endif
