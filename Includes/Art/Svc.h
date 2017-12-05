/*
 * Svc.h
 *
 *  Created on: 4 Oca 2015
 *      Author: denizcan
 */

#ifndef ART_SVC_H_
#define ART_SVC_H_

#include <Art/BasicQueue.h>
#include <Art/Mcu.h>
#include <Art/Task.h>

namespace Art
{
	class Svc
	{
	public:
		static void enqueueIrq(Task* task);
		static void enqueueSvc(Task* task);

		template <class A0>
		static void call(void(*f)(A0), A0 a0);

		template <class R, class A0>
		static R call(R(*f)(A0), A0 a0);

		template <class A0, class A1>
		static void call(void(*f)(A0, A1), A0 a0, A1 a1);

		template <class R, class A0, class A1>
		static R call(R(*f)(A0, A1), A0 a0, A1 a1);

		template <class A0, class A1, class A2>
		static void call(void(*f)(A0, A1, A2), A0 a0, A1 a1, A2 a2);

		template <class R, class A0, class A1, class A2>
		static R call(R(*f)(A0, A1, A2), A0 a0, A1 a1, A2 a2);

		template <class A0, class A1, class A2, class A3>
		static void call(void(*f)(A0, A1, A2, A3), A0 a0, A1 a1, A2 a2, A3);

		template <class R, class A0, class A1, class A2, class A3>
		static R call(R(*f)(A0, A1, A2, A3), A0 a0, A1 a1, A2 a2, A3 a3);
	protected:
		static void executeSvc();
		static BasicQueue<Task> tasks;
		static Bool active;
	};

}


#if defined(CORTEX_CM0) || defined(CORTEX_CM3) || defined(CORTEX_CM4)
	#if defined(__GNUC__)
		#include <Art/Private/cm/Svc-cm-gnuc.h>
	#else
		#include <Art/Private/cm/Svc-cm-keil.h>
	#endif
#elif defined(MSP430)
	#include <Art/Private/msp430/Svc-msp430.h>
#elif defined(__CC2541__)


#endif

#endif /* SOURCE_ART_SVC_H_ */
