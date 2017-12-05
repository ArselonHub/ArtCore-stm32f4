#ifndef ART_WAITOBJECT_H
#define ART_WAITOBJECT_H

#include <Art/Private/WaitLink.h>

namespace Art
{
	namespace Private
	{
		class WaitObject
		{
		protected:
			WaitLink* removeOneLink();
			void addLink(WaitLink* link);
		private:
			BasicList<WaitLink> m_links;

			friend class WaitLink;
		};

		inline WaitLink* WaitObject::removeOneLink()
		{
			return m_links.removeFirst();
		}

		inline void WaitObject::addLink(WaitLink* link)
		{
			m_links.append(link);
		}

	}
}

#endif
