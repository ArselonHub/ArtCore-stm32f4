/*
 * Uart.h
 *
 *  Created on: Jul 27, 2015
 *      Author: denizcan
 */

#ifndef ART_UARTPORT_H_
#define ART_UARTPORT_H_

#include <Art/Pin.h>
#include <Art/Private/UartDefines.h>
#include <Art/RingBuffer.h>
#include <Art/Task.h>
#include <Art/Device.h>

namespace Art
{
	class SerialPort;

	class Uart
	{
	public:
		Uart();
		virtual ~Uart();
		Pin* rxPin() const;
		Pin* txPin() const;
		void setRxPin(Pin* value);
		void setTxPin(Pin* value);

	protected:
		enum Report
		{
			ReportDataReady = 0x01,
			ReportDataWritten = 0x02,
			ReportDataTransmitted = 0x04,
			ReportIdle = 0x08
		};

		RingBuffer* rxBuffer();
		RingBuffer* txBuffer();
		void reportIrq(Word report);
		Parity parity();
		StopBits stopBits();
		Int baud();
	private:
		virtual Word open() = 0;
		virtual Word close() = 0;
		virtual void configure() = 0;
		virtual void transmit() = 0;
		virtual void flushRxFifo() = 0;
		virtual void flushTxFifo() = 0;
		
		class StatusTask : public Task
		{
			virtual void execute();
		};

		SerialPort*		m_serialPort;
		RingBuffer		m_rxBuffer;
		RingBuffer		m_txBuffer;
		StatusTask		m_statusTask;
		Pin*			m_rxPin;
		Pin*			m_txPin;
		UWord			m_report;

		friend class SerialPort;
	};

	inline Pin* Uart::rxPin() const
	{
		return m_rxPin;
	}

	inline Pin* Uart::txPin() const
	{
		return m_txPin;
	}

	inline void Uart::setRxPin(Pin* value)
	{
		m_rxPin = value;
	}

	inline void Uart::setTxPin(Pin* value)
	{
		m_txPin = value;
	}

	inline RingBuffer* Uart::rxBuffer()
	{
		return &m_rxBuffer;
	}


	inline RingBuffer* Uart::txBuffer()
	{
		return &m_txBuffer;
	}

} /* namespace Art */

#if defined(STM32F051)
	#include <Art/stm32/stm32f0/Uart-stm32f0.h>
#elif defined(__STM32F429__)
#	include <Art/Private/stm32/stm32f4/StmUart.h>
#elif defined(__LPC17XX__)
	#include <Art/Private/lpc/lpc17/LpcUartPort-lpc17.h>
#elif defined(__CC430F5137__)
	#include <Art/Private/msp430/UsciaUart.h>
#elif defined(__LPC112X__)
	#include <Art/Private/lpc/lpc112x/Uart-lpc112x.h>
#endif

#endif /* UART_H_ */
