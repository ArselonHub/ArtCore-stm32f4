/*
 * StmTim4.h
 *
 *  Created on: Jan 18, 2017
 *      Author: denizcan
 */

#ifndef ART_PRIVATE_STM32_STM32F4_STMTIM2_H_
#define ART_PRIVATE_STM32_STM32F4_STMTIM2_H_

#include <Art/Private/stm32/stm32f4/StmTimA.h>

namespace Art
{
	namespace Private
	{
		extern "C" void TIM2_IRQHandler();

		class StmTim2 : public StmTimA
		{
		public:
			StmTim2();
			virtual ~StmTim2();
		protected:
			virtual Word openDevice();
			virtual Word closeDevice();

			friend void TIM2_IRQHandler();

		};
	}

	extern Private::StmTim2* tim2();
}

#endif /* SOURCE_ART_PRIVATE_STM32_STM32F4_StmTim4_H_ */
