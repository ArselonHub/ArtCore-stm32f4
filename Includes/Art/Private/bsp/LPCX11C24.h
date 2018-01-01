#ifndef _ART_BSP_LPCX1124_H
#define _ART_BSP_LPCX1124_H

#include <Art/Pin.h>

namespace Art
{
	namespace Bsp
	{
		static inline const Pin& led0() { return port0().pin7(); }
		static inline const Pin& led1() { return port0().pin8(); }
	}
	
}

#endif
