/*
 * CaptureChannel-lpc.h
 *
 *  Created on: May 22, 2016
 *      Author: denizcan
 */

#ifndef ART_PRIVATE_LPC_CAPTURECHANNEL_LPC_H_
#define ART_PRIVATE_LPC_CAPTURECHANNEL_LPC_H_

#include <Art/CoreEdgeDetector.h>
#include <Art/Private/PitChannel.h>

namespace Art
{
	class CaptureChannel : public Private::PitChannel
	{
	public:
		Edge edge() const;
		void setEdge(Edge edge);
		void stop();
		void setSingleShot(Bool value);
	};

} /* namespace Art */

#endif /* SOURCE_ART_PRIVATE_LPC_CAPTURECHANNEL_LPC_H_ */
