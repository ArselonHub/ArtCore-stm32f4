/*
 * Clock.h
 *
 *  Created on: Jan 2, 2015
 *      Author: denizcan
 */

#ifndef ART_LPC_PMCC_H_
#define ART_LPC_PMCC_H_

#include <Art/Pmcc.h>

namespace Art
{
	struct UartDivisor
	{
		UByte	dll;
		UByte	dlm;
		UByte	divadd:4;
		UByte	divmul:4;
		UByte	div;
	};

}

#endif /* ART_LPC_CLOCK_H_ */
