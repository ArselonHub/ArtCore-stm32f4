/*
 * PitChannel.h
 *
 *  Created on: Jan 19, 2017
 *      Author: denizcan
 */

#ifndef ART_PRIVATE_STM32_STM32F4_PULSECHANNEL_H_
#define ART_PRIVATE_STM32_STM32F4_PULSECHANNEL_H_

#include <Art/Private/stm32/stm32f4/PitChannel.h>

namespace Art
{
	enum PulseMode
	{
		PulseModeStartActive = (6 << 4),
		PulseModeStartInactive = (7 << 4)
	};

	class PulseChannel : public Private::PitChannel
	{
	public:
		void setValue(UWord value);
		void latch();
		void latchAll();
		PulseMode mode();
		void setMode(PulseMode value);
	};

	inline void PulseChannel::setValue(UWord value)
	{
		((CompositeChannel*)this)->setValue(value);
	}

} /* namespace Art */

#endif /* SOURCE_ART_PRIVATE_STM32_STM32F4_PITCHANNEL_H_ */
