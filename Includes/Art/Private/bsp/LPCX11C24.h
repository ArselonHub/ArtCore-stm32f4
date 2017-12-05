#ifndef _ART_BSP_LPCX1124_H
#define _ART_BSP_LPCX1124_H

#include <Art/Pin.h>

namespace Art
{
	namespace Bsp
	{
		static inline const PinPort& led0() { return port0().pin7(); }
		static inline const PinPort& led1() { return port0().pin8(); }
	}
	
}

#endif
