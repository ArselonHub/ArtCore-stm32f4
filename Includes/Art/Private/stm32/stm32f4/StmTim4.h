/*
 * StmTim4.h
 *
 *  Created on: Jan 18, 2017
 *      Author: denizcan
 */

#ifndef SOURCE_ART_PRIVATE_STM32_STM32F4_STMTIM4_H_
#define SOURCE_ART_PRIVATE_STM32_STM32F4_STMTIM4_H_

#include <Art/Private/stm32/stm32f4/StmTimA.h>

namespace Art
{
	namespace Private
	{
		extern "C" void TIM4_IRQHandler();

		class StmTim4 : public StmTimA
		{
		public:
			StmTim4();
			virtual ~StmTim4();

		protected:
			virtual Word openDevice();
			virtual Word closeDevice();

			friend void TIM4_IRQHandler();
		};
	}

	extern Private::StmTim4* tim4();

}

#endif /* SOURCE_ART_PRIVATE_STM32_STM32F4_StmTim4_H_ */
