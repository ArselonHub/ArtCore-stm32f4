/*
 * I2CPort-stm32f4.h
 *
 *  Created on: Dec 3, 2016
 *      Author: denizcan
 */

#ifndef ART_PRIVATE_STM32_STM32F4_I2CPORT_STM32F4_H_
#define ART_PRIVATE_STM32_STM32F4_I2CPORT_STM32F4_H_

#include <Art/I2CPort.h>
#include <Art/Mcu.h>
#include <Art/I2CData.h>

namespace Art
{
	namespace Private
	{
		class StmI2CPort : public Art::I2CPort
		{
		public:
			virtual ~StmI2CPort();
			Pin* sclPin() const;
			Pin* sdaPin() const;
			void setSclPin(Pin* sclPin);
			void setSdaPin(Pin* sdaPin);
		protected:
			StmI2CPort(I2C_TypeDef* port);
			I2C_TypeDef* port();

			void processEventIrq();
			void processErrorIrq();
			void configurePin(Pin* pin);

		private:
			void readOne();
			void writeOne();
			virtual void openPort();
			virtual void closePort();
			virtual void startPort();
			virtual void stopPort();
			virtual Word registerSlave(I2CSlave* slave);
			virtual Word unregisterSlave(I2CSlave* slave);

			virtual void powerUp() = 0;
			virtual void powerDown() = 0;
			void stop();

			I2C_TypeDef*	m_port;
			Pin*			m_sclPin;
			Pin*			m_sdaPin;
			Word			m_bufferIndex;
			Word			m_transferredBytes;
			Word			m_totalLength;
			I2CData* 		m_data;
			I2CSlave*		m_slaves[2];
		};

		inline I2C_TypeDef* StmI2CPort::port()
		{
			return m_port;
		}

		inline Art::Pin* StmI2CPort::sclPin() const
		{
			return m_sclPin;
		}

		inline void StmI2CPort::setSclPin(Pin* sclPin)
		{
			m_sclPin = sclPin;
		}

		inline Art::Pin* StmI2CPort::sdaPin() const
		{
			return m_sdaPin;
		}

		inline void StmI2CPort::setSdaPin(Pin* sdaPin)
		{
			m_sdaPin = sdaPin;
		}

		inline void StmI2CPort::stop()
		{
			m_port->CR1 |= I2C_CR1_STOP;
		}
	}
}

#include <Art/Private/stm32/stm32f4/StmI2CPort2.h>
#include <Art/Private/stm32/stm32f4/StmI2CPort3.h>

#endif /* SOURCE_ART_PRIVATE_STM32_STM32F4_I2CPORT_STM32F4_H_ */
