#ifndef ART_BASIS_QUEUE_H
#define ART_BASIS_QUEUE_H

#include <Art/Types.h>

namespace Art
{
	template <class T>
	class BasicQueue
	{
	public:
		BasicQueue();
		void pushFront(T* item);
		void pushFront(BasicQueue<T>& queue);
		void pushBack(T* item);
		T* popFront();
		Bool hasItems();
		Bool isEmpty();
		void clear();
		T* head();
		T* front();
		T* back();
		static T* tail();
		T* nextOf(T* item);
		void remove(T* item);
		void removeNextOf(T* index);
	private:
		T* m_front;
		T* m_back;
	};

	template<class T>
	inline BasicQueue<T>::BasicQueue()
	{
		m_front = 0;
		m_back = 0;
	}

	template <class T>
	inline T* BasicQueue<T>::popFront()
	{
		T* result = m_front;
		if (result)
			m_front = result->m_next;
		return result;
	}

	template <class T>
	inline Bool BasicQueue<T>::hasItems()
	{
		return m_front != 0;
	}

	template <class T>
	inline Bool BasicQueue<T>::isEmpty()
	{
		return m_front == 0;
	}

	template <class T>
	inline void BasicQueue<T>::clear()
	{
		m_front = 0;
	}

	template<class T>
	void BasicQueue<T>::pushFront(T* item)
	{
		T* f = m_front;
		item->m_next = f;
		if (f == 0)
			m_back = item;
		m_front = item;
	}

	template<class T>
	inline void BasicQueue<T>::pushFront(BasicQueue<T>& queue)
	{
		if (queue.isEmpty())
			return;
		T* b = queue.m_back;
		b->m_next = m_front;
		m_back = b;
		m_front = queue.m_front;
		queue.clear();
	}

	template <class T>
	void BasicQueue<T>::pushBack(T* item)
	{
		item->m_next = 0;
		if (m_front == 0)
			m_front = item;
		else
			m_back->m_next = item;
		m_back = item;
	}


	template<class T>
	inline T* BasicQueue<T>::head()
	{
		return (T*)((UByte*)this - offsetOf(T, m_next));
	}

	template <class T>
	inline T* BasicQueue<T>::front()
	{
		return m_front;
	}

	template<class T>
	inline T* BasicQueue<T>::back()
	{
		return m_front ? m_back : 0;
	}

	template<class T>
	inline T* BasicQueue<T>::tail()
	{
		return 0;
	}

	template<class T>
	inline T* BasicQueue<T>::nextOf(T* item)
	{
		return item->m_next;
	}

	template<class T>
	void BasicQueue<T>::remove(T* item)
	{
		T* p = head();
		for (T* i = p->m_next; i; i = i->m_next)
		{
			if (i == item)
			{
				T* nn = i->m_next;
				p->m_next = nn;
				if (nn == 0)
					m_back = p;
				return;
			}
			p = i;
		}
	}

	template<class T>
	void BasicQueue<T>::removeNextOf(T* index)
	{
		T* n = index->m_next;
		T* nn = n->m_next;
		index->m_next = nn;
		if (nn == 0)
			m_back = index;
	}
}

#endif
