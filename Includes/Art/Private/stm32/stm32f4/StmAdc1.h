/*
 * StmAdc1.h
 *
 *  Created on: Jul 2, 2017
 *      Author: denizcan
 */

#ifndef ART_PRIVATE_STM32_STM32F4_STMADC1_H_
#define ART_PRIVATE_STM32_STM32F4_STMADC1_H_

#include <Art/Private/stm32/stm32f4/StmAdc.h>

namespace Art
{
	namespace Private
	{
		class StmAdc1 : public StmAdc
		{
		public:
			StmAdc1();
			virtual ~StmAdc1();


		private:
			virtual Word openDevice();
			virtual Word closeDevice();

		};
	} /* namespace Private */

	extern Private::StmAdc1* adc1();
} /* namespace Art */

#endif /* SOURCE_ART_PRIVATE_STM32_STM32F4_STMADC1_H_ */
