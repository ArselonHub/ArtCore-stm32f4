/*
 * Allocator.h
 *
 *  Created on: Oct 18, 2016
 *      Author: denizcan
 */

#ifndef ART_ALLOCATOR_H_
#define ART_ALLOCATOR_H_

#include <Art/Types.h>

namespace Art
{

	class Allocator
	{
	public:
		virtual void* allocate(UWord length) = 0;
		virtual void* reallocate(void* pointer, UWord length) = 0;
		virtual void free(void* pointer) = 0;
	};

} /* namespace Art */

#endif /* SOURCE_ART_ALLOCATOR_H_ */
