/*
 * Svc-msp430.h
 *
 *  Created on: 10 Mar 2015
 *      Author: denizcan
 */

#ifndef ART_PRIVATE_MSP430_SVC_MSP430_H_
#define ART_PRIVATE_MSP430_SVC_MSP430_H_

#include <Art/Types.h>

namespace Art
{
	class Svc;

	namespace Private
	{
		class Svc
		{
		private:
			static UWord call(void* function);
			static UWord call(void* arg0, void* function);
			static UWord call(void* arg0, void* arg1, void* function);
			static UWord call(void* arg0, void* arg1, void* arg2, void* function);
			static void exitSvc();

			friend class ::Art::Svc;
		};
	}
}
#endif /* SVC_MSP430_H_ */
