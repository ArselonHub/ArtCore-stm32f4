/*
 * GlobalSection.h
 *
 *  Created on: 28 Oca 2014
 *      Author: denizcan
 */

#ifndef ART_GLOBALSECTION_H_
#define ART_GLOBALSECTION_H_

#include <Art/Mcu.h>

#if defined(CORTEX_CM0) || defined(CORTEX_CM3)
	#include <Art/Private/cm/GlobalSection-cm.h>
#elif defined(MSP430)
	#include <Art/Private/msp430/GlobalSection-msp430.h>
#elif defined(__CC2541__)
#	include <Art/Private/cc254x/GlobalSection-cc254x.h>
#endif


#endif /* GLOBALSECTION_H_ */
