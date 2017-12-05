/*
 * PitChannel.h
 *
 *  Created on: Jan 19, 2017
 *      Author: denizcan
 */

#ifndef ART_PRIVATE_STM32_STM32F4_COMPOSITECHANNEL_H_
#define ART_PRIVATE_STM32_STM32F4_COMPOSITECHANNEL_H_

#include <Art/Types.h>
#include <Art/Private/Detector.h>

namespace Art
{
	class CaptureChannel;
	class MatchChannel;
	class PulseChannel;

	namespace Private
	{
		class PitChannel;
		class PitChannelEx;
	}

	enum PitChannelMode
	{
		PitChannelModeCapture,
		PitChannelModeMatch,
		PitChannelModePulse
	};

	enum CompositeOutputMode
	{
		CompositeOutputModeNone,
		CompositeOutputModeSet,
		CompositeOutputModeClear,
		CompositeOutputModeToggle,
		CompositeOutputModeForceCleared,
		CompositeOutputModeForceSet,
		CompositeOutputModePwm,
		CompositeOutputModePwmInverted
	};

	enum CaptureSource
	{
		CaptureSourceLower = 1,
		CaptureSourceUpper,
		CaptureSourceTRC
	};

	enum CaptureEdge
	{
		CaptureEdgeRising = 1,
		CaptureEdgeFalling = 2,
		CaptureEdgeBoth = 3
	};

	class CompositeChannel
	{
	public:
		UWord value();
		void enable();
		void disable();
		void clear();
		void clearAndEnable();

		CaptureChannel* asCaptureChannel();
		MatchChannel* asMatchChannel();
		PulseChannel* asPulseChannel();

		PitChannelMode mode();
		void setMode(PitChannelMode value);

		// Match
		void setValue(UWord value);
		void stepForward(UWord value);
		void stepAhead(UWord value);
		void setOutputValue(Bool value);
		void setOutputMode(CompositeOutputMode value);

		// capture
		CaptureEdge captureEdge();
		CaptureSource captureSource();
		void setCaptureEdge(CaptureEdge value);
		void setCaptureSource(CaptureSource value);

	private:
		void enableIrq();
		void disableIrq();
		void registerDetector(Private::Detector* detector);
		void unregisterDetector(Private::Detector* detector);

		friend class CaptureChannel;
		friend class MatchChannel;
		friend class Private::PitChannel;
		friend class Private::PitChannelEx;
	};
} /* namespace Art */

#endif
