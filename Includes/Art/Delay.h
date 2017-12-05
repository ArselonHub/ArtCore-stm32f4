/*
 * Delay.h
 *
 *  Created on: Jan 2, 2015
 *      Author: denizcan
 */

#ifndef ART_DELAY_H_
#define ART_DELAY_H_

#include <Art/Types.h>
#include <Art/Thread.h>

namespace Art
{
	extern void loopFor(UWord n);
	extern void loopUs(UShortL value);
	extern void loopMs(UShortL value);
	extern UInt ticks();
}

#endif /* SOURCE_ART_DELAY_H_ */
