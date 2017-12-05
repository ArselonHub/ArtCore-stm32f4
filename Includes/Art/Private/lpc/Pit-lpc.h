/*
 * LpcTim.h
 *
 *  Created on: May 22, 2016
 *      Author: denizcan
 */

#ifndef SOURCE_ART_PRIVATE_LPC_PIT_LPC_H_
#define SOURCE_ART_PRIVATE_LPC_PIT_LPC_H_

#include <Art/Mcu.h>
#include <Art/Private/Monitor.h>

namespace Art
{
	class Pit : protected Private::Monitor
	{
	public:
		Pit(LPC_TIM_TypeDef* port);
		void start();
		void stop();
		void reset();
		void holdReset();
		void releaseReset();
		void powerUp();
		void powerDown();

	protected:
		UWord		singleShotMap_;
	private:
		virtual void powerUpPort() = 0;
		virtual void powerDownPort() = 0;
		virtual void enableInterruptPort() = 0;
		virtual void disableInterruptPort() = 0;

		LPC_TIM_TypeDef*	port_;

		friend class CoreCaptureDetector;
		friend class CoreMatchDetector;
	};

	inline Pit::Pit(LPC_TIM_TypeDef* port)
	{
		port_ = port;
	}
}


#endif /* SOURCE_ART_PRIVATE_LPC_PIT_LPC_H_ */
