#ifndef ART_LIST_H
#define ART_LIST_H

#include <Art/Types.h>

namespace Art
{
	template <class T>
	class BasicList
	{
	public:
		BasicList();
		BasicList(T* first);
		void append(BasicList<T>& list);
		void append(T* item);
		static void insertBefore(T* target, T* item);
		static void insertAfter(T* target, T* item);
		void prepend(T* item);
		void prepend(BasicList<T>& source);
		void clear();
		bool hasItems();
		bool isEmpty();
		T* sentinel();
		T* tail();
		T* first();
		T* last();
		static T* previousOf(T* item);
		static void remove(T* item);
		T* removeFirst();
		static void removeNext(T* item);
	private:
		T* m_next;
		T* m_previous;
	};

	template <class T>
	BasicList<T>::BasicList()
	{
		clear();
	}

	template <class T>
	inline T* BasicList<T>::sentinel()
	{
		Word o = offsetOf(T, m_next);
		return (T*)((UByte*)this - o);
	}

	template <class T>
	inline void BasicList<T>::clear()
	{
		T* t = sentinel();
		m_next = t;
		m_previous = t;
	}

	template <class T>
	inline bool BasicList<T>::hasItems()
	{
		return m_next != m_previous;
	}

	template <class T>
	inline bool BasicList<T>::isEmpty()
	{
		return m_next == sentinel();
	}

	template <class T>
	inline T* BasicList<T>::first()
	{
		return ((volatile BasicList<T>*)this)->m_next;
	}

	template <class T>
	inline void BasicList<T>::insertBefore(T* target, T* item)
	{
		item->m_next = target;
		item->m_previous = target->m_previous;
		target->m_previous->m_next = item;
		target->m_previous = item;
	}

	template <class T>
	inline void BasicList<T>::insertAfter(T* target, T* item)
	{
		item->m_previous = target;
		item->m_next = target->m_next;
		target->m_next->m_previous = item;
		target->m_next = item;
	}

	template<class T>
	void BasicList<T>::append(BasicList<T>& list)
	{
		if (list.hasItems())
		{
			list.m_next->m_previous = m_previous;
			list.m_previous->m_next = sentinel();
			m_previous->next = list.m_next;
			m_previous = list.m_previous;
			list.clear();
		}
	}

	template <class T>
	inline void BasicList<T>::prepend(T* item)
	{
		insertBefore(m_next, item);
	}

	template <class T>
	inline void BasicList<T>::prepend(BasicList<T>& source)
	{
		if (source.hasItems())
		{
			source.m_previous->next = m_next;
			m_next->m_previous = source.m_previous;
			source.m_next->previous = sentinel();
			m_next = source.m_next;
			source.clear();
		}
	}

	template <class T>
	inline T* BasicList<T>::last()
	{
		return m_previous;
	}

	template <class T>
	inline T* BasicList<T>::previousOf(T* item)
	{
		return item->m_previous;
	}

	template <class T>
	inline void BasicList<T>::append(T* item)
	{
		insertAfter(m_previous, item);
	}

	template <class T>
	inline void BasicList<T>::remove(T* item)
	{
		item->m_previous->m_next = ((volatile T*)item)->m_next;
		item->m_next->m_previous = ((volatile T*)item)->m_previous;
	}

	template <class T>
	inline T* BasicList<T>::removeFirst()
	{
		T* item = m_next;
		if (item == sentinel())
			return 0;
		remove(item);
		return item;
	}
}

#endif
