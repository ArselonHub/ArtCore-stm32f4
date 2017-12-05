/*
 * I2C.h
 *
 *  Created on: May 3, 2013
 *      Author: denizcan
 */

#ifndef ART_I2CPORT_H_
#define ART_I2CPORT_H_

#include <Art/Pin.h>
#include <Art/I2CRequest.h>
#include <Art/Task.h>

namespace Art
{
	class I2CSlave;

	class I2CPort
	{
	protected:
		void performReadRequestedIrq(I2CSlave* slave);
		void performWriteRequestedIrq(I2CSlave* slave);
		void performReadCompletedIrq(Word responseValue);
		void performWriteCompletedIrq(Word responseValue);
		void performGenericCall();
		void setResponseValueIrq(Word responseValue);

		I2CRequest* currentRequest();
	private:
		Word enqueue(I2CRequest* request);
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
		I2CRequest*				m_currentRequest;
		BasicQueue<I2CRequest>	m_requests;
		UByte					m_openCount;
		BusState				m_busState;
		BusTask					m_busTask;
		Word					m_responseValue;

		friend class I2CSlave;
		friend class I2CDevice;
	};

	inline I2CRequest* I2CPort::currentRequest()
	{
		return m_currentRequest;
	}
}

#if defined(__LPC1758__) || defined(__LPC1768__)
#	include <Art/lpc/LpcI2C.h>	
#elif defined(__STM32F4XX__)
#	include <Art/Private/stm32/stm32f4/StmI2CPort.h>
#endif

#endif /* I2C_H_ */
