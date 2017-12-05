/*
 * Queue.h
 *
 *  Created on: Mar 24, 2016
 *      Author: denizcan
 */

#ifndef ART_QUEUE_H_
#define ART_QUEUE_H_

#include <Art/Types.h>

namespace Art
{
	template <class T>
	class Stack
	{
	private:
		class Record
		{
		public:
			Record(const T& item);
			Record*	next_;
			T		item_;
		};

	public:
		class Iterator
		{
		public:
			Iterator next();
			T& operator*();
			T& operator->();
			Iterator& operator++(Word);
			Bool operator!=(const Iterator& right) const;
			Bool operator==(const Iterator& right) const;
		private:
			Iterator(Record* cursor);
			Record*	cursor_;
		
			friend class Stack<T>;
		};

		Stack();
		~Stack();
		Iterator begin();
		Iterator end();
		T& front();
		void insertAfter(const Iterator& iterator, const T& item);
		void pushFront(const T& item);
		void popFront();
		Bool hasItem();
		Bool isEmpty();
		void clear();
	private:
		Record*	next_;
	};

	template<class T>
	inline Stack<T>::Record::Record(const T& item)
	{
		item_ = item;
	}

	template<class T>
	inline Stack<T>::Iterator::Iterator(Record* cursor)
	{
		cursor_ =  cursor;
	}

	template<class T>
	inline class Stack<T>::Iterator& Stack<T>::Iterator::operator ++(Word)
	{
		cursor_ = cursor_->next_;
		return *this;
	}

	template<class T>
	inline Bool Stack<T>::Iterator::operator !=(const Iterator& right) const
	{
		return cursor_ != right.cursor_;
	}
	
	template<class T>
	inline Bool Stack<T>::Iterator::operator ==(const Iterator& right) const
	{
		return cursor_ == right.cursor_;
	}

	template<class T>
	inline class Stack<T>::Iterator Stack<T>::Iterator::next()
	{
		return Iterator(cursor_->next_);
	}


	template<class T>
	inline T& Stack<T>::Iterator::operator *()
	{
		return cursor_->item_;
	}

	template<class T>
	inline T& Stack<T>::Iterator::operator ->()
	{
		return cursor_->item_;
	}

	template<class T>
	inline Stack<T>::Stack()
	{
		next_ = 0;
	}

	template<class T>
	inline Stack<T>::~Stack()
	{
		clear();
	}

	template<class T>
	inline class Stack<T>::Iterator Stack<T>::begin()
	{
		return Iterator(next_);
	}

	template<class T>
	inline class Stack<T>::Iterator Stack<T>::end()
	{
		return Iterator(0);
	}

	template<class T>
	inline T& Stack<T>::front()
	{
		return next_->item_;
	}

	template<class T>
	inline void Stack<T>::insertAfter(const Iterator& iterator, const T& item)
	{

		Record* record = new Record(item);
		Record* c = iterator->cursor_;
		record->next_ = c->next_;
		c->next = record;
	}

	template<class T>
	inline void Stack<T>::pushFront(const T& item)
	{
		Record* record = new Record(item);
		record->next_ = next_;
		next_ = record;
	}

	template<class T>
	void Stack<T>::popFront()
	{
		Record* record = next_;
		next_ = record->next_;
		delete record;
	}

	template<class T>
	inline Bool Stack<T>::hasItem()
	{
		return next_ != 0;
	}

	template<class T>
	inline Bool Stack<T>::isEmpty()
	{
		return next_ == 0;
	}

	template<class T>
	void Stack<T>::clear()
	{
		for (Record* r = next_; r;)
		{
			Record* n = r->next_;
			delete r;
			r = n;
		}
		next_ = 0;
	}

} /* namespace Art */


#endif /* SOURCE_ART_QUEUE_H_ */
