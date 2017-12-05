/*
 * Uart-lpc112x.h
 *
 *  Created on: 12 Şub 2015
 *      Author: denizcan
 */

#ifndef ART_PRIVATE_LPC_LPC17_LPCUART_LPC17_H_
#define ART_PRIVATE_LPC_LPC17_LPCUART_LPC17_H_

#include <Art/Private/lpc/LpcUartPortPort.h>

namespace Art
{
	extern "C" void UART0_IRQHandler();
	extern "C" void UART1_IRQHandler();
	extern "C" void UART2_IRQHandler();
	extern "C" void UART3_IRQHandler();

	class LpcUart0 : public LpcUartPort
	{
	public:
		LpcUart0();

	protected:
		// Uart
		virtual void configurePins();
		virtual Result powerUp();
		virtual Result powerDown();

		virtual void setClockDivider(UWord value);

	private:
		static LpcUart0	instance;

		friend void UART0_IRQHandler();
		friend LpcUart0* uart0();	
	};

	class LpcUart1 : public LpcUartPort
	{
	public:
		LpcUart1();

	protected:
		// Uart
		virtual Result powerUp();
		virtual Result powerDown();
		virtual void setClockDivider(UWord value);
		virtual void configurePins();

	private:
		static LpcUart1 instance;

		friend void UART1_IRQHandler();
		friend LpcUart1* uart1();
	};

	class LpcUart2 : public LpcUartPort
	{
	public:
		LpcUart2();

	protected:
		// Uart
		virtual Result powerUp();
		virtual Result powerDown();
		virtual void setClockDivider(UWord value);
		virtual void configurePins();

	private:
		static LpcUart2 instance;

		friend void UART2_IRQHandler();
		friend LpcUart2* uart2();
	};

	class LpcUart3 : public LpcUartPort
	{
	public:
		LpcUart3();

	protected:
		// Uart
		virtual Result powerUp();
		virtual Result powerDown();
		virtual void setClockDivider(UWord value);
		virtual void configurePins();

	private:
		static LpcUart3 instance;

		friend void UART3_IRQHandler();
		friend LpcUart3* uart3();
	};

	inline LpcUart0* uart0()
	{
		return &LpcUart0::instance;
	}

	inline LpcUart1* uart1()
	{
		return &LpcUart1::instance;
	}

	inline LpcUart2* uart2()
	{
		return &LpcUart2::instance;
	}

	inline LpcUart3* uart3()
	{
		return &LpcUart3::instance;
	}
}

#include <Art/PinPort.h>

#endif 
