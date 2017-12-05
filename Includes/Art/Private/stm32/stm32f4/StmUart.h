/*
 * StmUartPort.h
 *
 *  Created on: Dec 23, 2016
 *      Author: denizcan
 */

#ifndef SOURCE_ART_PRIVATE_STM32_STM32F4_STMUARTPORT_H_
#define SOURCE_ART_PRIVATE_STM32_STM32F4_STMUARTPORT_H_

#include <Art/Uart.h>

namespace Art
{
	namespace Private
	{
		class StmUart : public Uart
		{
		public:
			StmUart(void* port);
			virtual ~StmUart();
		protected:
			void handleInterrupt();

		private:
			virtual Word open();
			virtual Word close();
			virtual void configure();
			virtual void transmit();
			virtual void flushRxFifo();
			virtual void flushTxFifo();

			virtual void powerUp() = 0;
			virtual void powerDown() = 0;

			void*	m_port;
			Word	m_rxCount;
			Word	m_txCount;
		};
	}
}

#include <Art/Private/stm32/stm32f4/StmUart1.h>

#endif /* SOURCE_ART_PRIVATE_STM32_STM32F4_STMUARTPORT_H_ */
