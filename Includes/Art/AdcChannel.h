/*
 * AdcChannel.h
 *
 *  Created on: Jul 11, 2017
 *      Author: denizcan
 */

#ifndef ART_ADCCHANNEL_H_
#define ART_ADCCHANNEL_H_

#include <Art/Types.h>

namespace Art
{
	class Adc;

	class AdcChannel
	{
	public:
		AdcChannel(const void* d);
		Word convert();
		Word value();
		Adc* adc();

	protected:
		void*	m_d;
	};

	inline AdcChannel::AdcChannel(const void* d)
	{
		m_d = (void*)d;
	}

	inline Adc* AdcChannel::adc()
	{
		return *((Adc**)m_d);
	}

} /* namespace Art */

#if defined(__LPC175X__) || defined(__LPC176X__)
	#include <Art/lpc/lpc17/LpcAdc-lpc17.h>
#elif defined(__STM32F4XX__)
#	include  <Art/Private/stm32/stm32f4/StmAdcChannel.h>
#endif

#endif /* SOURCE_ART_ADCCHANNEL_H_ */
