/*
 * Callback.h
 *
 *  Created on: 22 May 2015
 *      Author: denizcan
 */

#ifndef ART_CALLBACK_H_
#define ART_CALLBACK_H_

#include <Art/Types.h>
#include <Art/Utility.h>
#include <Art/Event.h>

namespace Art
{
	namespace Private
	{
		class CallbackBase
		{
		public:
			CallbackBase();
			CallbackBase(Event* event);
			CallbackBase(void* function);
			CallbackBase(void* instance, void* function);
			Bool isEmpty();
			Bool isAssigned();

		protected:
			void assignTarget(void* function);
			void assignTarget(void* instance, void* function);

			void callTarget() const;
			void callTarget(UWord arg0) const;
			void callTarget(UWord arg0, UWord arg1) const;

		private:
			void* m_function;
			void* m_instance;

			static void doNothing();
			friend class CallbackAdapter;
		};

		class CallbackAdapter
		{
		public:
			static Event* eventReferenceOf(CallbackBase* callback);
		};

		inline CallbackBase::CallbackBase()
		{
			m_instance = 0;
			m_function = 0;
		}

		inline CallbackBase::CallbackBase(void* function)
		{
			m_function = function;
			m_instance = 0;
		}

		inline CallbackBase::CallbackBase(void* instance, void* function)
		{
			m_instance = instance;
			m_function = function;
		}

		inline CallbackBase::CallbackBase(Event* event)
		{
			m_instance = event;
			m_function = getMethodAddress(&Event::set);
		}

		inline void CallbackBase::assignTarget(void* function)
		{
			m_function = function;
			m_instance = 0;
		}

		inline Bool CallbackBase::isAssigned()
		{
			return m_function != getFunctionAddress(&doNothing);
		}

		inline Bool CallbackBase::isEmpty()
		{
			return m_function == getFunctionAddress(&doNothing);
		}

		inline void CallbackBase::assignTarget(void* instance, void* function)
		{
			m_instance = instance;
			m_function = function;
		}
	}

	template <class T0=void, class A1=void, class A2=void>
	class Callback;

	template <>
	class Callback<> : public Private::CallbackBase
	{
	public:
		Callback();
		Callback(Event* event);
		Callback(void(*function)());

		template <class T>
		Callback(T* instance, void (T::*method)());

		void assign(void (*function)());

		template <class T>
		void assign(T* instance, void (T::*method)());

		void call() const;
	private:
	};

	template <class T0>
	class Callback<T0> : public Private::CallbackBase
	{
	public:
		Callback();
		Callback(Event* event);
		Callback(void (*function)(T0));

		template <class T>
		Callback(T* instance, void (T::*method)(T0));

		void assign(void(*function)(T0));

		template <class T>
		void assign(T* instance, void (T::*method)(T0));

		void call(T0 arg0) const;
	};

	inline Callback<>::Callback()
	{
	}

	inline Callback<>::Callback(Event* event)
		: CallbackBase(event)
	{
	}

	inline Callback<>::Callback(void(*function)())
			: CallbackBase(getFunctionAddress(function))
	{
	}

	template<class T>
	inline Callback<>::Callback(T* instance, void (T::*method)())
		: CallbackBase(instance, getMethodAddress(method))
	{

	}

	inline void Callback<>::assign(void (*function)())
	{
		assignTarget(getFunctionAddress(function));
	}

	template<class T>
	inline void Callback<>::assign(T* instance, void (T::*method)())
	{
		assignTarget(instance, getMethodAddress(method));
	}

	inline void Callback<>::call() const
	{
		callTarget();
	}

	template<class T0>
	inline Callback<T0>::Callback()
	{
	}

	template<class T0>
	inline Callback<T0>::Callback(void (*function)(T0))
		: CallbackBase(getFunctionAddress(function))
	{
	}

	template<class T0>
	template<class T>
	inline Callback<T0>::Callback(T* instance, void (T::*method)(T0))
		: CallbackBase(instance, getMethodAddress(method))
	{
	}

	template<class T0>
	void Callback<T0>::assign(void(*function)(T0))
	{
		assignTarget(getFunctionAddress(function));
	}

	template<class T0>
	template<class T>
	inline void Callback<T0>::assign(T* instance, void (T::*method)(T0))
	{
		assignTarget(instance, getMethodAddress(method));
	}

	template<class T0>
	inline Callback<T0>::Callback(Event* event)
		: CallbackBase(event)
	{
	}

	template<class T0>
	void Callback<T0>::call(T0 arg0) const
	{
		callTarget((UWord)arg0);
	}

} /* namespace Art */

#endif /* ART_CALLBACK_H_ */
