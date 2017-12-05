/*
 * AbstractCompareChannel.h
 *
 *  Created on: 24 �ub 2015
 *      Author: denizcan
 */

#ifndef ART_ABSTRACTCOMPARECHANNEL_H_
#define ART_ABSTRACTCOMPARECHANNEL_H_

#include <Art/Private/AbstractPitChannel.h>

namespace Art
{
	enum OutputAction
	{
		OutputActionNothing,
		OutputActionClear,
		OutputActionSet,
		OutputActionToggle
	};

	class AbstractIntervalGenerator : public Private::AbstractPitChannel
	{
	public:
		void setValue(UShortL value);
		void stepAhead(UShortL value);
		void stepForward(UShortL value);
		UShortL getValue();
		void setOutputAction(OutputAction value);
	protected:
		void open();
	};

} /* namespace Art */
#endif /* ABSTRACTCOMPARECHANNEL_H_ */
