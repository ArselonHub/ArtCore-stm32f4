/*
 * ChannelStub.h
 *
 *  Created on: Jan 22, 2017
 *      Author: denizcan
 */

#ifndef SOURCE_ART_PRIVATE_STM32_STM32F4_PITCHANNELSTUB_H_
#define SOURCE_ART_PRIVATE_STM32_STM32F4_PITCHANNELSTUB_H_

#include <Art/Private/stm32/stm32f4/CompositeChannel.h>

namespace Art
{
	namespace Private
	{
		class PitChannelStub
		{
		public:
			CompositeChannel* operator ->() const;
			operator CaptureChannel*() const;
			operator MatchChannel*() const;
			operator PulseChannel*() const;
		};

		inline CompositeChannel* PitChannelStub::operator ->() const
		{
			return (CompositeChannel*)this;
		}

		inline PitChannelStub::operator CaptureChannel*() const
		{
			return (*this)->asCaptureChannel();
		}

		inline PitChannelStub::operator MatchChannel*() const
		{
			return (*this)->asMatchChannel();
		}

		inline PitChannelStub::operator PulseChannel*() const
		{
			return (*this)->asPulseChannel();
		}
	} /* namespace Private */
} /* namespace Art */

#endif /* SOURCE_ART_PRIVATE_STM32_STM32F4_PITCHANNELSTUB_H_ */
