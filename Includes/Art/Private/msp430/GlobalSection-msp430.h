/*
 * GlobalSection-msp430.h
 *
 *  Created on: 28 Oca 2014
 *      Author: denizcan
 */

#ifndef ART_GLOBALSECTION_MSP430_H_
#define ART_GLOBALSECTION_MSP430_H_

#include "../../Mcu.h"

namespace Art
{
	class GlobalSection
	{
	private:
		UWord savedValue;
	public:
		GlobalSection()
		{
			savedValue = __get_SR_register() & GIE;
		}

		void enter()
		{
			__bic_SR_register(GIE);
			__no_operation();
		}

		void exit()
		{
			UWord sr = savedValue;
			__no_operation();
			__bis_SR_register(sr);
		}
	};
}

#endif /* GLOBALSECTION_MSP430_H_ */
