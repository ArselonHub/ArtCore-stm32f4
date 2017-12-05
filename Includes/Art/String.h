/*
 * String.h
 *
 *  Created on: May 8, 2016
 *      Author: denizcan
 */

#ifndef ART_STRING_H_
#define ART_STRING_H_

#include <Art/Private/StringBase.h>
#include <Art/StringRef.h>

namespace Art
{
	class String : public Private::StringBase
	{
	public:
		String();
		String(const Char* s);
		String(const Char* s, const Char* e);
		String(const String& s);
		String(const StringRef& s);
		String(const Expression& e);
		~String();

		Word assign(const Char* s);
		Word assign(const String& s);
		Word assign(const StringRef& s);
		Word assign(const Expression& e);
		Bool isEmpty();
		Bool isNotEmpty();
		void clear();

		void operator =(const Char* s);
		void operator =(const String& s);
		void operator =(const StringRef& s);
		void operator =(const Expression& e);

		static String fromShort(Int value, NumericFormat format = NumericFormatDecimal);
		static String fromUShort(Int value, NumericFormat format = NumericFormatDecimal);
		static String fromUInt(Int value, NumericFormat format = NumericFormatDecimal);
		static String fromInt(Int value, NumericFormat format = NumericFormatDecimal);

		operator const StringRef&() const;
	private:
		static void removeReference(Char* p);
		Word construct(Word length);
		Word constructFrom(const Char* s);
		Word constructFrom(const String& s);
		Word constructFrom(const StringRef& s);
		Word constructFrom(const Char* s, Word length);
		Word constructFrom(const Expression& e, Word length);

	};

	inline String::String()
	{
		m_pointer = 0;
		m_length = 0;
	}

	inline String::String(const Char* s)
	{
		constructFrom(s);
	}

	inline String::String(const Char* s, const Char* e)
	{
		constructFrom(s, e - s);
	}

	inline String::String(const String& s)
	{
		constructFrom(s);
	}

	inline String::String(const StringRef& s)
	{
		constructFrom(s);
	}

	inline String::~String()
	{
		removeReference(m_pointer);
	}


	inline void String::operator =(const Char* s)
	{
		assign(s);
	}

	inline void String::operator =(const String& s)
	{
		assign(s);
	}

	inline void String::operator =(const StringRef& s)
	{
		assign(s);
	}

	inline void String::operator =(const Expression& e)
	{
		assign(e);
	}

	inline Bool String::isEmpty()
	{
		return m_length == 0;
	}

	inline Bool String::isNotEmpty()
	{
		return m_length != 0;
	}

	inline String::operator const StringRef&() const
	{
		return *((const StringRef*)this);
	}
}

//#include <Art/Private/StringExpression.h>

#endif /* STRING_H_ */
