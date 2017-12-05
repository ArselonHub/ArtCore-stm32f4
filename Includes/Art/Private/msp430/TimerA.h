/*
 * Timer1A.h
 *
 *  Created on: 17 �ub 2015
 *      Author: denizcan
 */

#ifndef ART_PRIVATE_MSP430_TIMER1A_H_
#define ART_PRIVATE_MSP430_TIMER1A_H_

#include <Art/Private/Pit.h>
#include <Art/Mcu.h>

namespace Art
{
	class TimerA : public Pit
	{
	public:
		virtual void powerUp();
		virtual void powerDown();
		virtual void open();
		virtual void enable();
		virtual void disable();
		virtual void clear();
		virtual void clearAndEnable();
		virtual UWord getValue();
		virtual void setValue(UWord value);
	protected:
		typedef MspTimerA Port;
		virtual Port* getPort() = 0;

	private:
	};

} /* namespace Art */

#include <Art/Private/msp430/TimerA0.h>

#endif /* TIMER1A_H_ */
