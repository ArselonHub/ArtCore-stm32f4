#ifndef ART_PRIVATE_LPC_PIT_LPC17_H
#define ART_PRIVATE_LPC_PIT_LPC17_H

#include <Art/Private/lpc/CaptureChannel-lpc.h>
#include <Art/Private/lpc/Pit-lpc.h>
#include <Art/Private/lpc/PulseChannel-lpc.h>

namespace Art
{
	extern "C" void TIMER0_IRQHandler();
	class LpcTim0 : public Pit
	{
	public:
		LpcTim0();
		PulseChannel* match0();
		PulseChannel* match1();
		PulseChannel* match2();
		PulseChannel* match3();

		CaptureChannel* capture0();
		CaptureChannel* capture1();

	private:
		virtual void powerUpPort();
		virtual void powerDownPort();
		virtual void enableInterruptPort();
		virtual void disableInterruptPort();

		static LpcTim0 instance;

		friend void TIMER0_IRQHandler();
		friend LpcTim0* tim0();
	};

	extern "C" void TIMER1_IRQHandler();
	class LpcTim1 : public Pit
	{
	public:
		LpcTim1();
		PulseChannel* match0();
		PulseChannel* match1();
		PulseChannel* match2();
		PulseChannel* match3();

		CaptureChannel* capture0();
		CaptureChannel* capture1();

	private:
		virtual void powerUpPort();
		virtual void powerDownPort();
		virtual void enableInterruptPort();
		virtual void disableInterruptPort();

		static LpcTim1 instance;

		friend void TIMER1_IRQHandler();
		friend LpcTim1* tim1();
	};

	extern "C" void TIMER2_IRQHandler();
	class LpcTim2 : public Pit
	{
	public:
		LpcTim2();
		PulseChannel* match0();
		PulseChannel* match1();
		PulseChannel* match2();
		PulseChannel* match3();

		CaptureChannel* capture0();
		CaptureChannel* capture1();

	private:
		virtual void powerUpPort();
		virtual void powerDownPort();
		virtual void enableInterruptPort();
		virtual void disableInterruptPort();

		static LpcTim2 instance;

		friend void TIMER2_IRQHandler();
		friend LpcTim2* tim2();
	};

	extern "C" void TIMER3_IRQHandler();
	class LpcTim3 : public Pit
	{
	public:
		LpcTim3();
		PulseChannel* match0();
		PulseChannel* match1();
		PulseChannel* match2();
		PulseChannel* match3();

		CaptureChannel* capture0();
		CaptureChannel* capture1();

	private:
		virtual void powerUpPort();
		virtual void powerDownPort();
		virtual void enableInterruptPort();
		virtual void disableInterruptPort();

		static LpcTim3 instance;

		friend void TIMER3_IRQHandler();
		friend LpcTim3* tim3();
	};
	inline LpcTim0* tim0()
	{
		return &LpcTim0::instance;
	}

	inline LpcTim1* tim1()
	{
		return &LpcTim1::instance;
	}

	inline LpcTim2* tim2()
	{
		return &LpcTim2::instance;
	}

	inline LpcTim3* tim3()
	{
		return &LpcTim3::instance;
	}

}

#endif
