/*
 * StringFormatter.h
 *
 *  Created on: Aug 21, 2015
 *      Author: denizcan
 */

#ifndef ART_PRIVATE_WRITEREMITTER_H_
#define ART_PRIVATE_WRITEREMITTER_H_

#include <Art/Private/Emitter.h>

namespace Art
{
	class Stream;
	
	namespace Private
	{
		class StreamEmitter : public Emitter
		{
		public:
			StreamEmitter(Stream* stream);
			virtual Word emitChar(const Char c, Word length);
			virtual Word emitStringRef(const StringRef& s);
		protected:
			Stream* m_stream;
		};

		inline StreamEmitter::StreamEmitter(Stream* stream)
		{
			m_stream = stream;
		}
	}



} /* namespace Art */

#endif /* SOURCE_ART_STRINGFORMATTER_H_ */
