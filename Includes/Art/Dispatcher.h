/*
 * Dispatcher.h
 *
 *  Created on: Jul 3, 2017
 *      Author: denizcan
 */

#ifndef ART_DISPATCHER_H_
#define ART_DISPATCHER_H_

#include <Art/Types.h>
#include <Art/Utility.h>

namespace Art
{

	class Dispatcher
	{
	public:
		Dispatcher();
		~Dispatcher();

		void connect(UWord id, void(*function)());

		template<class A0>
		void connect(UWord id, void(*function)(A0));

		template<class A0, class A1>
		void connect(UWord id, void(*function)(A0, A1));

		template<class T>
		void connect(UWord id, T* instance, void(T::*method)());

		template<class T, class A0>
		void connect(UWord id, T* instance, void(T::*method)(A0));

		template<class T, class A0, class A1>
		void connect(UWord id, T* instance, void(T::*method)(A0, A1));

		void emit(UWord id);

		template <class T0>
		void emit(UWord id, T0 arg0);

		template <class T0, class T1>
		void emit(UWord id, T0 arg0, T1 arg1);

		Bool hasSlot(UWord id);
		void clear(UWord id);

	private:
		void emitImp(UWord id, UWord arg0);
		void emitImp(UWord id, UWord arg0, UWord arg1);

		void connectFunction(UWord id, void* function);
		void connectMethod(UWord id, void* instance, void* function);

		struct	Slot
		{
			Slot(Slot* next, UWord id, void*  function, void* instance);
			Slot*	next;
			UWord	id;
			void* 	instance;
			void* 	function;
		};

		Slot*	m_slots;
	};

	inline void Dispatcher::connect(UWord id, void (*function)())
	{
		connectFunction(id, getFunctionAddress(function));
	}

	template<class A0>
	inline void Dispatcher::connect(UWord id, void (*function)(A0))
	{
		connectFunction(id, getFunctionAddress(function));
	}

	template<class A0, class A1>
	inline void Dispatcher::connect(UWord id, void (*function)(A0, A1))
	{
		connectFunction(id, getFunctionAddress(function));
	}

	template<class T>
	inline void Dispatcher::connect(UWord id, T* instance, void (T::*method)())
	{
		connectMethod(id, instance, getMethodAddress(method));
	}

	template<class T, class A0>
	inline void Dispatcher::connect(UWord id, T* instance, void (T::*method)(A0))
	{
		connectMethod(id, instance, getMethodAddress(method));
	}


	template<class T, class A0, class A1>
	inline void Dispatcher::connect(UWord id, T* instance, void (T::*method)(A0, A1))
	{
		connectMethod(id, instance, getMethodAddress(method));
	}

	template<class T0>
	inline void Dispatcher::emit(UWord id, T0 arg0)
	{
		emitImp(id, (UWord)arg0);
	}

	template<class T0, class T1>
	inline void Dispatcher::emit(UWord id, T0 arg0, T1 arg1)
	{
		emitImp(id, (UWord)arg0, (UWord)arg1);
	}


} /* namespace Art */



#endif /* SOURCE_ART_DISPATCHER_H_ */
