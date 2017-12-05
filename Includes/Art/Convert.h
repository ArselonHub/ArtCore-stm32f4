/*
 * Convert.h
 *
 *  Created on: 01 May 2014
 *      Author: denizcan
 */

#ifndef ART_CONVERT_H_
#define ART_CONVERT_H_

#include <Art/Types.h>

namespace Art
{
	namespace Convert
	{
		inline UShortL toUShort(void* b)
		{
			return *((UShort*)b);
		}

		inline UShortL toUShortAndStep(UByte*& b)
		{
			UShortL result = *((UShort*)b);
			b += sizeof(UShortL);
			return result;
		}

		inline UInt toUInt(void* b)
		{
			return *((UInt*)b);
		}

		inline Int toInt(void* b)
		{
			return *((Int*)b);
		}

		inline UByte* fromUShortL(UByte* b, UShortL value)
		{
			*((UShortL*)b) = value;
			return b + sizeof(UShortL);
		}
	}

} /* namespace Art */
#endif /* CONVERT_H_ */
