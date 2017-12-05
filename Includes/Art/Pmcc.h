/*
 * Pmcc.h
 * Power Management and Clock Control
 *
 *  Created on: 30 Ara 2014
 *      Author: denizcan
 */

#ifndef ART_PMCC_H_
#define ART_PMCC_H_

#include <Art/Types.h>

#if defined(__LPC112X__)
	#include <Art/Private/lpc/lpc112x/Pmcc-lpc112x.h>
#elif defined(__LPC17XX__)
	#include <Art/Private/lpc/lpc17/Pmcc-lpc17.h>
#elif defined(STM32F051)
	#include <Art/stm32/stm32f0/System-stm32f0.h>
#elif defined(__STM32F4XX__)
	#include <Art/Private/stm32/stm32f4/Pmcc-stm32f4.h>
#elif defined(__CC430F5137__)
	#include <Art/Private/msp430/Clock-cc430.h>
#elif defined(__CC2541__)
#   include <Art/Private/cc254x/Clock-cc254x.h>
#endif

#endif /* CLOCK_H_ */
