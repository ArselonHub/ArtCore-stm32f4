/*
 * StmTim9.h
 *
 *  Created on: Jan 18, 2017
 *      Author: denizcan
 */

#ifndef SOURCE_ART_PRIVATE_STM32_STM32F4_STMTIM9_H_
#define SOURCE_ART_PRIVATE_STM32_STM32F4_STMTIM9_H_

#include <Art/Private/stm32/stm32f4/StmTim.h>

namespace Art
{
	namespace Private
	{
		extern "C" void TIM1_BRK_TIM9_IRQHandler();

		class StmTim9 : public StmTim
		{
		public:
			StmTim9();
			virtual ~StmTim9();

			Private::PitChannelStub& channel1();
			Private::PitChannelStub& channel2();

		protected:
			virtual Word enableDeviceClock();
			virtual Word disableDeviceClock();

			friend void TIM1_BRK_TIM9_IRQHandler();

		};
	}

	extern Private::StmTim9* tim9();

}

#endif /* SOURCE_ART_PRIVATE_STM32_STM32F4_STMTIM9_H_ */
