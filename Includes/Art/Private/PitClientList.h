/*
 * PitClientList.h
 *
 *  Created on: May 9, 2017
 *      Author: denizcan
 */

#ifndef SOURCE_ART_PRIVATE_PITCLIENTLIST_H_
#define SOURCE_ART_PRIVATE_PITCLIENTLIST_H_

#include <Art/Private/PitClient.h>

namespace Art
{
	namespace Private
	{

		class PitClientList
		{
		public:
			void configureClients();
		private:
			void addClient(PitClient* client);
			void removeClient(PitClient* client);

			BasicList<PitClient> m_clients;
		};

	} /* namespace Private */
} /* namespace Art */

#endif /* SOURCE_ART_PRIVATE_PITCLIENTLIST_H_ */
