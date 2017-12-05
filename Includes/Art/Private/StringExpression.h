/*
 * StringOperator.h
 *
 *  Created on: May 10, 2016
 *      Author: denizcan
 */

#ifndef ART_PRIVATE_STRINGEXPRESSION_H_
#define ART_PRIVATE_STRINGEXPRESSION_H_

#include <Art/Private/Expression.h>
#include <Art/StringRef.h>
#include <Art/Types.h>

namespace Art
{
	namespace Private
	{
		class StringStringExpression : public Expression
		{
		public:
			StringStringExpression(const StringRef& left, const StringRef& right);
			virtual ~StringStringExpression();

		private:
			virtual Word apply(Private::Emitter* emitter) const;

			StringRef	m_left;
			StringRef	m_right;
		};

		class ExpressionStringExpression : public Expression
		{
		public:
			ExpressionStringExpression(const Expression& left, const StringRef& right);
			virtual ~ExpressionStringExpression();

		private:
			virtual Word apply(Private::Emitter* emitter) const;

			const Expression*	m_left;
			StringRef	m_right;
		};

		class ExpressionExpressionExpression : public Expression
		{
		public:
			ExpressionExpressionExpression(const Expression& left, const Expression& right);
			virtual ~ExpressionExpressionExpression();

		private:
			virtual Word apply(Private::Emitter* emitter) const;

			const Expression*	m_left;
			const Expression* m_right;
		};

		inline StringStringExpression::~StringStringExpression()
		{
		}

		inline ExpressionStringExpression::~ExpressionStringExpression()
		{
		}

		inline ExpressionExpressionExpression::~ExpressionExpressionExpression()
		{
		}
	}

	extern Private::StringStringExpression operator +(const StringRef& left,
			const Char* right);

	extern Private::StringStringExpression operator +(const Char* left,
			const StringRef& right);

	extern Private::StringStringExpression operator +(const StringRef& left,
			const StringRef& right);

	extern Private::ExpressionStringExpression operator +(const Expression& left,
			const Char* right);

	extern Private::ExpressionStringExpression operator +(const Expression& left,
			const StringRef&  right);
}

#endif /* SOURCE_ART_PRIVATE_STRINGOPERATOR_H_ */
