#ifndef ART_PRIVATE_CM_GNUC_H
#define ART_PRIVATE_CM_GNUC_H

namespace Art
{
	inline void Svc::enqueueSvc(Task* task)
	{
		enqueueIrq(task);
	}

	template<class A0>
	inline void Svc::call(void (*f)(A0), A0 a0)
	{
		__asm volatile
		(
			"	movs	r12,%0\n"
			"	movs	r0,%1\n"
			"	svc		0\n"
			: : "r" (f), "r" (a0) : "r0", "r12", "memory"
		);
	}

	template <class R, class A0>
	inline R Svc::call(R(*f)(A0), A0 a0)
	{
		UWord result;
		__asm volatile
		(
			"	movs	r12,%1\n"
			"	movs	r0,%2\n"
			"	svc		0\n"
			"	movs	%0, r0"
			: "=r"(result) : "r" (f), "r" (a0) : "r0", "r12", "memory"
		);
		return (R)result;
	}

	template <class A0, class A1>
	inline void Svc::call(void(*f)(A0, A1), A0 a0, A1 a1)
	{
		__asm volatile
		(
			"	movs	r12,%0\n"
			"	movs	r0,%1\n"
			"	movs	r1,%2\n"
			"	svc		0\n"
			: : "r"(f), "r"(a0), "r"(a1) : "r0", "r1", "r12", "memory"
		);
	}

	template <class R, class A0, class A1>
	inline R Svc::call(R(*f)(A0, A1), A0 a0, A1 a1)
	{
		UWord result;
		__asm volatile
		(
			"	movs	r12,%1\n"
			"	movs	r0,%2\n"
			"	movs	r1,%3\n"
			"	svc		0\n"
			"	movs	%0, r0"
			: "=r"(result)
			: "r"(f), "r"(a0), "r"(a1)
			: "r0", "r1", "r12", "memory"
		);
		return (R)result;
	}

	template <class A0, class A1, class A2>
	inline void Svc::call(void(*f)(A0, A1, A2), A0 a0, A1 a1, A2 a2)
	{
		__asm volatile
		(
			"	movs	r12,%0\n"
			"	movs	r0,%1\n"
			"	movs	r1,%2\n"
			"	movs	r2,%3\n"
			"	svc		0\n"
			: : "r"(f), "r"(a0), "r"(a1), "r"(a2)
			: "r0", "r1", "r2", "r12", "memory"
		);
	}

	template <class R, class A0, class A1, class A2>
	inline R Svc::call(R(*f)(A0, A1, A2), A0 a0, A1 a1, A2 a2)
	{
		UWord result;
		__asm volatile
		(
			"	movs	r12,%1\n"
			"	movs	r0,%2\n"
			"	movs	r1,%3\n"
			"	movs	r2,%4\n"
			"	svc		0\n"
			"	movs	%0, r0"
			: "=r"(result) : "r"(f), "r"(a0), "r"(a1), "r"(a2)
			: "r0", "r1", "r2", "r12", "memory"
		);
		return (R)result;
	}

	template <class A0, class A1, class A2, class A3>
	inline void Svc::call(void(*f)(A0, A1, A2, A3), A0 a0, A1 a1, A2 a2, A3 a3)
	{
		__asm volatile
		(
			"	movs	r12,%0\n"
			"	movs	r0,%1\n"
			"	movs	r1,%2\n"
			"	movs	r2,%3\n"
			"	movs	r3,%3\n"
			"	svc		0\n"
			: : "r"(f), "r"(a0), "r"(a1), "r"(a2), "r"(a3)
			: "r0", "r1", "r2", "r3", "r12", "memory"
		);
	}


	template <class R, class A0, class A1, class A2, class A3>
	inline R Svc::call(R(*f)(A0, A1, A2, A3), A0 a0, A1 a1, A2 a2, A3 a3)
	{
		UWord result;
		__asm volatile
		(
			"	movs	r12,%1\n"
			"	movs	r0,%2\n"
			"	movs	r1,%3\n"
			"	movs	r2,%4\n"
			"	movs	r3,%5\n"
			"	svc		0\n"
			"	movs	%0, r0"
			: "=r"(result) : "r"(f), "r"(a0), "r"(a1), "r"(a2), "r"(a3)
			: "r0", "r1", "r2", "r3", "r12", "memory"
		);
		return (R)result;
	}
}

#endif
