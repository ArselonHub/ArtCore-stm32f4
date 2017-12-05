/*
 * StringFormatter.h
 *
 *  Created on: Aug 21, 2015
 *      Author: denizcan
 */

#ifndef ART_PRIVATE_NULLEMITTER_H_
#define ART_PRIVATE_NULLEMITTER_H_

#include <Art/Private/Emitter.h>

namespace Art
{
	class String;

	namespace Private
	{
		class NullEmitter : public Emitter
		{
		public:
			NullEmitter();
			NullEmitter(String* s);
			virtual Word emitChar(const Char c, Word length);
			virtual Word emitStringRef(const StringRef& s);
			Word length() const;
			Word referenceLevel() const;
		private:
			Word length_;
			Word referenceLevel_;
			Char* head_;
			Char* tail_;
		};

		inline NullEmitter::NullEmitter()
		{
			length_ = 0;
			referenceLevel_ = -1;
		}

		inline Word NullEmitter::length() const
		{
			return length_;
		}

		inline Word NullEmitter::referenceLevel() const
		{
			return referenceLevel_;
		}

	}

} /* namespace Art */

#endif /* SOURCE_ART_STRINGFORMATTER_H_ */
