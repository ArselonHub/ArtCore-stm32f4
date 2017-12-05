/*
 * PitChannelPort.h
 *
 *  Created on: May 10, 2017
 *      Author: denizcan
 */

#ifndef SOURCE_ART_PRIVATE_STM32_STM32F4_PITCHANNELPORT_H_
#define SOURCE_ART_PRIVATE_STM32_STM32F4_PITCHANNELPORT_H_

#include <Art/Private/stm32/stm32f4/CompositeChannel.h>

namespace Art
{
	namespace Private
	{
		class PitChannel
		{
		public:
			void enable();
			void disable();
			UWord value();
		};

		inline UWord PitChannel::value()
		{
			return ((CompositeChannel*)this)->value();
		}

		inline void PitChannel::enable()
		{
			((CompositeChannel*)this)->enable();
		}

		inline void PitChannel::disable()
		{
			((CompositeChannel*)this)->disable();
		}

	} /* namespace Private */
} /* namespace Art */

#endif /* SOURCE_ART_PRIVATE_STM32_STM32F4_PITCHANNELPORT_H_ */
