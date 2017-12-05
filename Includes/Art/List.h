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
	class List
	{
	private:
		class Record
		{
		public:
			Record(const T& item);
			Record*	next_;
			Record* previous_;
			T		item_;
		};

	public:
		class Iterator
		{
		public:
			Iterator next();
			Iterator previous();
			T& operator*();
			T& operator->();
			Iterator& operator--();
			Iterator& operator++(Word);
			Bool operator!=(const Iterator& right) const;
			Bool operator==(const Iterator& right) const;
		private:
			Iterator(Record* cursor);
			Record*	cursor_;
		
			friend class List<T>;
		};

		List();
		~List();
		Iterator begin();
		Iterator end();
		T& front();
		T& back();
		void pushFront(const T& item);
		void pushBack(const T& item);
		void popFront();
		void popBack();
		Bool hasItem();
		Bool isEmpty();
		void clear();
	private:
		static void insert(const T& item, Record* cursor);
		static void remove(Record* record);
		Record*	next_;
		Record*	previous_;
	};

	template<class T>
	inline List<T>::Record::Record(const T& item)
	{
		item_ = item;
	}

	template<class T>
	inline List<T>::Iterator::Iterator(Record* cursor)
	{
		cursor_ =  cursor;
	}

	template<class T>
	inline class List<T>::Iterator& List<T>::Iterator::operator --()
	{
		cursor_ = cursor_->previous_;
		return *this;
	}

	template<class T>
	inline class List<T>::Iterator& List<T>::Iterator::operator ++(Word)
	{
		cursor_ = cursor_->next_;
		return *this;
	}

	template<class T>
	inline Bool List<T>::Iterator::operator !=(const Iterator& right) const
	{
		return cursor_ != right.cursor_;
	}
	
	template<class T>
	inline Bool List<T>::Iterator::operator ==(const Iterator& right) const
	{
		return cursor_ == right.cursor_;
	}

	template<class T>
	inline class List<T>::Iterator List<T>::Iterator::next()
	{
		return Iterator(cursor_->next_);
	}

	template<class T>
	inline class List<T>::Iterator List<T>::Iterator::previous()
	{
		return Iterator(cursor_->previous_);
	}


	template<class T>
	inline T& List<T>::Iterator::operator *()
	{
		return cursor_->item_;
	}

	template<class T>
	inline T& List<T>::Iterator::operator ->()
	{
		return cursor_->item_;
	}

	template<class T>
	inline List<T>::List()
	{
		next_ = (Record*)this;
		previous_ = (Record*)this;
	}

	template<class T>
	inline List<T>::~List()
	{
		clear();
	}

	template<class T>
	inline class List<T>::Iterator List<T>::begin()
	{
		return Iterator(next_);
	}

	template<class T>
	inline class List<T>::Iterator List<T>::end()
	{
		return Iterator((Record*)this);
	}

	template<class T>
	inline T& List<T>::front()
	{
		return next_->item_;
	}

	template<class T>
	inline T& List<T>::back()
	{
		return previous_->item_;
	}

	template<class T>
	void List<T>::insert(const T& item, Record* cursor)
	{
		Record* record = new Record(item);
		Record* p = cursor->previous_;
		record->next_ = cursor;
		record->previous_ = p;		
		p->next_ = record;
		cursor->previous_ = record;
	}

	template<class T>
	inline void List<T>::remove(Record* record)
	{
		Record* p = record->previous_;
		Record* n = record->next_;
		p->next_ = n;
		n->previous_ = p;
	}

	template<class T>
	inline void List<T>::pushFront(const T& item)
	{
		insert(item, next_);
	}

	template<class T>
	inline void List<T>::pushBack(const T& item)
	{
		insert(item, (Record*)this);
	}

	template<class T>
	void List<T>::popFront()
	{
		Record* record = next_;
		remove(record);
		delete record;
	}

	template<class T>
	void List<T>::popBack()
	{
		Record* record = previous_;
		remove(record);
		delete record;
	}


	template<class T>
	inline Bool List<T>::hasItem()
	{
		return next_ != (Record*)this;
	}

	template<class T>
	inline Bool List<T>::isEmpty()
	{
		return next_ == (Record*)this;
	}


	template<class T>
	void List<T>::clear()
	{
		for (Record* r = next_; r != (Record*)this;)
		{
			Record* n = r->next_;
			delete r;
			r = n;
		}
		next_ = (Record*)this;
		previous_ = (Record*)this;
	}

} /* namespace Art */


#endif /* SOURCE_ART_QUEUE_H_ */
