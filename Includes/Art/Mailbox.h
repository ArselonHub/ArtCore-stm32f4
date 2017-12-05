#ifndef MAILBOX_H
#define MAILBOX_H

#include <Art/Event.h>
#include <Art/GlobalSection.h>

namespace Art
{
	template <class T>
	class Mailbox
	{
	public:
		Mailbox(void* buffer, ShortL size);
		void open();
		bool hasItem() { return head != tail; }
		bool hasRoom() { return (head - tail) < size; }
		void pop(T& item);
		void push(const T item);
		bool tryPop(T& item);
		bool tryPush(const T item);
		UWord getCount() { return head - tail; }
	private:
		Event	inEvent;
		Event	outEvent;
		T* 		items;
		volatile Short	head;
		volatile Short	tail;
		Short	size;
	};

	template <class T>
	Mailbox<T>::Mailbox(void* buffer, ShortL size)
	{
		this->items = (T*)buffer;
		this->size = size / sizeof(T);
		this->head = 0;
		this->tail = 0;
	}

	template <class T>
	void Mailbox<T>::pop(T& item)
	{
		//QUESTION Why sometimes event returns even while count remains 0
		while (head == tail)
			inEvent.wait();
		
		ShortL i = tail;
		item = items[i];
		i++;
		if (i == size)
		{
			GlobalSection section;
			section.enter();
			tail = 0;
			head -= size;
			section.exit();
		}
		else
			tail = i;
		outEvent.set();
	}

	template <class T>
	void Mailbox<T>::push(const T item)
	{
		while ((head - tail) == size)
			outEvent.wait();

		GlobalSection section;
		section.enter();
		ShortL i = head;
		if (i >= size)
			i -= size;
		items[i] = item;
		head++;
		section.exit();

		inEvent.set();
	}

	template <class T>
	bool Mailbox<T>::tryPop(T& item)
	{
		if (tail == head)
			return false;

		ShortL i = tail;
		item = items[i];
		i++;
		if (i == size)
		{
			GlobalSection section;
			section.enter();
			tail = 0;
			head -= size;
			section.exit();
		}
		else
			tail = i;
		outEvent.set();
		return true;
	}

	template <class T>
	bool Mailbox<T>::tryPush(const T item)
	{
		if ((head - tail) == size)
			return false;

		GlobalSection section;
		section.enter();
		ShortL i = head;
		if (i >= size)
			i -= size;
		items[i] = item;
		head++;
		section.exit();

		inEvent.set();
		return true;
	}
}

#endif
