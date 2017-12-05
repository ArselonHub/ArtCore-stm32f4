/*
 * CapturePort.h
 *
 *  Created on: Jan 21, 2017
 *      Author: denizcan
 */

#ifndef SOURCE_ART_PRIVATE_STM32_STM32F4_CAPTURECHANNEL_H_
#define SOURCE_ART_PRIVATE_STM32_STM32F4_CAPTURECHANNEL_H_

#include <Art/Private/stm32/stm32f4/PitChannelEx.h>

namespace Art
{
	class CaptureChannel : public Private::PitChannelEx
	{
	public:
		CaptureEdge edge();
		CaptureSource source();
		void setEdge(CaptureEdge value);
		void setSource(CaptureSource value);
	};

	inline CaptureEdge CaptureChannel::edge()
	{
		return ((CompositeChannel*)this)->captureEdge();
	}

	inline CaptureSource CaptureChannel::source()
	{
		return ((CompositeChannel*)this)->captureSource();
	}

	inline void CaptureChannel::setEdge(CaptureEdge value)
	{
		((CompositeChannel*)this)->setCaptureEdge(value);
	}

	inline void CaptureChannel::setSource(CaptureSource value)
	{
		((CompositeChannel*)this)->setCaptureSource(value);
	}

} /* namespace Art */

#endif /* SOURCE_ART_PRIVATE_STM32_STM32F4_CAPTURECHANNEL_H_ */
