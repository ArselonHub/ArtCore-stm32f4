#ifndef ART_LPC_LPCADC_LPC17_H
#define ART_LPC_LPCADC_LPC17_H

#include <Art/Adc.h>
#include <Art/lpc/lpc17/LpcAdcChannel-lpc17.h>

namespace Art
{		
	class LpcAdc
	{
	public:
		LpcAdc();
		Result open();
		Result close();

		//LpcAdcChannel channel0;
		//LpcAdcChannel channel1;
		LpcAdcChannel channel2;
		LpcAdcChannel channel3;
		LpcAdcChannel channel4;
		LpcAdcChannel channel5;
		LpcAdcChannel channel6;
		LpcAdcChannel channel7;
	
	private:
		static const LpcAdcChannel::ChannelData channelData[];		
	};
	
	extern LpcAdc adc;
}


#endif
