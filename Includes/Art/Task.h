#ifndef ART_PRIVATE_TASK_H
#define ART_PRIVATE_TASK_H

#include <Art/BasicQueue.h>

namespace Art
{
	class Task
	{
	public:
		Task();
		virtual void execute() = 0;
		Bool isIdle();
	private:
		Task* m_next;

		friend class Svc;
		friend class Thread;
		friend class BasicQueue<Task>;
	};

	inline Task::Task()
	{
		m_next = (Task*)1;
	}

	inline Bool Task::isIdle()
	{
		return m_next == (Task*)1;
	}
}

#endif
