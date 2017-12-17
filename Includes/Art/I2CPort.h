/*
 * I2C.h
 *
 *  Created on: May 3, 2013
 *      Author: denizcan
 */

#ifndef ART_I2CPORT_H_
#define ART_I2CPORT_H_

#include <Art/Pin.h>
#include <Art/Task.h>
#include <Art/I2CDevice.h>

namespace Art
{
	class I2CSlave;

	class I2CPort
	{
	public:
		I2CPort();
		virtual ~I2CPort();

	protected:
		void performReadRequestedIrq(I2CSlave* slave);
		void performWriteRequestedIrq(I2CSlave* slave);
		void performReadCompletedIrq(Word responseValue);
		void performWriteCompletedIrq(Word responseValue);
		void performGenericCall();
		void setResponseValueIrq(Word responseValue);

		Word currentAddress();
		I2CData* currentData();
	private:
		Word enqueue(I2CDevice* device);
		Word open();
		Word close();
		Word resetBus();

		// port driver
		virtual void openPort() = 0;
		virtual void closePort() = 0;
		virtual void startPort() = 0;
		virtual void stopPort() = 0;
		virtual Word registerSlave(I2CSlave* slave) = 0;
		virtual Word unregisterSlave(I2CSlave* slave) = 0;

		enum BusState
		{
			BusStateNothing,
			BusStateGenericCall,
			BusStateReadRequested,
			BusStateReadCompleted,
			BusStateWriteRequested,
			BusStateWriteCompleted,
			BusStateRequestCompleted
		};

		class BusTask : public Task
		{
		public:
			virtual void execute();
		};

		void setBusStateIrq(BusState value);

		I2CSlave*				m_currentSlave;
		I2CDevice*				m_currentRequester;
		BasicQueue<I2CDevice>	m_requesters;
		UByte					m_openCount;
		BusState				m_busState;
		BusTask					m_busTask;
		Word					m_responseValue;

		friend class I2CSlave;
		friend class I2CDevice;
	};

	inline Word I2CPort::currentAddress()
	{
		return m_currentRequester->m_address;
	}

	inline I2CData* I2CPort::currentData()
	{
		return m_currentRequester->m_data;
	}
}

#if defined(__LPC1758__) || defined(__LPC1768__)
#	include <Art/lpc/LpcI2C.h>	
#elif defined(__STM32F4XX__)
#	include <Art/Private/stm32/stm32f4/StmI2CPort.h>
#endif

#endif /* I2C_H_ */
