/*
 * MatchChannel-lpc.h
 *
 *  Created on: May 22, 2016
 *      Author: denizcan
 */

#ifndef ART_PRIVATE_LPC_MATCHCHANNEL_LPC_H_
#define ART_PRIVATE_LPC_MATCHCHANNEL_LPC_H_

#include <Art/Private/PitChannel.h>

namespace Art
{
	enum MatchAction
	{
		MatchActionReset = (1 << 1),
		MatchActionStop = (1 << 2),
		MatchActionResetStop = MatchActionReset | MatchActionStop
	};
	ENUMFLAGS(MatchAction)

	class MatchChannel : public Private::PitChannel
	{
	public:
		MatchAction matchAction();
		void setValue(UWord value);
		void stepAhead(UWord delta);
		void stepForward(UWord delta);
		void setMatchAction(MatchAction value);
	};

} /* namespace Art */

#endif /* SOURCE_ART_PRIVATE_LPC_MATCHCHANNEL_LPC_H_ */
