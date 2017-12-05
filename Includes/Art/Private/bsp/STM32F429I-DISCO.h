/*
 * STM32F429I-DISC1.h
 *
 *  Created on: Dec 1, 2017
 *      Author: denizcan
 */

#ifndef ART_PRIVATE_BSP_STM32F429I_DISC1_H_
#define ART_PRIVATE_BSP_STM32F429I_DISC1_H_

#include <Art/Pin.h>
#include <Art/Uart.h>

namespace Art
{

	inline Pin* button()
	{
		return pa0();
	}

	inline Pin* redLed()
	{
		return pg14();
	}

	inline Pin* greenLed()
	{
		return pg13();
	}

	inline Pin* led()
	{
		return pg13();
	}

	inline Pin* led0()
	{
		return pg13();
	}

	inline Pin* led1()
	{
		return pg14();
	}

	inline Uart* uart()
	{
		return usart1();
	}
}



#endif /* SOURCE_ART_PRIVATE_BSP_STM32F429I_DISC1_H_ */
