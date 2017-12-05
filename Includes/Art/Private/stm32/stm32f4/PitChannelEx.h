/*
 * PitChannelEx.h
 *
 *  Created on: May 10, 2017
 *      Author: denizcan
 */

#ifndef SOURCE_ART_PRIVATE_STM32_STM32F4_PITCHANNELPORTEX_H_
#define SOURCE_ART_PRIVATE_STM32_STM32F4_PITCHANNELPORTEX_H_

#include <Art/Private/stm32/stm32f4/PitChannel.h>

namespace Art
{
	class CoreCaptureDetector;
	class CoreMatchDetector;

	namespace Private
	{
		class PitChannelEx : public PitChannel
		{
		public:
			void clear();
			void clearAndEnable();

		private:
			void registerDetector(Private::Detector* detector);
			void unregisterDetector(Private::Detector* detector);
			void enableIrq();
			void disableIrq();

			friend class Art::CoreCaptureDetector;
			friend class Art::CoreMatchDetector;
		};

		inline void PitChannelEx::clear()
		{
			((CompositeChannel*)this)->clear();
		}

		inline void PitChannelEx::clearAndEnable()
		{
			((CompositeChannel*)this)->clearAndEnable();
		}

		inline void PitChannelEx::registerDetector(Private::Detector* detector)
		{
			((CompositeChannel*)this)->registerDetector(detector);
		}

		inline void PitChannelEx::unregisterDetector(Private::Detector* detector)
		{
			((CompositeChannel*)this)->unregisterDetector(detector);
		}

		inline void PitChannelEx::enableIrq()
		{
			((CompositeChannel*)this)->enableIrq();
		}

		inline void PitChannelEx::disableIrq()
		{
			((CompositeChannel*)this)->disableIrq();
		}
	} /* namespace Private */
} /* namespace Art */

#endif /* SOURCE_ART_PRIVATE_STM32_STM32F4_PITCHANNELPORTEX_H_ */
