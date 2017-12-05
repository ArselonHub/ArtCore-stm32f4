/*
 * BasicAllocator.h
 *
 *  Created on: Oct 19, 2016
 *      Author: denizcan
 */

#ifndef SOURCE_ART_BASICALLOCATOR_H_
#define SOURCE_ART_BASICALLOCATOR_H_

#include <Art/Allocator.h>

namespace Art
{

	class BasicAllocator : public Allocator
	{
	public:
		virtual void* allocate(UWord length) ;
		virtual void* reallocate(void* pointer, UWord length);
		virtual void free(void* pointer);
	protected:
		void configure(void* head, void* tail);
	private:
		UByte*	m_head;
		UByte*	m_tail;
	};

} /* namespace Art */

#endif /* SOURCE_ART_BASICALLOCATOR_H_ */
