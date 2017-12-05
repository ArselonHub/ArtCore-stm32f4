/*
 * Pit-lpc112x.h
 *
 *  Created on: 4 Şub 2015
 *      Author: denizcan
 */

#ifndef ART_LPC_LPC112X_PIT_LPC112X_H_
#define ART_LPC_LPC112X_PIT_LPC112X_H_

#include <Art/lpc/Pit-lpc.h>

extern "C" void TIMER_16_0_IRQHandler();

namespace Art
{
	class Timer16B0 : public Pit
	{
	public:
		Timer16B0();
		virtual void powerUp();
		virtual void powerDown();
	protected:
		virtual Port* getPort();
	private:
		static const Info infos[];

		friend void ::TIMER_16_0_IRQHandler();
	};

	extern Timer16B0 timer16b0;
}

#endif /* ART_LPC_LPC112X_PIT_LPC112X_H_ */
