#ifndef ART_THREAD_H
#define ART_THREAD_H

#include <Art/BasicQueue.h>
#include <Art/Private/WaitHandler.h>
#include <Art/Task.h>
#include <Art/Utility.h>

/**
 * \defgroup Art
 */

/**
 * \defgroup Threading
 * \ingroup Art
 */

namespace Art
{
	namespace Private
	{
		class Signal;
		class WaitLink;
	}

	/**
	 * \brief Predefined priority levels
	 * \ingroup Threading
	 */
	enum ThreadPriority
	{
		ThreadPriorityLowest = 1,	///< Lowest priority
		ThreadPriorityLower,		///< Lower than normal priority
		ThreadPriorityNormal,		///< Normal priority, this is defined as default
		ThreadPriorityHigher,		///< Higher than normal priority
		ThreadPriorityHighest		///< Highest priority, this will cause immediate switch
	};

	/**
	 * Current state of a Thread
	 */
	enum ThreadState
	{
		ThreadStateIdle,
		ThreadStateWaiting,
		ThreadStateWaitingTask,
		ThreadStateReady,
		ThreadStateRunning
	};

	/**
	 * \brief Core threading class
	 * \ingroup Threading
	 */
	class Thread
	{
	public:
		Thread();
		Thread(void* stack, UWord size);
		void setStack(void* stack, UWord size);
		void setName(const Char* value);
		void setPriority(ThreadPriority value);
		void enqueue(Task* task);
		void enqueueSvc(Task* task);
		void enqueue(void(*function)());

		template <class A0>
		void enqueue(void(*function)(A0), A0 arg0);


		static Word run();
		static void suspend();
		static Word sleep(Word timeout);

		Word start();
		Result start(void(*function)());
		
		template <class T0>
		Result start(void(*function)(T0), T0 param0);

		template <class T0, class T1>
		Result start(void(*function)(T0, T1), T0 param0, T1 param1);
		
		template <class T>
		Result start(T* instance, void (T::*method)());
		void setStackSize(UShortL value);
		

	private:
		void enqueueFunction(UWord function, UWord arg0, UWord arg1);

		Word executeOne();
		void executeAll();
		void suspendSvc();
		void wakeSvc();

		void initializeDefaults();
		void prepareStack(void* function, UWord param0, UWord param1);
		Result startWithParameters(void* function, UWord param0, UWord param1);

		static void suspendSvcImp(Thread* thread);
		static void sleepSvcImp(Private::WaitHandler* waitLink, Word timeout);
		static void enqueueSvcImp(Thread* thread, Task* task);
		static void wakeSvcImp(Thread* thread);
		static void waitOneSvcImp(Thread* thread);

		#ifdef TASKING_DEBUG
		void checkIfActive();
		static void checkActiveThread();
		#else
		void checkIfActive() {}
		static void checkActiveThread() {}
		#endif

	private:
		Thread*				m_next;
		Thread* 			m_previous;
		UWord*				m_sp;
		Private::WaitHandler*	m_waitHandler;
		const Char*			m_name;
		UWord*				m_stackBase;
		ThreadPriority		m_priority;
		ThreadState			m_state;
		BasicQueue<Task>	m_tasks;

		friend class BasicList<Thread>;
		friend class Event;
		friend class Mutex;
		friend class WaitCondition;
		friend class DebugStream;
		friend class BasicExecutor;
		friend class Context;
		friend class Private::WaitHandler;
		friend class Loop;
	};
	
	extern void handleCriticalError();
	extern Thread* currentThread();

	inline void Thread::setName(const Char* value)
	{
		m_name = value;
	}

	inline void Thread::enqueueSvc(Task* task)
	{
		enqueueSvcImp(this, task);
	}

	inline Result Thread::start(void(*function)())
	{
		return startWithParameters((void*)function, 0, 0);
	}

	template <class T0>
	inline Result Thread::start(void(*function)(T0), T0 param0)
	{
		return startWithParameters((void*)function, (UWord)param0, 0);
	}

	template <class T0, class T1>
	inline Result Thread::start(void(*function)(T0, T1), T0 param0, T1 param1)
	{
		return startWithParameters((void*)function, (UWord)param0, (UWord)param1);
	}

	template <class T>
	inline Result Thread::start(T* instance, void (T::*method)())
	{
		return startWithParameters(getMethodAddress(method), (UWord)instance, 0);
	}

	inline void Thread::setStackSize(UShortL value)
	{
		m_sp = (UWord*)value;
	}

	inline void Thread::suspendSvc()
	{
		suspendSvcImp(this);
	}

	inline void Thread::enqueue(void(*function)())
	{
		enqueueFunction((UWord)function, 0, 0);
	}

	template<class A0>
	inline void Art::Thread::enqueue(void (*function)(A0), A0 arg0)
	{
		enqueueFunction((UWord)function, (UWord)arg0, 0);
	}

	inline void Thread::wakeSvc()
	{
		wakeSvcImp(this);
	}

	inline Word sleep(Word timeout)
	{
		return Thread::sleep(timeout);
	}
}


#endif // THREAD_H
