#ifndef ART_MCU_CM
#define ART_MCU_CM

namespace Art
{
	inline void disableInterrupts()
	{
		__disable_irq();
	}

	inline void enableInterrupts()
	{
		__enable_irq();
	}

	inline bool isInterruptsEnabled()
	{
		return __get_PRIMASK() != 0;		
	}

	inline bool isInterruptsDisabled()
	{
		return __get_PRIMASK() == 0;		
	}
		
	inline bool isInInterrupt()
	{
		return __get_IPSR() != 0;
	
	}

	inline bool isInSvc()
	{
		UWord ipsr = __get_IPSR();
		return (ipsr >= 14) && (ipsr <= 15);
	}
	
	inline bool isInThread()
	{
		return __get_IPSR() == 0;
	}
}

#endif
