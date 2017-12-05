#ifndef ART_STREAM_H
#define ART_STREAM_H

#include <Art/Object.h>
#include <Art/String.h>

namespace Art
{
	/*!
	 * \brief Provides generic handling of bytes. This is an abstract class
	 * \ingroup Data Handling
	 * Stream class is the core class in Art's serial data handling toolset.
	 * It serves as interface for writing to and reading from serial peripherals,
	 * files, sockets etc.
	 *
	 */
	class Stream : public Object
	{
	public:		    
		Signal<void*> onDataReady() SIGNAL;
		Signal<void*> onDataWritten() SIGNAL;

		virtual Word bytesToWrite() = 0;
		virtual Word bytesToSend();
		virtual Int bytesWritten();
		virtual Word waitForDataWritten(Word timeout = 0);
		virtual Word write(const void* buffer, Word length) = 0;
		virtual Word read(void* buffer, Word length) = 0;
        virtual Word skipBytes(Word length) = 0;
		virtual Word bytesToRead() = 0;
		virtual Bool canReadLine();
        virtual Word waitForDataReady(Word timeout = 0);
        virtual Word readTimeout();
        virtual Word setReadTimeout(Word value);
        virtual Word writeTimeout();
        virtual Word setWriteTimeout(Word value);

		Word readChar(Char& value);
		Word readByte(UByte& value);
		Word readShort(Short& value);
		Word readUShort(UShort& value);
		Word readInt(Int& value);
		Word readUInt(UInt& value);
		Word readLine(Char* s, UWord length);
		Word readDateTime(DateTime& value);

		Word writeChar(Char value);
		Word writeByte(UByte value);
		Word writeShort(Short value);
		Word writeUShort(UShort value);
		Word writeInt(Int value);
		Word writeUInt(UInt value);
		Word writeString(const Char* s);
		Word writeString(const StringRef& value);
		Word writeString(const Expression& value);
		Word writeLine();
		Word writeLine(const Char* s);
		Word writeLine(const StringRef& value);
		Word writeLine(const Expression& value);
		Word writeDateTime(DateTime& value);
	};

}

#endif
