#ifndef ART_BSP
#define ART_BSP

#if defined(STM32F0DISCO)
#	include <Art/bsp/STM32F0Discovery.h>
#elif defined(LANDTIGER)
#	include <Art/Bsp/Landtiger.h>
#elif defined(__MSP430CCRF__)
#	include <Art/Private/bsp/MSP430CCRF.h>
#elif defined(LPCX11C24)
#	include <Art/Private/bsp/LPCX11C24.h>
#elif defined(STM32F429I_DISCO) || defined(STM32F429I_DISC1)
#	include <Art/Private/bsp/STM32F429I-DISCO.h>
#endif

#endif
