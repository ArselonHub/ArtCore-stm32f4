/*
 * I2CRequest.h
 *
 *  Created on: Dec 8, 2016
 *      Author: denizcan
 */

#ifndef ART_I2CREQUEST_H_
#define ART_I2CREQUEST_H_

#include <Art/Response.h>
#include <Art/BasicQueue.h>
#include <Art/I2CData.h>

namespace Art
{
	class I2CDevice;

	class I2CRequest
	{
	public:
		I2CRequest(Word address, I2CData* data, Response* response);

		Byte address() const;
		Response* response() const;
		I2CData* data() const;

	private:
		I2CRequest*	m_next;
		Response*	m_response;
		I2CData*	m_data;
		UByte		m_address;

		friend class BasicQueue<I2CRequest>;
	};

	inline I2CRequest::I2CRequest(Word address, I2CData* data,
	        Response* response)
	{
		m_address = address;
		m_data = data;
		m_response = response;
	}


	inline Byte I2CRequest::address() const
	{
		return m_address;
	}

	inline Response* I2CRequest::response() const
	{
		return m_response;
	}

	inline I2CData* I2CRequest::data() const
	{
		return m_data;
	}

} /* namespace Art */

#endif /* SOURCE_ART_I2CREQUEST_H_ */
