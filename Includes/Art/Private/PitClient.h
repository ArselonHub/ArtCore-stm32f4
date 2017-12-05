/*
 * PitClient.h
 *
 *  Created on: May 9, 2017
 *      Author: denizcan
 */

#ifndef SOURCE_ART_PRIVATE_PITCLIENT_H_
#define SOURCE_ART_PRIVATE_PITCLIENT_H_

#include <Art/BasicList.h>

namespace Art
{
	namespace Private
	{
		class PitClient
		{
		private:
			virtual void configurePort() = 0;
			PitClient* m_next;
			PitClient* m_previous;

			friend class BasicList<PitClient>;
		};

	} /* namespace Private */
} /* namespace Art */

#endif /* SOURCE_ART_PRIVATE_STM32_STM32F4_PITCLIENT_H_ */
