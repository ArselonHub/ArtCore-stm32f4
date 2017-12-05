/*
 * I2CDevice.h
 *
 *  Created on: Dec 9, 2016
 *      Author: denizcan
 */

#ifndef ART_I2CDEVICE_H_
#define ART_I2CDEVICE_H_

#include <Art/Device.h>
#include <Art/I2CPort.h>

namespace Art
{
	class I2CDevice : public Device
	{
	public:
		Word address() const;
		void setAddress(Word address);
		I2CPort* port() const;
		void setPort(I2CPort* port);
		Word write(void* buffer, Word length);
		Word write(void* buffer0, Word length0, void* buffer1, Word length1);
		Word writeRegister(Word registerAddress, void* buffer, Word length);
		Word read(void* buffer, Word length);
		Word readRegister(Word registerAddress, void* buffer, Word length);
	private:
		virtual Word openDevice();
		virtual Word closeDevice();

		I2CPort*	m_port;
		UByte		m_address;
	};

	inline Word I2CDevice::address() const
	{
		return m_address;
	}

	inline void I2CDevice::setAddress(Word address)
	{
		m_address = address;
	}

	inline I2CPort* I2CDevice::port() const
	{
		return m_port;
	}

	inline void I2CDevice::setPort(I2CPort* port)
	{
		m_port = port;
	}
} /* namespace Art */

#endif /* SOURCE_ART_I2CDEVICE_H_ */
