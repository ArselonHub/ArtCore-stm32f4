/*
 * MatchDetectorBase.h
 *
 *  Created on: May 22, 2016
 *      Author: denizcan
 */

#ifndef SOURCE_ART_COREMATCHDETECTOR_H_
#define SOURCE_ART_COREMATCHDETECTOR_H_

#include <Art/Pit.h>

namespace Art
{
	class CoreMatchDetector : public Private::Detector
	{
	public:
		CoreMatchDetector();
		MatchChannel* channel();
		void setChannel(MatchChannel* channel);

		UWord value();
		void setValue(UWord value);
		void stepAhead(UWord value);
		void stepForward(UWord value);
	private:
		virtual Word openDevice();
		virtual Word closeDevice();
		virtual Word enableDevice();
		virtual Word disableDevice();

		MatchChannel* m_channel;
	};

	inline CoreMatchDetector::CoreMatchDetector()
	{
		m_channel = 0;
	}

	inline MatchChannel* CoreMatchDetector::channel()
	{
		return m_channel;
	}

	inline void CoreMatchDetector::setChannel(MatchChannel* value)
	{
		m_channel = value;
	}

} /* namespace Art */

#endif /* SOURCE_ART_COREMATCHDETECTOR_H_ */
