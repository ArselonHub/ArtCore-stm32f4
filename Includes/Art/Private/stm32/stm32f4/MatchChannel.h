/*
 * PitChannel.h
 *
 *  Created on: Jan 19, 2017
 *      Author: denizcan
 */

#ifndef SOURCE_ART_PRIVATE_STM32_STM32F4_MATCHCHANNEL_H_
#define SOURCE_ART_PRIVATE_STM32_STM32F4_MATCHCHANNEL_H_

#include <Art/Private/stm32/stm32f4/PitChannelEx.h>

namespace Art
{
	enum MatchOutputMode
	{
		MatchOutputModeNone,
		MatchOutputModeSet,
		MatchOutputModeClear,
		MatchOutputModeToggle,
		MatchOutputModeForceCleared,
		MatchOutputModeForceSet,
	};

	class MatchChannel : public Private::PitChannelEx
	{
	public:
		void setValue(UWord value);
		Bool outputValue();
		MatchOutputMode outputMode();
		void setOutputValue(Bool value);
		void setOutputMode(MatchOutputMode value);
		void stepForward(UWord value);
		void stepAhead(UWord value);
	};

	inline void MatchChannel::setValue(UWord value)
	{
		((CompositeChannel*)this)->setValue(value);
	}

	inline void MatchChannel::setOutputValue(Bool value)
	{
		((CompositeChannel*)this)->setOutputValue(value);
	}

	inline void MatchChannel::setOutputMode(MatchOutputMode value)
	{
		((CompositeChannel*)this)->setOutputMode((CompositeOutputMode)value);
	}

	inline void MatchChannel::stepForward(UWord value)
	{
		((CompositeChannel*)this)->stepForward(value);
	}

	inline void MatchChannel::stepAhead(UWord value)
	{
		((CompositeChannel*)this)->stepAhead(value);
	}	

} /* namespace Art */

#endif /* SOURCE_ART_PRIVATE_STM32_STM32F4_PITCHANNEL_H_ */
