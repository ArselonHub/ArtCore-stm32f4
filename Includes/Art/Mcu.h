/******************************************************************************
	in.h, input header file of all Armin library. This file decides defines
	specific to platform and includes types to implement types for that 
	platform, then includes extra defines depending on the platform. 
	Very very "core" definitions of Armin..
 ******************************************************************************/
 
#ifndef ART_MCU_H
#define ART_MCU_H

#include <Art/Types.h>

#if defined(__STM32F4XX__)
#	include <Art/Private/stm32/stm32f4/Mcu-stm32f4.h>
#elif defined(__STM32F0XX__)
#	include <STM32F0xx.h>
#	include <core_cm0.h>
#	include <Art/stm32/stm32f0/mcu-stm32f0.h>
#elif defined(__LPC112X__)
#	include <Art/Private/lpc/lpc112x/Mcu-lpc112x.h>
#elif defined(__LPC17XX__)
#	include <Art/Private/lpc/Mcu-lpc17.h>
#elif defined(MSP430)
#	include <cc430x513x.h>
#	include <Art/Private/msp430/mcu-msp430.h>
#elif defined(ATMEGA)
#elif defined(__CC2541__)
#	include <ioCC2541.h>
#   include <Art/Private/cc254x/Mcu-cc254x.h>
#endif

#if defined(CORTEX_CM0) || defined(CORTEX_CM3)
#	include <Art/Private/cm/Mcu-cm.h>
#endif

#endif
