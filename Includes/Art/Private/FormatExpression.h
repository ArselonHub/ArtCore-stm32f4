/*
 * FormatterBase.h
 *
 *  Created on: Sep 4, 2015
 *      Author: denizcan
 */

#ifndef ART_PRIVATE_FORMATEXPRESSION_H_
#define ART_PRIVATE_FORMATEXPRESSION_H_

#include <Art/Str.h>
#include <Art/StringRef.h>
#include <Art/Private/Expression.h>

namespace Art
{
	namespace Private
	{
		class IntArgExpression;
		class FloatArgExpression;
		class StringRefArgExpression;

		class FormatExpression : public Expression
		{
		public:
			FormatExpression(FormatExpression* previous, Word alignment, Char fillChar);
			IntArgExpression arg(Int value);
			IntArgExpression arg(Int value, Word alignment, Char fillChar = ' ');
			IntArgExpression arg(Int value, NumericFormat format,
				Word alignment = 0, Char fillChar = ' ');
			FloatArgExpression arg(Float value, Word precision = 7, Word alignment = 0);
			StringRefArgExpression arg(const StringRef& s);
		protected:
			virtual Word apply(Emitter* emitter) const;
			virtual Word applyArg(Emitter* emitter) const = 0;
			virtual const StringRef formatString() const;

			FormatExpression* m_previous;
			Short	m_alignment;
			Char	m_fillChar;
		};

		class IntArgExpression : public FormatExpression
		{
		public:
			IntArgExpression(FormatExpression* previous, Int value, NumericFormat format,
				Word alignment, Char fillChar);
		protected:
			virtual Word applyArg(Emitter* emitter) const;
			Int m_value;
			NumericFormat m_format;
		};

		class FloatArgExpression : public FormatExpression
		{
		public:
			FloatArgExpression(FormatExpression* previous, Float value, Char format, Word precision,
				Word alignment, Char fillChar);
		protected:
			virtual Word applyArg(Emitter* emitter) const;
			Float value_;
			Word precision_;
		};

		class StringRefArgExpression : public FormatExpression
		{
		public:
			StringRefArgExpression(FormatExpression* previous,
					const StringRef& value, Word alignment, Char fillChar);
		protected:
			virtual Word applyArg(Emitter* emitter) const;
			StringRef m_value;
		};

		class IntHeaderExpression : public IntArgExpression
		{
		public:
			IntHeaderExpression(const StringRef* formatString,
					Int value, NumericFormat numericFormat, Word alignment, Char fillChar);
		protected:
			virtual const StringRef formatString() const;
		private:
			StringRef	m_formatString;
		};

		class FloatHeaderExpression : public FloatArgExpression
		{
		public:
			FloatHeaderExpression(const StringRef* formatString,
				Float value, Char format, Word precision,
				Word alignment, Char fillChar);
		protected:
			virtual const StringRef formatString() const;
		private:
			StringRef	m_formatString;
		};

		class StringRefHeaderExpression : public StringRefArgExpression
		{
		public:
			StringRefHeaderExpression(const StringRef* formatString,
					const StringRef& value, Word alignment, Char fillChar);
		protected:
			virtual const StringRef formatString() const;
		private:
			StringRef	m_formatString;
		};

		inline IntArgExpression::IntArgExpression(FormatExpression* previous,
			Int value, NumericFormat base,
			Word alignment, Char fillChar)
			: FormatExpression(previous, alignment, fillChar)
		{
			m_value = value;
			m_format = base;
		}

		inline FloatArgExpression::FloatArgExpression(FormatExpression* previous,
				Float value, Char format,
				Word precision, Word alignment, Char fillChar)
			: FormatExpression(previous, alignment, fillChar)
		{
			value_ = value;
			precision_ = precision;
		}

		inline StringRefArgExpression::StringRefArgExpression(FormatExpression* previous,
				const StringRef& value,
				Word alignment, Char fillChar)
			: FormatExpression(previous, alignment, fillChar)
		{
			m_value = value;
		}
	}
}

#endif /* SOURCE_ART_FORMAT_H_ */
