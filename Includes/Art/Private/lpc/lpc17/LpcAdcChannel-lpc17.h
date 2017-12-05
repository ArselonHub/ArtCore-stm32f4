#ifndef ART_LPC_LPCADCCHANNEL_LPC17_H
#define ART_LPC_LPCADCCHANNEL_LPC17_H

#include <Art/Private/Pin.h>

namespace Art
{
	class LpcAdc;
	
	class LpcAdcChannel : public AdcChannel
	{
	public:
		virtual Result open();
		virtual Result read(Short& value);
		virtual Result read(UShort& value);
		virtual Result read(Int& value);
	private:
		struct ChannelData
		{
			volatile UWord*	data;
			UWord		index;
			PinId		pin;
			PinConfig	pinConfig;
		};
		
	private:	
		LpcAdcChannel(const ChannelData* data) { this->data = data; }				
		
		const ChannelData* data;
		friend class LpcAdc;
	};
}

#endif
