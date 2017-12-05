/*
 * PulseChannel-lpc.h
 *
 *  Created on: May 22, 2016
 *      Author: denizcan
 */

#ifndef ART_PRIVATE_LPC_PULSECHANNEL_LPC_H_
#define ART_PRIVATE_LPC_PULSECHANNEL_LPC_H_

#include <Art/Private/lpc/MatchChannel-lpc.h>

namespace Art
{
	enum PulseAction
	{
		PulseActionNone,
		PulseActionClear,
		PulseActionSet,
		PulseActionToggle
	};

	class PulseChannel : public MatchChannel
	{
	public:
		Bool output();
		void setOutput(Bool value);
		PulseAction pulseAction();
		void setPulseAction(PulseAction value);
	};

} /* namespace Art */

#endif /* SOURCE_ART_PRIVATE_LPC_PULSECHANNEL_LPC_H_ */
