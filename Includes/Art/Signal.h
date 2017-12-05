#ifndef ART_SIGNAL_H
#define ART_SIGNAL_H

#include <Art/Dispatcher.h>

namespace Art
{
	template <class T0=void, class T1=void, class T2=void>
	class Signal
	{
	};

	namespace Private
	{		
		struct SignalInfo
		{
			SignalInfo(Dispatcher* dispatcher, const void* id);

			Dispatcher*	dispatcher;
			UWord 		id;
		};

		class SignalBase
		{
		public:
			Bool isEmpty();
			void clear();

		protected:
			Dispatcher* m_dispatcher;
			UWord		m_id;
		};

		inline SignalInfo::SignalInfo(Dispatcher* dispatcher, const void* id)
		{
			this->dispatcher = dispatcher;
			this->id = (UWord) (id);
		}
	}
	
	template <>
	class Signal<> : public Private::SignalBase
	{
	public:
		Signal(const Private::SignalInfo info);
		void emit();
		void connect(void(*function)());

		template<class T>
		void connect(T* instance, void(T::*method)());
	};

	template <class T0>
	class Signal<T0> : public Private::SignalBase
	{
	public:
		Signal(Dispatcher* dispatcher, UWord id);
		Signal(const Private::SignalInfo info);

		void emit(T0 arg0);
		inline void connect(void(*function)(T0));
		
		template<class T>
		inline void connect(T* instance, void(T::*method)(T0));
	};

	template <class T0, class T1>
	class Signal<T0, T1> : public Private::SignalBase
	{
	public:
		Signal(const Private::SignalInfo info);

		void emit(T0 arg0, T1 arg1);
		void connect(void(*function)(T0, T1));
		
		template<class T>
		inline void connect(T* instance, void(T::*method)(T0, T1));
	};

	inline Signal<>::Signal(const Private::SignalInfo info)
	{
		m_dispatcher  = info.dispatcher;
		m_id = info.id;
	}

	inline void Signal<>::emit()
	{
		m_dispatcher->emit(m_id);
	}

	inline void Signal<>::connect(void(*function)())
	{
		m_dispatcher->connect(m_id, function);
	}

	template<class T>
	void Signal<>::connect(T* instance, void(T::*method)())
	{
		m_dispatcher->connect(m_id, instance, method);
	}

	template<class T0>
	inline Signal<T0>::Signal(Dispatcher* dispatcher, UWord id)
	{
		m_dispatcher = dispatcher;
		m_id = id;
	}

	template<class T0>
	inline Signal<T0>::Signal(const Private::SignalInfo info)
	{
		m_dispatcher = info.dispatcher;
		m_id = info.id;
	}

	template <class T0>
	void Signal<T0>::emit(T0 arg0)
	{
		m_dispatcher->emit(m_id, arg0);
	}

	template <class T0>
	void Signal<T0>::connect(void(*function)(T0))
	{
		m_dispatcher->connect(m_id, function);
	}

	template <class T0>
	template<class T>
	void Signal<T0>::connect(T* instance, void(T::*method)(T0))
	{
		m_dispatcher->connect(m_id, instance, method);
	}

	template<class T0, class T1>
	inline Signal<T0, T1>::Signal(const Private::SignalInfo info)
	{
		m_dispatcher = info.dispatcher;
		m_id = info.id;
	}

	template<class T0, class T1>
	void Signal<T0, T1>::connect(void(*function)(T0, T1))
	{
		m_dispatcher->connect(m_id, function);
	}

	template<class T0, class T1>
	template<class T>
	void Signal<T0, T1>::connect(T* instance, void(T::*method)(T0, T1))
	{
		m_dispatcher->connect(m_id, instance, method);
	}

}

#define SIGNAL { static const Byte state = 0; return ::Art::Private::SignalInfo(dispatcher(), &state); }

#endif
