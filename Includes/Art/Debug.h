/*
 * Debug.h
 *
 *  Created on: 05 Mar 2014
 *      Author: denizcan
 */

#ifndef ART_DEBUG_H_
#define ART_DEBUG_H_

#include <Art/StreamLog.h>
#include <Art/Types.h>

namespace Art
{
	extern StreamLog* debug();
	extern void debug(const String& s);
	extern void debug(const Expression& e);
} /* namespace Art */
#endif /* DEBUG_H_ */
