#ifndef ART_STDSTREAM_H
#define ART_STDSTREAM_H

#include <Art/SplitStream.h>
#include <Art/Stream.h>

namespace Art
{
	class StdStream : public Stream
	{
	public:
		StdStream();
		StdStream(FILE* file);
		virtual ShortL read(void* buffer, ShortL length);
        virtual ShortL skipBytes(ShortL length);
		virtual ShortL bytesToRead();
		virtual ShortL bytesToWrite();
		virtual ShortL write(const void* buffer, ShortL length);

	private:
		FILE* file;
	};

	extern StdStream stdInput;
	extern StdStream stdOutput;
	extern StdStream stdError;	
	extern SplitStream stdConsole;

}

#endif
