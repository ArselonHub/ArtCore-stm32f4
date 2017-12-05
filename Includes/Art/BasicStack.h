#ifndef ART_BASIS_STACK_H
#define ART_BASIS_STACK_H

#include <Art/Types.h>

namespace Art
{
	template <class T>
	class BasicStack
	{
	public:
		BasicStack();
		BasicStack(T* items);
		void pushFront(T* item);
		void pushFront(BasicStack<T>& stack);
		T* popFront();
		void insertAfter(T* index, T* item);
		void clear();
		bool hasItems();
		bool isEmpty();
		T* head();
		T* front();
		T* back();
		T* tail();
		T* nextOf(T* item);
		void remove(T* index);
		static void removeNextOf(T* index);
	private:
		T* m_front;
	};

	template <class T>
	BasicStack<T>::BasicStack()
	{
		m_front = 0;
	}

	template <class T>
	BasicStack<T>::BasicStack(T* items)
	{
		this->m_front = items;
	}

	template <class T>
	inline void BasicStack<T>::pushFront(T* item)
	{
		item->m_next = m_front;
		m_front = item;
	}

	template<class T>
	void BasicStack<T>::pushFront(BasicStack<T>& stack)
	{
		T* l = stack.back();
		if (l == 0)
			return;
		l->m_next = m_front;
		m_front = stack.m_front;
		stack.clear();
	}

	template <class T>
	inline T* BasicStack<T>::popFront()
	{
		T* result = m_front;
		if (result)
			m_front = result->m_next;
		return result;
	}

	template <class T>
	void BasicStack<T>::insertAfter(T* index, T* item)
	{
		item->m_next = index->m_next;
		index->m_next = item;
	}

	template <class T>
	inline void BasicStack<T>::clear()
	{
		m_front = 0;
	}

	template <class T>
	inline bool BasicStack<T>::hasItems()
	{
		return m_front != 0;
	}

	template <class T>
	inline bool BasicStack<T>::isEmpty()
	{
		return m_front == 0;
	}

	template <class T>
	inline T* BasicStack<T>::head()
	{
		Word o = offsetOf(T, m_next);
		return (T*)((UByte*)this - o);
	}

	template <class T>
	inline T* BasicStack<T>::front()
	{
		return m_front;
	}

	template<class T>
	T* BasicStack<T>::back()
	{
		T* i = m_front;
		if (i == 0)
			return 0;
		while (true)
		{
			T* n = i->m_next;
			if (n == 0)
				return i;
			i = n;
		}
	}

	template<class T>
	inline T* BasicStack<T>::tail()
	{
		return 0;
	}

	template<class T>
	inline T* BasicStack<T>::nextOf(T* item)
	{
		return item->m_next;
	}

	template<class T>
	void BasicStack<T>::remove(T* item)
	{
		T* p = head();
		for (T* i = p->m_next; i; i = i->m_next)
		{
			if (i == item)
			{
				p->m_next = i->m_next;
				return;
			}
			p = i;
		}
	}

	template<class T>
	inline void BasicStack<T>::removeNextOf(T* index)
	{
		index->m_next = index->m_next->m_next;
	}
}

#endif
