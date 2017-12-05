#ifndef BITBUFFER_H
#define BITBUFFER_H

#include <Art/Types.h>

#define WORD_SIZE 		(sizeof(Word) * 8)
#define WORD_SIZE_MASK	(WORD_SIZE - 1)

namespace Art
{
	class BitBuffer
	{
	public:
		BitBuffer(void* buffer)
		{
			this->buffer = (UByte*)buffer;
			this->index = 0;
		}

		BitBuffer(void* buffer, UWord index)
		{
			this->buffer = (UByte*)buffer;
			this->index = index;
		}

		Word read()
		{
			//TODO use inline assembly
			Word i = index;
			index = i + 1;
			return (buffer[i >> 3] >> (i & 7)) & 1;
		}
	
		void write(Word value)
		{
			Word i = index;
			index = i + 1;
			Word bit = 1 << (i % 8);
			if (value)
				buffer[i / 8] |= bit;
			else
				buffer[i / 8] &= ~bit;
		}

		void advance(Word value)
		{
			index += value;
		}

		void seekTo(Word index)
		{
			this->index = index;
		}

		UByte* getBuffer()
		{
			 return buffer;
		}
	
		Word getIndex()
		{
			return index;
		}

	private:
		UByte*	buffer;
		Word	index;
	};
}

#endif
