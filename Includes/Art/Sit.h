/*
 * Sit.h
 *
 *  Created on: Jul 5, 2015
 *      Author: denizcan
 */

#ifndef ART_SIT_H_
#define ART_SIT_H_

#include <Art/Types.h>

namespace Art
{

	typedef UInt Moment;

	namespace Sit
	{
		extern void reconfigure();
		extern Moment currentMoment();
		extern void setTarget(Moment moment);
		extern Int toJiffies(ShortL interval);
		extern Word compare(Moment l, Moment r);
		extern Moment squize(Moment moment);
		extern void processTick();
	};
}

#endif /* SOURCE_ART_PRIVATE_SIT_H_ */
