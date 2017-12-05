#ifndef ART_SPLITSTREAM_H
#define ART_SPLITSTREAM_H

#include <Art/Stream.h>

namespace Art
{
	class SplitStream : public Stream
	{
	public:
		SplitStream();
		SplitStream(Stream* input, Stream* output);	
		virtual ShortL read(void* buffer, ShortL length);
        virtual ShortL skipBytes(ShortL length);
		virtual ShortL bytesToRead();
		virtual ShortL bytesToWrite();
		virtual ShortL write(const void* buffer, ShortL length);
	
	protected:
	
		void setInput(Stream* value) { input = value; }
		void setOutput(Stream* value) { output = value; }
	private:
		Stream* input;
		Stream* output;
	};
	
}

#endif
