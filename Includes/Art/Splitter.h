/*
 * Tokenizer.h
 *
 *  Created on: 28 Nis 2014
 *      Author: denizcan
 */

#ifndef ART_SPLITTER_H_
#define ART_SPLITTER_H_

#include <Art/StringRef.h>

namespace Art
{


	class Splitter
	{
	public:
		Splitter(const StringRef& string);
		Splitter(const StringRef& string, const StringRef seperators);
		Word next();
		StringRef value();
		Bool isAtEnd() const;
	protected:
		StringRef m_string;
		StringRef m_seperators;
		Word	m_head;
		Word	m_tail;
		Word	m_index;
	};

} /* namespace Art */
#endif /* TOKENIZER_H_ */
