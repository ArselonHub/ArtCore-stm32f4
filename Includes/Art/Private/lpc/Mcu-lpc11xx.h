/*
 * Mcu-lpc11xx.h
 *
 *  Created on: 4 Şub 2015
 *      Author: denizcan
 */

#ifndef ART_LPC_MCU_LPC11XX_H_
#define ART_LPC_MCU_LPC11XX_H_

/*****************************************************************************
  SYSAHBCLKCTRL
 *****************************************************************************/

#define SYSAHBCLKCTRL_ROM			(1 << 1)
#define SYSAHBCLKCTRL_RAM			(1 << 2)
#define SYSAHBCLKCTRL_FLASHREG		(1 << 3)
#define SYSAHBCLKCTRL_FLASHARRAY	(1 << 4)
#define SYSAHBCLKCTRL_I2C			(1 << 5)
#define SYSAHBCLKCTRL_GPIO			(1 << 6)
#define SYSAHBCLKCTRL_CT16B0		(1 << 7)
#define SYSAHBCLKCTRL_CT16B1		(1 << 8)
#define SYSAHBCLKCTRL_CT32B0		(1 << 9)
#define SYSAHBCLKCTRL_CT32B1		(1 << 10)
#define SYSAHBCLKCTRL_SSP0			(1 << 11)
#define SYSAHBCLKCTRL_UART			(1 << 12)
#define SYSAHBCLKCTRL_ADC			(1 << 13)
#define SYSAHBCLKCTRL_WDT			(1 << 15)
#define SYSAHBCLKCTRL_IOCON			(1 << 16)

#define MAINCLKSEL_IRC		(0 << 0)
#define MAINCLKSEL_PLL_IN	(1 << 0)
#define MAINLCKSEL_WDT		(2 << 0)
#define MAINCLKSEL_PLL_OUT	(3 << 0)

#define SYSPLLCLKSEL_IRC	(0 << 0)
#define SYSPLLCLKSEL_SYSOSC	(1 << 0)

#endif /* ART_LPC_MCU_LPC11XX_H_ */
