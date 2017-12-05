/*
 * Loop.h
 *
 *  Created on: Dec 24, 2016
 *      Author: denizcan
 */

#ifndef SOURCE_ART_LOOP_H_
#define SOURCE_ART_LOOP_H_

#include <Art/Types.h>

namespace Art
{
	class Loop
	{
	public:
		Word execute();
		Word exit(Word result);
		Bool isRunning();
		Word result();
	private:
		Word m_result;
		volatile Bool m_running;

	};

	inline Bool Loop::isRunning()
	{
		return m_running;
	}

	inline Word Loop::result()
	{
		return m_result;
	}

} /* namespace Art */

#endif /* SOURCE_ART_LOOP_H_ */
