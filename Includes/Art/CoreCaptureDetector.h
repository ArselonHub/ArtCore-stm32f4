/*
 * CaptureDetectorBase.h
 *
 *  Created on: May 28, 2016
 *      Author: denizcan
 */

#ifndef ART_CORECAPTUREDETECTOR_H_
#define ART_CORECAPTUREDETECTOR_H_

#include <Art/Pit.h>
#include <Art/Private/Detector.h>

namespace Art
{
	class CoreCaptureDetector : public Private::Detector
	{
	public:
		CoreCaptureDetector();
		CaptureChannel* channel() const;
		void setChannel(CaptureChannel* value);

		UWord value() const;
		CaptureEdge edge() const;
		void setEdge(CaptureEdge value);
	private:
		virtual Word openDevice();
		virtual Word closeDevice();
		virtual Word enableDevice();
		virtual Word disableDevice();

		CaptureChannel*	m_channel;
		CaptureEdge		m_edge;
	};

	inline CoreCaptureDetector::CoreCaptureDetector()
	{
		m_channel = 0;
		m_edge = CaptureEdgeRising;
	}

	inline CaptureChannel* CoreCaptureDetector::channel() const
	{
		return m_channel;
	}

	inline UWord CoreCaptureDetector::value() const
	{
		return m_channel->value();
	}

	inline CaptureEdge CoreCaptureDetector::edge() const
	{
		return m_edge;
	}
} /* namespace Art */

#endif /* SOURCE_ART_CORECAPTUREDETECTOR_H_ */
