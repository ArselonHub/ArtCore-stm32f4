/*
 * StmTimA.h
 *
 *  Created on: Aug 12, 2017
 *      Author: denizcan
 */

#ifndef ART_PRIVATE_STM32_STM32F4_STMTIMA_H_
#define ART_PRIVATE_STM32_STM32F4_STMTIMA_H_

#include <Art/Private/stm32/stm32f4/StmTim.h>

namespace Art
{
	class StmTimA : public StmTim
	{
	public:
		StmTimA(const void* d);
		virtual ~StmTimA();

		Private::PitChannelStub& channel1();
		Private::PitChannelStub& channel2();
		Private::PitChannelStub& channel3();
		Private::PitChannelStub& channel4();
	};

} /* namespace Art */

#endif /* SOURCE_ART_PRIVATE_STM32_STM32F4_STMTIMA_H_ */
