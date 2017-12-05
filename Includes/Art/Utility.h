/*
 * Utility.h
 *
 *  Created on: 31 Mar 2014
 *      Author: denizcan
 */

#ifndef ART_UTILITY_H_
#define ART_UTILITY_H_

#include <Art/Types.h>

namespace Art
{
	template <class R>
	inline void* getFunctionAddress(R(*function)())
	{
		return *((void**)&function);
	}

	template <class R, class A0>
	inline void* getFunctionAddress(R(*function)(A0))
	{
		return *((void**)&function);
	}

	template <class R, class A0, class A1>
	inline void* getFunctionAddress(R(*function)(A0, A1))
	{
		return *((void**)&function);
	}

	template <class R, class A0, class A1, class A2>
	static inline void* getFunctionAddress(R(*function)(A0, A1, A2))
	{
		return *((void**)&function);
	}

	template <class R, class T>
	inline void* getMethodAddress(R(T::*method)())
	{				
		return *((UWord**)&method);
	}

	template <class R, class T, class A0>
	inline void* getMethodAddress(R(T::*method)(A0))
	{
		return *((UWord**)&method);
	}

	template <class R, class T, class A0, class A1>
	inline void* getMethodAddress(R(T::*method)(A0, A1))
	{
		return *((UWord**)&method);
	}

	template <class R, class T, class A0, class A1, class A2>
	inline void* getMethodAddress(R(T::*method)(A0, A1, A2))
	{
		return *((UWord**)&method);
	}

	extern "C" Word mallocSize(void* ptr);
}


#endif /* UTILITY_H_ */
