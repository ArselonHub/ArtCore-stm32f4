#ifndef ART_STM32_CORE_STM32F0_H
#define ART_STM32_CORE_STM32F0_H

namespace Art
{
	namespace System
	{
		struct ClockProfile
		{
			UWord	frequency;		
			UWord	usLoop;
			UWord	msLoop;
			UWord	sysTickValue;
		};
		
		struct ClockConfiguration
		{		
			const ClockProfile* profile;
			UWord	rcc_cr;
			UWord	rcc_cfgr;
			UWord	rcc_cfgr2;
		};
		
		extern const ClockConfiguration clockConfigurationDefault;
		extern const ClockConfiguration	clockConfigurationInternalHighSpeed;
		extern const ClockConfiguration clockConfigurationHSI48Mhz;

		enum ClockOutput
		{
			ClockOutputDisabled,
			ClockOutputHSI14,
			ClockOutputLSI,
			ClockOutputLSE,
			ClockOutputSystemClock,
			ClockOutputHSI,
			ClockOutputHSE,
			ClockOutputHSI48	
		};
							
		extern Result setClockOutput(ClockOutput value);
	}
}

#endif
