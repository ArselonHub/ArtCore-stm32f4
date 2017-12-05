/*
 * Emitter.h
 *
 *  Created on: May 10, 2016
 *      Author: denizcan
 */

#ifndef ART_PRIVATE_EMITTER_H_
#define ART_PRIVATE_EMITTER_H_

#include <Art/StringRef.h>
#include <Art/Private/Expression.h>

namespace Art
{
	namespace Private
	{
		class Emitter
		{
		public:
			Word emitExpression(const Expression& e);
			virtual Word emitChar(Char c, Word length) = 0;
			virtual Word emitStringRef(const StringRef& s) = 0;
			Word emitString(const StringRef& s, Word alignment, Char fillChar);
		};

		inline Word Emitter::emitExpression(const Expression& e)
		{
			return e.apply(this);
		}

	} /* namespace Private */
} /* namespace Art */

#endif /* SOURCE_ART_PRIVATE_EMITTER_H_ */
