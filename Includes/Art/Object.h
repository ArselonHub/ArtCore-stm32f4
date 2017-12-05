
#ifndef ART_OBJECT_H
#define ART_OBJECT_H

#include <Art/Signal.h>

namespace Art
{
	class Object
	{
	public:
		virtual ~Object();
	protected:
		Dispatcher* dispatcher();

	private:
		Dispatcher m_dispatcher;
	};

	inline Object::~Object()
	{
	}

	inline Dispatcher* Object::dispatcher()
	{
		return &m_dispatcher;
	}
}

#endif
