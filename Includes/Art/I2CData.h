/*
 * I2CData.h
 *
 *  Created on: Dec 9, 2016
 *      Author: denizcan
 */

#ifndef ART_I2CDATA_H_
#define ART_I2CDATA_H_

#include <Art/Types.h>

namespace Art
{
	class I2CData
	{
	public:
		I2CData(void* buffer, Word length);
		I2CData(void* buffer, Word length, I2CData* next);

		void* buffer() const;
		Word length() const;
		I2CData* next() const;
	private:
		I2CData();

		I2CData*	m_next;
		void*		m_buffer;
		Word		m_length;
	};

	inline I2CData::I2CData()
	{
		m_buffer = 0;
		m_length = 0;
		m_next = 0;
	}

	inline I2CData::I2CData(void* buffer, Word length)
	{
		m_buffer = buffer;
		m_length = length;
		m_next = 0;
	}

	inline I2CData::I2CData(void* buffer, Word length, I2CData* next)
	{
		m_buffer = buffer;
		m_length = length;
		m_next = next;
	}

	inline void* I2CData::buffer() const
	{
		return m_buffer;
	}

	inline Word I2CData::length() const
	{
		return m_length;
	}


	inline I2CData* I2CData::next() const
	{
		return m_next;
	}
} /* namespace Art */

#endif /* SOURCE_ART_I2CDATA_H_ */
