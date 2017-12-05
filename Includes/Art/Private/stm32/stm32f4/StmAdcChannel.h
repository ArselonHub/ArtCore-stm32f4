/*
 * StmAdcChannel.h
 *
 *  Created on: Jul 12, 2017
 *      Author: denizcan
 */

#ifndef ART_PRIVATE_STMADCCHANNEL_H_
#define ART_PRIVATE_STMADCCHANNEL_H_

#include <Art/AdcChannel.h>

namespace Art
{
	class StmAdcChannel : public AdcChannel
	{
	public:
		StmAdcChannel(const void* d);

		friend class StmAdc;
	};

	inline StmAdcChannel::StmAdcChannel(const void* d) : AdcChannel(d)
	{
	}

} /* namespace Art */

#endif /* SOURCE_ART_PRIVATE_STMADCCHANNEL_H_ */
