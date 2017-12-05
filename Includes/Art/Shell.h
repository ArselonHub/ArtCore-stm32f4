#ifndef ART_SHELL_H
#define ART_SHELL_H

#include <Art/Stream.h>
#include <Art/String.h>
#include <Art/Signal.h>

namespace Art
{
	class Shell : public Object
	{
	public:
		Signal<void*> onCommand() SIGNAL;

		Shell();
		virtual ~Shell();
		Word setStream(Stream* value);
		Stream* stream();
		Word writeString(const Char* s);
		Word writeString(const StringRef& s);
		Word writeString(const Expression& e);
		Word writeLine(const Char* s);
		Word writeLine(const StringRef& s);
		Word writeLine(const Expression& e);
		Word open();
		StringRef line();

	private:
		void doDataReady(void* sender);

		Stream*			m_stream;
		Char*			m_lineBuffer;
		Short			m_index;
		Short			m_length;
		Short			m_capacity;
		Bool			m_echo;
	};

	inline Stream* Shell::stream()
	{
		return m_stream;
	}
}

#endif
