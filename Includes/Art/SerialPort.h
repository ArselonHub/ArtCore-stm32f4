#ifndef ART_SERIALPORT_H
#define ART_SERIALPORT_H

#include <Art/Event.h>
#include <Art/Requester.h>
#include <Art/Stream.h>
#include <Art/Uart.h>

namespace Art
{

	class SerialPort : public Stream
	{
	public:
		SerialPort();
		Int baud();
		void setBaud(Int value);

		// stream
		virtual Int bytesToRead();
        virtual Word skipBytes(Word length);
		virtual Word read(void* data, Word length);
        virtual Word waitForDataReady(Word timeout = 0);
		virtual Bool canReadLine();
		virtual Word write(const void* data, Word length);
        virtual Word bytesToWrite();
		virtual Word bytesToSend();
		virtual Word waitForDataWritten(Word timeout = 0);

		Uart* port() const;
		Word setPort(Uart* port);
		Word open();

		DataBits dataBits() const;
		void setDataBits(DataBits value);

		Parity parity() const;
		void setParity(Parity value);
		StopBits stopBits() const;
		void setStopBits(StopBits value);
		Thread* thread() const;
		void setThread(Thread* value);

		Signal<void*> onIdle() SIGNAL;
		Signal<void*> onDataTransmitted() SIGNAL;
	private:
		RingBuffer*	rxBuffer();
		RingBuffer* txBuffer();

		void processReportSvc(UWord report);

		class DelegateTask : public Task
		{
			virtual void execute();
		};

		//void triggerSvc(Delegate<void*>* delegate);

		Thread*			m_thread;
		Uart*			m_port;

		Event			m_dataReadyEvent;
		Event			m_dataWrittenEvent;
		DelegateTask	m_delegateTask;
		UByte			m_report;
		UByte			m_reportMask;

		Int				m_baud;
		DataBits		m_dataBits;
		StopBits		m_stopBits;
		Parity			m_parity;
		Bool			m_active;
		Word			m_writeTimeout;
		Word			m_readTimeout;

		friend class Uart;
	};

	inline Int SerialPort::baud()
	{
		return m_baud;
	}

	inline void SerialPort::setBaud(Int value)
	{
		m_baud = value;
	}

	inline Uart* SerialPort::port() const
	{
		return m_port;
	}

	inline Word SerialPort::setPort(Uart* value)
	{
		if (m_active)
			return ErrorInvalidOperation;
		m_port = value;
		return ErrorOk;
	}

	inline DataBits SerialPort::dataBits() const
	{
		return m_dataBits;
	}

	inline Parity SerialPort::parity() const
	{
		return m_parity;
	}

	inline void SerialPort::setParity(Parity value)
	{
		m_parity = value;
	}

	inline StopBits SerialPort::stopBits() const
	{
		return m_stopBits;
	}

	inline void SerialPort::setStopBits(StopBits value)
	{
		m_stopBits = value;
	}

	inline Thread* SerialPort::thread() const
	{
		return m_thread;
	}

	inline void SerialPort::setThread(Thread* value)
	{
		m_thread = value;
	}

	inline RingBuffer* SerialPort::rxBuffer()
	{
		return &m_port->m_rxBuffer;
	}

	inline RingBuffer* SerialPort::txBuffer()
	{
		return &m_port->m_txBuffer;
	}

}

#endif
