/*
 * StringFormatter.h
 *
 *  Created on: Aug 21, 2015
 *      Author: denizcan
 */

#ifndef ART_STRINGFORMATTER_H_
#define ART_STRINGFORMATTER_H_

#include <Art/Private/Emitter.h>

namespace Art
{
	namespace Private
	{
		class StringEmitter : public Emitter
		{
		public:
			StringEmitter(Char* buffer);
			virtual Word emitChar(const Char c, Word length);
			virtual Word emitStringRef(const StringRef& s);
			Char* buffer() const;
		private:
			Char* buffer_;
		};

		inline StringEmitter::StringEmitter(Char* buffer)
		{
			buffer_ = buffer;
		}

		inline Char* StringEmitter::buffer() const
		{
			return buffer_;
		}
	}

} /* namespace Art */

#endif /* SOURCE_ART_STRINGFORMATTER_H_ */
