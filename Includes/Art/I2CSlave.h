/*
 * I2CSlave.h
 *
 *  Created on: Dec 7, 2016
 *      Author: denizcan
 */

#ifndef ART_I2CSLAVE_H_
#define ART_I2CSLAVE_H_

#include <Art/Device.h>
#include <Art/I2CPort.h>


namespace Art
{

	class I2CSlave : public Device
	{
	public:
		Word address() const;
		I2CPort* port() const;

		Word writeTo(const void* buffer, Word length);
		Word readFrom(void* buffer, Word length);
		Word setAddress(Word value);
		Word setPort(I2CPort* value);

		Signal<void*> onReadRequest() SIGNAL;
		Signal<void*> onWriteRequest() SIGNAL;
		Signal<void*, Word> onReadCompleted() SIGNAL;
		Signal<void*, Word> onWriteCompleted() SIGNAL;
	private:
		virtual Word openDevice();
		virtual Word closeDevice();

		I2CPort*	m_port;
		Word		m_address;

		friend I2CPort;
	};

	inline Word I2CSlave::address() const
	{
		return m_address;
	}

	inline I2CPort* I2CSlave::port() const
	{
		return m_port;
	}
} /* namespace Art */

#endif /* SOURCE_ART_I2CSLAVE_H_ */
