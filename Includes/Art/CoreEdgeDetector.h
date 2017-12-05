#ifndef ART_EDGEDETECTORBASE_H
#define ART_EDGEDETECTORBASE_H

#include <Art/Pin.h>
#include <Art/Private/Detector.h>

namespace Art
{
	enum Edge
	{
		EdgeRising = 1,
		EdgeFalling = 2,
		EdgeBoth = 3
	};

	class CoreEdgeDetector : public Private::Detector
	{
	public:
		CoreEdgeDetector();
		Edge edge() const;
		Word setEdge(Edge edge);

		Pin* pin() const;
		Word setPin(Pin* pin);

	private:
		virtual Word openDevice();
		virtual Word closeDevice();
		virtual Word enableDevice();
		virtual Word disableDevice();

		Word updateEdge();

		Pin*	m_pin;
		Edge	m_edge;
	};

	inline Edge CoreEdgeDetector::edge() const
	{
		return m_edge;
	}

	inline Art::Pin* CoreEdgeDetector::pin() const
	{
		return m_pin;
	}
}

#endif
