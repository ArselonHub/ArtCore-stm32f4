#ifndef ART_REQUESTER_H
#define ART_REQUESTER_H

#include <Art/Thread.h>

namespace Art
{	
	class Requester
	{
	public:
		Requester();
		void setThread(Thread* value);
		Thread* thread();
	private:
		Thread* thread_;
	};

	inline Requester::Requester()
	{
		thread_ = currentThread();
	}

	inline void Requester::setThread(Thread* value)
	{
		thread_ = value;
	}

	inline Thread* Requester::thread()
	{
		return thread_;
	}
}

#endif
