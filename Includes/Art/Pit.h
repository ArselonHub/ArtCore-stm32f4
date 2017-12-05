/*
 * Pit.h
 *
 *  Created on: May 22, 2016
 *      Author: denizcan
 */

#ifndef ART_PIT_H_
#define ART_PIT_H_

#include <Art/Mcu.h>

#if defined(STM32F051)
#elif defined(__STM32F4XX__)
#	include <Art/Private/stm32/stm32f4/MatchChannel.h>
#	include <Art/Private/stm32/stm32f4/CaptureChannel.h>
#	include <Art/Private/stm32/stm32f4/PulseChannel.h>
#	include <Art/Private/stm32/stm32f4/StmTim2.h>
#	include <Art/Private/stm32/stm32f4/StmTim4.h>
#	include <Art/Private/stm32/stm32f4/StmTim9.h>
#elif defined(__LPC112X__)
	#include <Art/Private/lpc/lpc112x/Gpio-lpc112x.h>
#elif defined(__LPC17XX__)
	#include <Art/Private/lpc/lpc17/Pit-lpc17.h>
#elif defined(MSP430)
	#include <Art/Private/msp430/Gpio-msp430.h>
#elif defined(__CC2541__)
	#include <Art/Private/cc254x/Gpio-cc254x.h>
#endif



#endif /* SOURCE_ART_PIT_H_ */
