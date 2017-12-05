/*
 * StringRef.h
 *
 *  Created on: May 7, 2016
 *      Author: denizcan
 */

#ifndef ART_STRINGREF_H_
#define ART_STRINGREF_H_

#include <Art/Private/StringBase.h>

namespace Art
{
	class StringRef : public Private::StringBase
	{
	public:
		StringRef();
		StringRef(const StringBase& s);
		StringRef(const Char* s);
		StringRef(const Char* s, Word length);
		StringRef(const Char* s, const Char* e);
	};

	inline StringRef::StringRef()
	{
		m_pointer = 0;
		m_length = 0;
	}

	inline StringRef::StringRef(const StringBase& s)
	{
		m_pointer = s.m_pointer;
		m_length = s.m_length;

	}

	inline StringRef::StringRef(const Char* s, Word length)
	{
		m_pointer = (Char*)s;
		m_length =  length;
	}

	inline StringRef::StringRef(const Char* s, const Char* e)
	{
		m_pointer = (Char*)s;
		m_length = e - s;
	}
}

#include <Art/Private/FormatExpression.h>
#include <Art/Private/StringExpression.h>

#endif /* SOURCE_ART_STRINGREF_H_ */
