/*
 * Interrupts.h
 *
 *  Created on: 25 �ub 2015
 *      Author: denizcan
 */

#ifndef INTERRUPTS_H_
#define INTERRUPTS_H_

#include <Art/Gpio.h>

namespace Art
{
	typedef void (*InterruptVector)();
	extern InterruptVector usciaVector;
	extern InterruptVector timerA0V1Vector;
	extern InterruptVector port1Vector;
	extern void (*port2Vector)(UWord index);
}


#endif /* INTERRUPTS_H_ */
