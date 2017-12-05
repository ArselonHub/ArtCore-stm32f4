/*
 * Uart-lpc112x.h
 *
 *  Created on: 12 Şub 2015
 *      Author: denizcan
 */

#ifndef ART_PRIVATE_LPC_LPC112X_UART_LPC112X_H_
#define ART_PRIVATE_LPC_LPC112X_UART_LPC112X_H_

#include <Art/Private/lpc/LpcUart.h>
#include <Art/Gpio.h>

namespace Art
{
	extern "C" void UART_IRQHandler();

	class LpcUart0 : public LpcUart
	{
	public:
		LpcUart0();
		//void setRxPin(PinPort& value);
		//void setTxPin(PinPort& value);
	protected:
		// Uart
		virtual Result powerUp();
		virtual Result powerDown();
		virtual void setClockDivider(UWord value);
		virtual void configurePins();

	private:
		static LpcUart0 instance;
		friend void UART_IRQHandler();
		friend LpcUart0& uart0();
	};

	inline LpcUart0& uart0()
	{
		return LpcUart0::instance;
	}
}

#endif /* SOURCE_ART_LPC_LPC112X_UART_LPC112X_H_ */
