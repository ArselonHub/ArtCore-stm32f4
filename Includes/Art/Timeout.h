#ifndef ART_TIMEOUT_H
#define ART_TIMEOUT_H

#include <Art/Types.h>

namespace Art
{
	class Timeout
	{
	public:
		Timeout();
		Timeout(ShortL period);
		void start();
		void start(ShortL timeout);
		ShortL remaining();
		void wait();
	
	private:
		UInt _targetTicks;
		ShortL _period;
	
	};
}


#endif
