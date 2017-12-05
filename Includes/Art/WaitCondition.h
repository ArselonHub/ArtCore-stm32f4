#ifndef ART_WAITCONDITION_H
#define ART_WAITCONDITION_H

#include <Art/Delay.h>
#include <Art/Mutex.h>
#include <Art/Types.h>

namespace Art
{	
	class WaitCondition : public Private::WaitObject
	{
	public:
		Word wait(Mutex* mutex);
		Word wait(Mutex* mutex, Word timeout);
		void wakeOne();
		void wakeAll();	
	private:
		static void waitMutexSvc(WaitCondition* waitCondition,
				Mutex* mutex, Private::WaitLink* waitLink, Word timeout);
		static void wakeOneSvcImp(WaitCondition* waitCondition);
		static void wakeAllSvcImp(WaitCondition* waitCondition);
	private:		
		friend class Dispatcher;
	};
}

#endif
