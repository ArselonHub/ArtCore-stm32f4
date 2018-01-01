/*
 * UsciaUart.h
 *
 *  Created on: 25 Oca 2014
 *      Author: denizcan
 */

#ifndef ART_USCIAUART_H_
#define ART_USCIAUART_H_

#include <Art/SerialPort.h>
#include <Art/Pin.h>

namespace Art
{
	class Uscia0Uart : public SerialPort
	{
	public:
		Uscia0Uart();
		void setRxPin(const Pin& value);
		void setTxPin(const Pin& value);
		void setRtsPin(const Pin& value);

		// Uart Interface
		virtual void flushRxFifo();
		virtual void flushTxFifo();
		virtual void powerUp();
		virtual void powerDown();
	protected:
		virtual Result openPort();
		virtual ShortL transmit(const Byte* data, ShortL length);
		virtual void disableTxInterrupt();
		virtual void enableTxInterrupt();
		virtual void configureDefaultPins();
	protected:
		static void processInterrupt();

	private:
		Pin rxPin;
		Pin txPin;
		Byte* txHead;
		Byte* txTail;
	};

	extern Uscia0Uart uscia0Uart;
	static const Uscia0Uart& serialPort = uscia0Uart;
}

#endif /* USCIAUART_H_ */
