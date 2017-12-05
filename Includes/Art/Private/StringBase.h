/*
 * StringBase.h
 *
 *  Created on: May 7, 2016
 *      Author: denizcan
 */

#ifndef ART_STRINGBASE_H_
#define ART_STRINGBASE_H_

#include <Art/Types.h>
#include <Art/Str.h>

namespace Art
{
	class StringRef;
	class String;

	namespace Private
	{

		class IntHeaderExpression;
		class FloatHeaderExpression;
		class StringRefHeaderExpression;

		class StringBase
		{
		public:
			Word isEmpty() const;
			Word isEqualTo(const Char* s) const;
			Word isEqualTo(const StringBase& s) const;

			StringRef left(Word length) const;
			StringRef right(Word length) const;
			StringRef subString(Word offset, Word length) const;
			Word startsWith(const Char* s) const;
			Word startsWith(const StringBase& s) const;
			Word hasChar(const Char value) const;

			Char* pointer() const;
			Word length() const;

			Word operator ==(const Char* s) const;
			Word operator ==(const StringBase& s) const;
			Word operator [](Word index) const;

			IntHeaderExpression arg(Int value);
			IntHeaderExpression arg(Int value, Word alignment, Char fillChar = ' ');
			IntHeaderExpression arg(Int value, NumericFormat format,
				Word alignment = 0, Char fillChar = ' ');
			FloatHeaderExpression arg(Float value, Word precision = 7, Word alignment = 0);
			StringRefHeaderExpression arg(const StringRef& s);
		protected:
			Char*	m_pointer;
			Word	m_length;

			friend class ::Art::String;
			friend class ::Art::StringRef;
		};

		inline Word StringBase::isEmpty() const
		{
			return m_length == 0;
		}

		inline Word StringBase::length() const
		{
			return m_length;
		}

		inline Char* StringBase::pointer() const
		{
			return m_pointer;
		}

		inline Word StringBase::operator ==(const Char* s) const
		{
			return isEqualTo(s);
		}

		inline Word StringBase::operator ==(const StringBase& s) const
		{
			return isEqualTo(s);
		}
	}
}

#endif /* SOURCE_ART_STRINGBASE_H_ */
