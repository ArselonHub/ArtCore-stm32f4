#ifndef ART_CM_CORE_CM_H
#define ART_CM_CORE_CM_H

namespace Art
{
	template <class A0>
	inline void Svc::call(void(*f)(A0), A0 a0)
	{
		extern UWord __svc_indirect(0) _call(UWord function, UWord param0);
		_call((UWord)f, (UWord)a0);
	}

	template <class R, class A0>
	inline R Svc::call(R(*f)(A0), A0 a0)
	{
		extern UWord __svc_indirect(0) _call(UWord function, UWord param0);
		return (R)_call((UWord)f, (UWord)a0);
	}
	
	template <class A0, class A1>
	inline void Svc::call(void(*f)(A0, A1), A0 a0, A1 a1)
	{
		extern UWord __svc_indirect(0) _call(UWord function, UWord param0, UWord param1);
		_call((UWord)f, (UWord)a0, (UWord)a1);
	}

	template <class R, class A0, class A1>
	inline R Svc::call(R(*f)(A0, A1), A0 a0, A1 a1)
	{
		extern UWord __svc_indirect(0) _call(UWord function, UWord param0, UWord param1);
		return (R)_call((UWord)f, (UWord)a0, (UWord)a1);
	}

	template <class A0, class A1, class A2>
	inline void Svc::call(void(*f)(A0, A1, A2), A0 a0, A1 a1, A2 a2)
	{
		extern UWord __svc_indirect(0) _call(UWord function, UWord param0, UWord param1, UWord param2);
		_call((UWord)f, (UWord)a0, (UWord)a1, (UWord)a2);
	}

	template <class R, class A0, class A1, class A2>
	inline R Svc::call(R(*f)(A0, A1, A2), A0 a0, A1 a1, A2 a2)
	{
		extern UWord __svc_indirect(0) _call(UWord function, UWord param0, UWord param1, UWord param2);
		return (R)_call((UWord)f, (UWord)a0, (UWord)a1, (UWord)a2);
	}
	
	/*
	template <class F, class A0, class A1, class A2>
	inline UWord Svc::call(F f, A0 a0, A1 a1, A2 a2)
	{
		extern UWord __svc_indirect(0) _call(UWord function, UWord param0, UWord param1, UWord param2);
		return _call((UWord)f, (UWord)a0, (UWord)a1, (UWord)a2);
	}

	template <class F, class A0, class A1, class A2, class A3>
	inline UWord Svc::call(F f, A0 a0, A1 a1, A2 a2, A3 a3)
	{
		extern UWord __svc_indirect(0) _call(UWord function, UWord param0, UWord param1, UWord param2, UWord param3);
		return _call((UWord)f, (UWord)a0, (UWord)a1, (UWord)a2, (UWord)a3);
	}
	*/
	
}

#endif
