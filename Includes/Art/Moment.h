/*
 * Moment.h
 *
 *  Created on: Oct 27, 2016
 *      Author: denizcan
 */

#ifndef SOURCE_ART_MOMENT_H_
#define SOURCE_ART_MOMENT_H_

#include <Art/Types.h>

namespace Art
{
	class Moment
	{
	public:
		const Moment& current();
		Bool operator >(const Moment& r);
	private:
		Long	m_value;
	};

	inline Bool Moment::operator >(const Moment& r)
	{
		return m_value > r.m_value;
	}

} /* namespace Art */

#endif /* SOURCE_ART_MOMENT_H_ */
