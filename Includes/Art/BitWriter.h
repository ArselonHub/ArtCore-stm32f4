#ifndef BITWRITER_H
#define BITWRITER_H

#include <Art/Stream.h>

namespace Art
{
	class BitWriter
	{
	private:
		Stream* stream;
		UWord accumulator;
		UWord index;
	public:
		BitWriter(Stream* stream);
		void write(Bool value);
		void write(UWord value, Word bits);
		void flush();
	};
}

#endif // BITWRITER_H
