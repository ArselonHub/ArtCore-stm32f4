#ifndef ART_DEBUGSTREAM_H
#define ART_DEBUGSTREAM_H

#include <Art/Requester.h>
#include <Art/RingBuffer.h>
#include <Art/Stream.h>

namespace Art
{
	//class DebugStream;
	//inline DebugStream* debugStream();
	
	class DebugStream : public Stream
	{
	public:
		virtual ShortL read(void* buffer, ShortL length);
        virtual ShortL skipBytes(ShortL length);
		virtual ShortL bytesToRead();
		virtual ShortL bytesToWrite();
		virtual ShortL write(const void* buffer, ShortL length);

		void setRxBuffer(void* buffer, ShortL length);
		void setTxBuffer(void* buffer, ShortL length);
		void processSvc();
		void open();
		
	protected:
	
	private:			
//		class Timer : public AbstractTimer
//		{
//		protected:
//			virtual void doTimeoutSvc();
//		};
	
		RingBuffer	rxBuffer;
		RingBuffer	txBuffer;
		//Timer		timer;
		Bool	dataReady:1;
		Bool	dataTransmitted:1;
	
		static DebugStream instance;
		friend DebugStream* debugStream();
	};

	inline void DebugStream::setRxBuffer(void* buffer, ShortL length)
	{
		rxBuffer.setBuffer(buffer, length);
	}

	inline void DebugStream::setTxBuffer(void* buffer, ShortL length)
	{
		txBuffer.setBuffer(buffer, length);
	}

	inline DebugStream* debugStream()
	{
		return &DebugStream::instance;
	}
}

#endif
