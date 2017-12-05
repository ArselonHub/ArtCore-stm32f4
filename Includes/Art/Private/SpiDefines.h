/*
 * SpiDefines.h
 *
 *  Created on: May 19, 2016
 *      Author: denizcan
 */

#ifndef ART_PRIVATE_SPIDEFINES_H_
#define ART_PRIVATE_SPIDEFINES_H_

#include <Art/Types.h>

namespace Art
{
	enum SpiSpeed
	{
		SpiSpeedMax1MHz,
		SpiSpeedMax2MHz,
		SpiSpeedMax4MHz,
		SpiSpeedMax8MHz,
		SpiSpeedMax12MHz,
		SpiSpeedMax16MHz,
		SpiSpeedMax24Mhz,
		SpiSpeedMax32MHz,
		SpiSpeedMax48Mhz,
		SpiSpeedMax64Mhz,
		SpiSpeedMax96MHz
	};

	enum SpiPolarity
	{
		SpiPolarityLow,
		SpiPolarityHigh
	};

	enum SpiPhase
	{
		SpiPhaseCaptureOnFirstEdge,
		SpiPhaseCaptureOnSecondEdge
	};


}

#endif /* SOURCE_ART_PRIVATE_SPIDEFINES_H_ */
