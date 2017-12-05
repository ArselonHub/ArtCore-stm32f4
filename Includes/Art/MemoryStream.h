/*
 * MemoryWriter.h
 *
 *  Created on: 17 �ub 2014
 *      Author: denizcan
 */

#ifndef ART_MEMORYSTREAM_H_
#define ART_MEMORYSTREAM_H_

#include <Art/Stream.h>

namespace Art
{
	class MemoryStream : public Stream
	{
	public:
		MemoryStream(void* buffer);
		MemoryStream(void* buffer, ShortL size);
		virtual Word write(const void* buffer, ShortL length);
		virtual Int bytesWritten();
		virtual Word read(void* buffer, ShortL length);
	private:
		UByte*	buffer_;
		UShort	size_;
		UShort	index_;
	};

} /* namespace Art */
#endif /* MEMORYWRITER_H_ */
