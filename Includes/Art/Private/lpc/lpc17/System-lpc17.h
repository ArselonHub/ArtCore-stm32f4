#ifndef ART_LPC_CORE_LPC17_H
#define ART_LPC_CORE_LPC17_H

namespace Art
{
	namespace System
	{
		struct ClockConfiguration
		{		
			const ClockProfile* profile;
			UWord	scs;
			UWord	clksrcsel;
			UWord	pll0cfg;
			UWord	cclkcfg;
		};
		
		extern const UartDivisor uartProfile96Mhz[];
		extern const ClockProfile clockProfile4MHz;
		extern const ClockConfiguration clockConfigurationInternal96Mhz;
		extern const ClockConfiguration clockConfigurationInternalMaxSpeed;
	}

}

#endif
