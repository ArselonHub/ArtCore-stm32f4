/*
 * Mutex.h
 *
 *  Created on: 27 Oca 2014
 *      Author: denizcan
 */

#ifndef ART_MUTEX_H_
#define ART_MUTEX_H_


#include <Art/Private/WaitObject.h>
#include <Art/Thread.h>
#include <Art/Types.h>

namespace Art
{
	class Mutex : public Private::WaitObject
    {
	public:
		Mutex();
		Word lock();
		Word tryLock();
		Word tryLock(Word timeout);
		Word unlock();
    private:		
		static void tryLockSvcImp(Mutex* mutex, Thread* thread);
		static void lockSvcImp(Mutex* mutex, Private::WaitLink* waitLink, Word timeout);

		static void unlockSvcImp(Mutex* mutex, Thread* thread, Word* result);
	private:
		Thread*	m_thread;
		UWord	m_lockCount;
	
		friend class WaitCondition;
	};

}

#endif /* MUTEX_H_ */
