/*
 * I2CDevice.h
 *
 *  Created on: Dec 9, 2016
 *      Author: denizcan
 */

#ifndef ART_I2CDEVICE_H_
#define ART_I2CDEVICE_H_

#include <Art/Device.h>
#include <Art/Response.h>
#include <Art/I2CData.h>
#include <Art/BasicQueue.h>

namespace Art
{
	class I2CPort;

	class I2CDevice : public Device
	{
	public:
		I2CDevice();
		virtual ~I2CDevice();
		Word address() const;
		Word setAddress(Word address);
		I2CPort* port() const;
		Word setPort(I2CPort* port);
		Word pool();
		Word write(I2CData* data);
		Word write(I2CData* data, Response* response);
		Word write(void* buffer, Word length);
		Word write(void* buffer0, Word length0, void* buffer1, Word length1);
		Word writeRegister(Word registerAddress, void* buffer, Word length);
		Word writeRegister(Word registerAddress, Word value);
		Word read(I2CData* data);
		Word read(I2CData* data, Response* response);
		Word read(void* buffer, Word length);
		Word readRegister(Word registerAddress);
		Word readRegister(Word registerAddress, void* buffer, Word length);
	private:
		Word request(I2CData* data, Response* response, bool isRead);
		virtual Word openDevice();
		virtual Word closeDevice();

		I2CDevice*	m_next;
		I2CPort*	m_port;
		Word		m_address;
		I2CData*	m_data;
		Response*	m_response;

		friend class I2CPort;
		friend class BasicQueue<I2CDevice>;
	};

	inline I2CPort* I2CDevice::port() const
	{
		return m_port;
	}


} /* namespace Art */

#include <Art/I2CPort.h>

#endif /* SOURCE_ART_I2CDEVICE_H_ */
