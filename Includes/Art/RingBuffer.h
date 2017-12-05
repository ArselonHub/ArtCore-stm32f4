/*
 * RingBuffer.h
 *
 *  Created on: 07 Eki 2014
 *      Author: denizcan
 */

#ifndef ART_RINGBUFFER_H_
#define ART_RINGBUFFER_H_

#include <Art/Stream.h>
#include <Art/Types.h>

namespace Art
{
	class RingBuffer
	{
	public:
		RingBuffer();
		RingBuffer(void* buffer, Word size);
		inline Bool isEmpty();
		inline Bool hasData();
		Bool putUByte(Word value);
		Word hasUByte(Word value);
		Word popUByte();
		Word write(Stream* stream, Word length);
		Word write(const void* data, Word maxLength);
		Word read(void* data, Word maxLength);
		Word read(Stream* stream, Word length);
		void skip(Word length);
		void setBuffer(void* buffer, Word size);
		void flush();
		void getTailChunk(void*& data, Word& length);
		inline UByte* tail();
		UByte* head();
		inline void* buffer();
		inline Word tailLength();
		inline Word bytesToRead();
		inline Word bytesToWrite();
		inline Word length();
		inline Word size();
	private:
		UByte*	m_buffer;
		UShort	m_size;
		UShort	m_head;
		UShort	m_tail;
	};

	Bool RingBuffer::isEmpty()
	{
		return m_tail == m_head;
	}

	Bool RingBuffer::hasData()
	{
		return m_tail != m_head;
	}

	UByte* RingBuffer::tail()
	{
		return m_buffer + m_tail;
	}


	Word RingBuffer::tailLength()
	{
		return (m_head < m_size) ? (m_head - m_tail) : (m_size - m_tail);
	}

	Word RingBuffer::bytesToRead()
	{
		return m_head - m_tail;
	}

	Word RingBuffer::bytesToWrite()
	{
		return m_size - (m_head - m_tail);
	}

	void* RingBuffer::buffer()
	{
		return m_buffer;
	}

	inline Word RingBuffer::length()
	{
		return m_head - m_tail;
	}

	Word RingBuffer::size()
	{
		return m_size;
	}
} /* namespace Art */
#endif /* RINGBUFFER_H_ */
