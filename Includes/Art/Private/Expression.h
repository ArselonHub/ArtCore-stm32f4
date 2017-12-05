/*
 * StringExpression.h
 *
 *  Created on: May 10, 2016
 *      Author: denizcan
 */

#ifndef ART_PRIVATE_EXPRESSION_H_
#define ART_PRIVATE_EXPRESSION_H_

#include <Art/Types.h>

namespace Art
{
	namespace Private
	{
		class Emitter;
		class ExpressionStringExpression;
		class ExpressionExpressionExpression;
	}

	class Expression
	{
	public:
		virtual ~Expression();
	private:
		virtual Word apply(Private::Emitter* emitter) const = 0;

		friend class Private::Emitter;
		friend class Private::ExpressionStringExpression;
		friend class Private::ExpressionExpressionExpression;
	};

	inline Expression::~Expression()
	{
	}

} /* namespace Art */

#endif /* SOURCE_ART_PRIVATE_STRINGEXPRESSION_H_ */
