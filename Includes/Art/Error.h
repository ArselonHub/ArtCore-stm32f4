/*
 * Error.h
 *
 *  Created on: 4 Oca 2015
 *      Author: denizcan
 */

#ifndef ART_ERROR_H_
#define ART_ERROR_H_

#include <Art/Types.h>

namespace Art
{
	extern void handleCriticalError();

	inline void checkCritical(ShortL result)
	{
		if (result < 0)
			handleCriticalError();
	}

	inline void assureCritical(Word result)
	{
		if (result == 0)
			handleCriticalError();
	}
}

#endif /* SOURCE_ART_ERROR_H_ */
