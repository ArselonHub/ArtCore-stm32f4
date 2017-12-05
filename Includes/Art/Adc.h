#ifndef ART_ADC_H
#define ART_ADC_H

#include <Art/Device.h>
#include <Art/Response.h>

namespace Art
{
	class AdcChannel;

	class Adc : public Device
	{
	public:
		virtual ~Adc();
		Word convert(AdcChannel* ch0);
		Word convert(AdcChannel* ch0, AdcChannel* ch1);
		Word convert(AdcChannel* ch0, AdcChannel* ch1, AdcChannel* ch2);
		Word convert(AdcChannel** channels);
		Word convert(AdcChannel** channels, Response* response);
	private:
		virtual Word convertChannels(AdcChannel** channels, Response* response) = 0;
		virtual Word valueOf(AdcChannel* channel) = 0;

		friend class AdcChannel;
	};

}

#if defined(__LPC175X__) || defined(__LPC176X__)
	#include <Art/lpc/lpc17/LpcAdc-lpc17.h>
#elif defined(__STM32F4XX__)
#	include  <Art/Private/stm32/stm32f4/StmAdc.h>
#endif


#endif
