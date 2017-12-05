/*
 * StmPit.h
 *
 *  Created on: Jan 18, 2017
 *      Author: denizcan
 */

#ifndef SOURCE_ART_PRIVATE_STM32_STM32F4_STMTIM_H_
#define SOURCE_ART_PRIVATE_STM32_STM32F4_STMTIM_H_

#include <Art/Device.h>
#include <Art/Thread.h>
#include <Art/Private/Monitor.h>
#include <Art/Private/stm32/stm32f4/CompositeChannel.h>
#include <Art/Private/stm32/stm32f4/PitChannelStub.h>

namespace Art
{
	enum PwmMode
	{
		PwmModeEdgeAligned,
		PwmModeCenterAligned1,
		PwmModeCenterAligned2,
		PwmModeCenterAligned3
	};

	class StmTim : public Device
	{
	public:
		StmTim(const void* d);
		virtual ~StmTim();
		Word prescaler();
		void setPrescaler(Word value);
		Word period();
		void setPeriod(Word value);
		PwmMode pwmMode();
		void setPwmMode(PwmMode value);
		Word clockFrequency() const;
		void setClockFrequency(Word frequency);
	protected:
		virtual Word openDevice();
		virtual Word closeDevice();
		virtual Word enableDevice();
		virtual Word disableDevice();
		void processInterrupt();

		const void*		m_d;
	private:
		void updatePrescaler();

		Word				m_period;
		Word				m_prescaler;
		Word				m_clockFrequency;
		Private::Monitor	m_monitor;

		friend class ::Art::CompositeChannel;
		friend class ::Art::Private::PitChannel;
	};

} /* namespace Art */

#endif /* SOURCE_ART_PRIVATE_STM32_STM32F4_STMTIM_H_ */
