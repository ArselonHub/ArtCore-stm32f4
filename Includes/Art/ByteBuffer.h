#ifndef BYTESTREAM_H
#define BYTESTREAM_H

#include <Art/Types.h>

namespace Art
{
	class ByteStream
	{
	private:
		UByte* buffer;
		UByte* index;
	public:
		ByteStream(void* buffer)
		{
			this->buffer = (UByte*)buffer;
			this->index = (UByte*)buffer;
		}
	
		INLINE Char readChar()
		{
			index += sizeof(Char);
			return ((Char*)index)[-1];
		}
	
		INLINE Byte readSByte()
		{
			index += sizeof(Byte);
			return ((Byte*)index)[-1];
		}

		INLINE UByte readByte()
		{
			index += sizeof(UByte);
			return index[-1];
		}

		INLINE Short readShort()
		{
			index += sizeof(Short);
			return ((Short*)index)[-1];
		}

		INLINE UShort readUShort()
		{
			index += sizeof(UShort);
			return ((UShort*)index)[-1];
		}

		INLINE Int readInt()
		{
			index += sizeof(Int);
			return ((Int*)index)[-1];
		}

		INLINE Int readUInt()
		{
			index += sizeof(UInt);
			return ((UInt*)index)[-1];
		}

		INLINE void writeByte(UByte value)
		{
			*((UByte*)index) = value;
			index += sizeof(UByte);
		}

		INLINE void writeShort(Short value)
		{
			*((Short*)index) = value;
			index += sizeof(Short);
		}

		INLINE void writeUShort(UShort value)
		{
			*((UShort*)index) = value;
			index += sizeof(UShort);
		}

		INLINE void writeInt(Int value)
		{
			*((Int*)index) = value;
			index += sizeof(Int);
		}

		INLINE void writeUInt(UInt value)
		{
			*((UInt*)index) = value;
			index += sizeof(UInt);
		}

	};
}

#endif
