/*
 * TimerA0.h
 *
 *  Created on: 25 �ub 2015
 *      Author: denizcan
 */

#ifndef ART_PRIVATE_MSP430_TIMERA0_H_
#define ART_PRIVATE_MSP430_TIMERA0_H_

#include <Art/Private/msp430/TimerA.h>

namespace Art
{
	class TimerA0 : public TimerA
	{
	public:
		TimerA0();
		static PitResource channel0;
		static PitResource channel1;

	protected:
		virtual Port* getPort();
		static void handleInterrupt();
	private:
		Private::AbstractPitChannel* channelLink0;
		Private::AbstractPitChannel* channelLink1;
		Private::AbstractPitChannel* channelLink2;
		Private::AbstractPitChannel* channelLink3;
		Private::AbstractPitChannel* channelLink4;
	};

	extern TimerA0 timerA0;

}


#endif /* TIMERA0_H_ */
