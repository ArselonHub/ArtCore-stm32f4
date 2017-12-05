/*
 * MatchChannel.h
 *
 *  Created on: Aug 12, 2017
 *      Author: denizcan
 */

#ifndef SOURCE_ART_MATCHCHANNEL_H_
#define SOURCE_ART_MATCHCHANNEL_H_

#include <Art/Types.h>

#if defined(STM32F051)
#elif defined(__STM32F4XX__)
#	include <Art/Private/stm32/stm32f4/MatchChannel.h>
#elif defined(__LPC112X__)
#elif defined(__LPC17XX__)
#elif defined(MSP430)
#elif defined(__CC2541__)
#endif



#endif /* SOURCE_ART_MATCHCHANNEL_H_ */
