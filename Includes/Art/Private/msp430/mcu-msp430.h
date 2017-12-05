#ifndef ART_MCU_MSP430_H
#define ART_MCU_MSP430_H

namespace Art
{
	inline Bool isInInterrupt()
	{
		return (__get_SR_register() & GIE) == 0;
	}

	inline Bool isInSvc()
	{
		return false;
	}

	inline void disableInterrupts()
	{
		asm("	dint");
		asm("	nop");
	}

	inline void enableInterrupts()
	{
		asm("	nop");
		asm("	eint");
		asm("	nop");
	}
	
	inline void exitSleep()
	{

	}

	inline void enterSleep()
	{

	}

	inline void disableFLL()
	{
		__bis_SR_register(SCG0);
	}

	inline void enableFLL()
	{
		__bic_SR_register(SCG0);
	}

	struct Msp430Gpio
	{
		Byte	in;
		Byte	_0;
		Byte	out;
		Byte	_1;
		Byte	dir;
		Byte	_2;
		Byte	resistor;
		Byte	_3;
		Byte	strength;
		Byte	_4;
		Byte	selection;
	};

	struct MspTimerA
	{
		volatile UWord	ctl;
		volatile UWord	cctl0;
		volatile UWord	cctl1;
		volatile UWord	cctl2;
		volatile UWord	cctl3;
		volatile UWord	cctl4;
		volatile UWord	cctl5;
		volatile UWord	cctl6;
		volatile UWord	r;
		volatile UWord	ccr0;
		volatile UWord	ccr1;
		volatile UWord	ccr2;
		volatile UWord	ccr3;
		volatile UWord	ccr4;
		volatile UWord	ccr5;
		volatile UWord	ccr6;
		volatile UWord	ex0;
	};

	static const MspTimerA* mspTimerA = (MspTimerA*)&TA1CTL;
}

#endif
