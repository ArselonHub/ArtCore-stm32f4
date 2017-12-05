/****************************************************************************
 *   $Id:: LPC112x.h 9198 2013-07-23 usb00175                     $
 *   Project: NXP LPC112x software example  
 *
 *   Description:
 *     CMSIS Cortex-M0 Core Peripheral Access Layer Header File for 
 *     NXP LPC112x Device Series 
 
 ****************************************************************************
 * Software that is described herein is for illustrative purposes only
* which provides customers with programming information regarding the
* products. This software is supplied "AS IS" without any warranties.
* NXP Semiconductors assumes no responsibility or liability for the
* use of the software, conveys no license or title under any patent,
* copyright, or mask work right to the product. NXP Semiconductors
* reserves the right to make changes in the software without
* notification. NXP Semiconductors also make no representation or
* warranty that such application will be suitable for the specified
* use without further testing or modification.

* Permission to use, copy, modify, and distribute this software and its 
* documentation is hereby granted, under NXP Semiconductors' 
* relevant copyright in the software, without fee, provided that it 
* is used in conjunction with NXP Semiconductors microcontrollers.  This 
* copyright, permission, and disclaimer notice must appear in all copies of 
* this code.

****************************************************************************/
#ifndef __LPC112x_H__
#define __LPC112x_H__

#ifdef __cplusplus
 extern "C" {
#endif 

 /**
  * \internal
  */

/** @addtogroup LPC112x_Definitions LPC112x Definitions
  This file defines all structures and symbols for LPC112x:
    - Registers and bitfields
    - peripheral base address
    - peripheral ID
    - PIO definitions
  @{
*/


/******************************************************************************/
/*                Processor and Core Peripherals                              */
/******************************************************************************/
/** @addtogroup LPC112x_CMSIS LPC112x CMSIS Definitions
  Configuration of the Cortex-M0 Processor and Core Peripherals
  @{
*/

/*
 * ==========================================================================
 * ---------- Interrupt Number Definition -----------------------------------
 * ==========================================================================
 */
typedef enum IRQn
{
/******  Cortex-M0 Processor Exceptions Numbers ***************************************************/
  Reset_IRQn                    = -15,    /*!< 1 Reset Vector                                    */  
  NonMaskableInt_IRQn           = -14,    /*!< 2 Non Maskable Interrupt                           */
  HardFault_IRQn                = -13,    /*!< 3 Cortex-M0 Hard Fault Interrupt                   */
  SVCall_IRQn                   = -5,     /*!< 11 Cortex-M0 SV Call Interrupt                     */
  PendSV_IRQn                   = -2,     /*!< 14 Cortex-M0 Pend SV Interrupt                     */
  SysTick_IRQn                  = -1,     /*!< 15 Cortex-M0 System Tick Interrupt                 */

/******  LPC112x Specific Interrupt Numbers *******************************************************/
  WAKEUP0_IRQn                  = 0,        /*!< All I/O pins can be used as wakeup source.       */
  WAKEUP1_IRQn                  = 1,        /*!< There are 13 pins in total for LPC112x           */
  WAKEUP2_IRQn                  = 2,
  WAKEUP3_IRQn                  = 3,
  WAKEUP4_IRQn                  = 4,   
  WAKEUP5_IRQn                  = 5,        
  WAKEUP6_IRQn                  = 6,        
  WAKEUP7_IRQn                  = 7,        
  WAKEUP8_IRQn                  = 8,        
  WAKEUP9_IRQn                  = 9,        
  WAKEUP10_IRQn                 = 10,       
  WAKEUP11_IRQn                 = 11,       
  WAKEUP12_IRQn                 = 12,         
  ADC_B_IRQn                    = 13,       /*!< ADC_B                                            */
  SSP1_IRQn                     = 14,       /*!< SSP1 Interrupt                                   */
  I2C_IRQn                      = 15,       /*!< I2C Interrupt                                    */
  TIMER_16_0_IRQn               = 16,       /*!< 16-bit Timer0 Interrupt                          */
  TIMER_16_1_IRQn               = 17,       /*!< 16-bit Timer1 Interrupt                          */
  TIMER_32_0_IRQn               = 18,       /*!< 32-bit Timer0 Interrupt                          */
  TIMER_32_1_IRQn               = 19,       /*!< 32-bit Timer1 Interrupt                          */
  SSP0_IRQn                     = 20,       /*!< SSP0 Interrupt                                   */
  UART_IRQn                     = 21,       /*!< UART Interrupt                                   */
  UART1_IRQn                    = 22,       /*!< UART1 Interrupt                                  */
  UART2_IRQn                    = 23,       /*!< UART2 Interrupt                                  */
  ADC_A_IRQn                    = 24,       /*!< ADC_A                                            */
  WDT_IRQn                      = 25,       /*!< Watchdog timer Interrupt                         */  
  BOD_IRQn                      = 26,       /*!< Brown Out Detect(BOD) Interrupt                  */
  FMC_IRQn                      = 27,       /*!< Flash Memory Controller Interrupt                */
  EINT3_IRQn                    = 28,       /*!< External Interrupt 3 Interrupt                   */
  EINT2_IRQn                    = 29,       /*!< External Interrupt 2 Interrupt                   */
  EINT1_IRQn                    = 30,       /*!< External Interrupt 1 Interrupt                   */
  EINT0_IRQn                    = 31,       /*!< External Interrupt 0 Interrupt                   */
} IRQn_Type;

/*
 * ==========================================================================
 * ----------- Processor and Core Peripheral Section ------------------------
 * ==========================================================================
 */

/* Configuration of the Cortex-M0 Processor and Core Peripherals */
#define __MPU_PRESENT             0         /*!< MPU present or not                               */
#define __NVIC_PRIO_BITS          2         /*!< Number of Bits used for Priority Levels          */
#define __Vendor_SysTickConfig    0         /*!< Set to 1 if different SysTick Config is used     */

/*@}*/ /* end of group LPC112x_CMSIS */


#include <Art/Private/cm/cmsis/core_cm0.h>                       /* Cortex-M0 processor and core peripherals           */

/******************************************************************************/
/*                Device Specific Peripheral Registers structures             */
/******************************************************************************/

#if defined ( __CC_ARM   )
#pragma anon_unions
#endif

/*------------- System Control (SYSCON) --------------------------------------*/
/** @addtogroup LPC112x_SYSCON LPC112x System Control Block 
  @{
*/
typedef struct
{
  __IO uint32_t SYSMEMREMAP;            /*!< Offset: 0x000 System memory remap (R/W) */
  __IO uint32_t PRESETCTRL;             /*!< Offset: 0x004 Peripheral reset control (R/W) */
  __IO uint32_t SYSPLLCTRL;             /*!< Offset: 0x008 System PLL control (R/W) */
  __I uint32_t SYSPLLSTAT;             /*!< Offset: 0x00C System PLL status (R/ ) */
       uint32_t RESERVED0[4];

  __IO uint32_t SYSOSCCTRL;             /*!< Offset: 0x020 System oscillator control (R/W) */
  __IO uint32_t WDTOSCCTRL;             /*!< Offset: 0x024 Watchdog oscillator control (R/W) */
  __IO uint32_t IRCCTRL;                /*!< Offset: 0x028 IRC control (R/W) */
       uint32_t RESERVED1[1];
  __IO uint32_t SYSRSTSTAT;             /*!< Offset: 0x030 System reset status Register (R/ ) */
       uint32_t RESERVED2[3];
  __IO uint32_t SYSPLLCLKSEL;           /*!< Offset: 0x040 System PLL clock source select (R/W) */	
  __IO uint32_t SYSPLLCLKUEN;           /*!< Offset: 0x044 System PLL clock source update enable (R/W) */
       uint32_t RESERVED3[10];

  __IO uint32_t MAINCLKSEL;             /*!< Offset: 0x070 Main clock source select (R/W) */
  __IO uint32_t MAINCLKUEN;             /*!< Offset: 0x074 Main clock source update enable (R/W) */
  __IO uint32_t SYSAHBCLKDIV;           /*!< Offset: 0x078 System AHB clock divider (R/W) */
       uint32_t RESERVED4[1];

  __IO uint32_t SYSAHBCLKCTRL;          /*!< Offset: 0x080 System AHB clock control (R/W) */
       uint32_t RESERVED5[4];
  __IO uint32_t SSP0CLKDIV;             /*!< Offset: 0x094 SSP0 clock divider (R/W) */          
  __IO uint32_t UART0CLKDIV;             /*!< Offset: 0x098 UART0 clock divider (R/W) */
  __IO uint32_t SSP1CLKDIV;             /*!< Offset: 0x09C SSP1 clock divider (R/W) */          
       
  __IO uint32_t  UART1CLKDIV;           /*!< UART1 clock divider*/
  __IO uint32_t  UART2CLKDIV;           /*!< UART2 clock divider*/ 

    uint32_t RESERVED6[10];

  __IO uint32_t WDTCLKSEL;              /*!< Offset: 0x0D0 WDT clock source select (R/W) */
  __IO uint32_t WDTCLKUEN;              /*!< Offset: 0x0D4 WDT clock source update enable (R/W) */
  __IO uint32_t WDTCLKDIV;              /*!< Offset: 0x0D8 WDT clock divider (R/W) */
       uint32_t RESERVED8[1];              
  __IO uint32_t CLKOUTCLKSEL;           /*!< Offset: 0x0E0 CLKOUT clock source select (R/W) */
  __IO uint32_t CLKOUTUEN;              /*!< Offset: 0x0E4 CLKOUT clock source update enable (R/W) */
  __IO uint32_t CLKOUTDIV;              /*!< Offset: 0x0E8 CLKOUT clock divider (R/W) */       
       uint32_t RESERVED9[5];
  
  __IO uint32_t PIOPORCAP0;             /*!< Offset: 0x100 POR captured PIO status 0 (R/ ) */           
  __IO uint32_t PIOPORCAP1;             /*!< Offset: 0x104 POR captured PIO status 1 (R/ ) */   
       uint32_t RESERVED10[18];
  __IO uint32_t BODCTRL;                /*!< Offset: 0x150 BOD control (R/W) */
  __IO uint32_t SYSTCKCAL;              /*!< Offset: 0x154 System tick counter calibration (R/W) */
       
       uint32_t RESERVED13[6];

  __IO uint32_t  IRQLATENCY;           /*!< IQR delay. */  

  __IO uint32_t NMISRC;                 /*!< Offset: 0x174 NMI source selection register (R/W) */
       uint32_t RESERVED14[34];
       
  __IO uint32_t STARTAPRP0;             /*!< Offset: 0x200 Start logic edge control Register 0 (R/W) */     
  __IO uint32_t STARTERP0;              /*!< Offset: 0x204 Start logic signal enable Register 0 (R/W) */      
  __O  uint32_t STARTRSRP0CLR;          /*!< Offset: 0x208 Start logic reset Register 0  ( /W) */
  __I uint32_t STARTSRP0;              /*!< Offset: 0x20C Start logic status Register 0 (R/) */

      uint32_t RESERVED17[8];

  __IO uint32_t PDSLEEPCFG;             /*!< Offset: 0x230 Power-down states in Deep-sleep mode (R/W) */
  __IO uint32_t PDAWAKECFG;             /*!< Offset: 0x234 Power-down states after wake-up (R/W) */        
  __IO uint32_t PDRUNCFG;               /*!< Offset: 0x238 Power-down configuration Register (R/W) */
} LPC_SYSCON_TypeDef;
/*@}*/ /* end of group LPC112x_SYSCON */


/*------------- Pin Connect Block (IOCON) --------------------------------*/
/** @addtogroup LPC112x_IOCON LPC112x I/O Configuration Block 
  @{
*/
typedef struct
{
  __IO uint32_t  PIO2_6;                            /*!< I/O configuration for pin PIO2_6/ CT32B0_MAT1                         */
  __I  uint32_t  RESERVED0;
  __IO uint32_t  PIO2_0;                            /*!< I/O configuration for pin PIO2_0/U0_DTR/SSP1_SSEL/ ADC_PIN_TRIG4      */
  __IO uint32_t  RESET_PIO0_0;                      /*!< I/O configuration for pin RESET/PIO0_0                                */
  __IO uint32_t  PIO0_1;                            /*!< I/O configuration for pin PIO0_1/CLKOUT/CT32B0_MAT2                   */
  __I  uint32_t  RESERVED1;
  __IO uint32_t  PIO1_8;                            /*!< I/O configuration for pin PIO1_8/CT16B1_CAP0/R/U2_TXD                 */
  __IO uint32_t  PIO0_2;                            /*!< I/O configuration for pin PIO0_2/SSP0_SSEL/CT16B0_CAP0/ ADC_PIN_TRIG0 */
  __IO uint32_t  PIO2_7;                            /*!< I/O configuration for pin PIO2_7/ CT32B0_MAT2/U0_RXD                  */
  __IO uint32_t  PIO2_8;                            /*!< I/O configuration for pin PIO2_8/ CT32B0_MAT3/U0_TXD                  */
  __IO uint32_t  PIO2_1;                            /*!< I/O configuration for pin PIO2_1/U0_DSR/SSP1_SCK                      */
  __I  uint32_t  RESERVED2;
  __IO uint32_t  PIO0_4;                            /*!< I/O configuration for pin PIO0_4/I2C0_SCL                             */
  __IO uint32_t  PIO0_5;                            /*!< I/O configuration for pin PIO0_5/I2C0_SDA                             */
  __IO uint32_t  PIO1_9;                            /*!< I/O configuration for pin PIO1_9/CT16B1_MAT0/SSP1_ MOSI               */
  __IO uint32_t  PIO3_4;                            /*!< I/O configuration for pin PIO3_4/ CT16B0_CAP1/U0_RXD                  */
  __IO uint32_t  PIO2_4;                            /*!< I/O configuration for pin PIO2_4/ CT16B1_MAT1/ SSP1_SSEL              */
  __IO uint32_t  PIO2_5;                            /*!< I/O configuration for pin PIO2_5/ CT32B0_MAT0                         */
  __IO uint32_t  PIO3_5;                            /*!< I/O configuration for pin PIO3_5/ CT16B1_CAP1/U0_TXD                  */
  __I  uint32_t  RESERVED3[2];
  __IO uint32_t  PIO2_9;                            /*!< I/O configuration for pin PIO2_9/ CT32B0_CAP0                         */
  __IO uint32_t  PIO2_10;                           /*!< I/O configuration for pin PIO2_10                                     */
  __IO uint32_t  PIO2_2;                            /*!< I/O configuration for pin PIO2_2/U0_DCD/SSP1_MISO                     */
  __IO uint32_t  PIO0_8;                            /*!< I/O configuration for pin PIO0_8/SSP0_MISO/CT16B0_MAT0/R/ADC_PIN_TRIG2 */
  __IO uint32_t  PIO0_9;                            /*!< I/O configuration for pin PIO0_9SSP0_MOSI/CT16B0_MAT1/R/ADC_PIN_TRIG3 */
  __IO uint32_t  SWCLK_PIO0_10;                     /*!< I/O configuration for pin SWCLK/PIO0_10/ SSP0_SCK/CT16B0_MAT2         */
  __IO uint32_t  PIO1_10;                           /*!< I/O configuration for pin PIO1_10/ADC_8/CT16B1_MAT1/ SSP1_MISO        */
  __I  uint32_t  RESERVED4;
  __IO uint32_t  R_PIO0_11;                         /*!< I/O configuration for pin R/PIO0_11/ADC_7/CT32B0_MAT3                 */
  __IO uint32_t  R_PIO1_0;                          /*!< I/O configuration for pin R/PIO1_0/ADC_6/CT32B1_CAP0                  */
  __IO uint32_t  R_PIO1_1;                          /*!< I/O configuration for pin R/PIO1_1/ADC_5/CT32B1_MAT0                  */
  __IO uint32_t  R_PIO1_2;                          /*!< I/O configuration for pin R/PIO1_2/ADC_4/CT32B1_MAT1                  */
  __IO uint32_t  PIO3_0;                            /*!< I/O configuration for pin PIO3_0/U0_DTR/CT16B0_MAT0/ U0_TXD           */
  __I  uint32_t  RESERVED5;
  __IO uint32_t  PIO2_3;                            /*!< I/O configuration for pin PIO2_3/U0_RI/SSP1_MOSI                      */
  __IO uint32_t  SWDIO_PIO1_3;                      /*!< I/O configuration for pin SWDIO/PIO1_3/ADC_3/CT32B1_MAT2              */
  __IO uint32_t  PIO1_4;                            /*!< I/O configuration for pin PIO1_4/ADC_2/CT32B1_MAT3                    */
  __IO uint32_t  PIO1_11;                           /*!< I/O configuration for pin PIO1_11/ADC_1/CT32B1_CAP1                   */
  __IO uint32_t  PIO3_2;                            /*!< I/O configuration for pin PIO3_2/U0_DCD/ CT16B0_MAT2/SSP1_SCK         */
  __IO uint32_t  PIO1_5;                            /*!< I/O configuration for pin PIO1_5/U0_RTS/CT32B0_CAP0                   */
  __IO uint32_t  PIO1_6;                            /*!< I/O configuration for pin PIO1_6/U0_RXD/CT32B0_MAT0                   */
  __IO uint32_t  PIO1_7;                            /*!< I/O configuration for pin PIO1_7/U0_TXD/CT32B0_MAT1                   */
  __IO uint32_t  PIO3_3;                            /*!< I/O configuration for pin PIO3_3/U0_RI/ CT16B0_CAP0                   */
  __IO uint32_t  SCK0_LOC;                          /*!< SCK0 pin location select register                                     */
  __IO uint32_t  DSR_LOC;                           /*!< DSR pin location select register                                      */
  __IO uint32_t  DCD_LOC;                           /*!< DCD pin location select register                                      */
  __IO uint32_t  RI_LOC;                            /*!< RI pin location select register                                       */
  __IO uint32_t  PIO0_3;                            /*!< I/O configuration for pin PIO0_3/R/R/U2_RXD                           */
  __IO uint32_t  PIO0_6;                            /*!< I/O configuration for pin PIO0_6/SSP0_SCK/U1_TXD                      */
  __IO uint32_t  PIO0_7;                            /*!< I/O configuration for pin PIO0_7/U0_CTS/ADC_PIN_TRIG1/U1_RXD          */
  __IO uint32_t  SSEL1_LOC;                         /*!< SSEL1 pin location select register                                    */
  __IO uint32_t  CT16B0_CAP0_LOC;                   /*!< CT16B0_CAP0 pin location select register                              */
  __IO uint32_t  SCK1_LOC;                          /*!< SCK1 pin location select register                                     */
  __IO uint32_t  MISO1_LOC;                         /*!< MISO1 pin location select register                                    */
  __IO uint32_t  MOSI1_LOC;                         /*!< MOSI1 pin location select register                                    */
  __IO uint32_t  CT32B0_CAP0_LOC;                   /*!< CT32B0_CAP0 pin location select register                              */
  __IO uint32_t  RXD_LOC;                           /*!< RXD pin location select register                                      */
} LPC_IOCON_TypeDef;
/*@}*/ /* end of group LPC112x_IOCON */


/*------------- Power Management Unit (PMU) --------------------------*/
/** @addtogroup LPC112x_PMU LPC112x Power Management Unit 
  @{
*/
typedef struct
{
  __IO uint32_t PCON;                   /*!< Offset: 0x000 Power control Register (R/W) */
  __IO uint32_t GPREG0;                 /*!< Offset: 0x004 General purpose Register 0 (R/W) */
  __IO uint32_t GPREG1;                 /*!< Offset: 0x008 General purpose Register 1 (R/W) */
  __IO uint32_t GPREG2;                 /*!< Offset: 0x00C General purpose Register 2 (R/W) */
  __IO uint32_t GPREG3;                 /*!< Offset: 0x010 General purpose Register 3 (R/W) */
  __IO uint32_t GPREG4;                 /*!< Offset: 0x014 General purpose Register 4 (R/W) */
} LPC_PMU_TypeDef;
/*@}*/ /* end of group LPC112x_PMU */



// ------------------------------------------------------------------------------------------------
// -----                                       FLASHCTRL                                      -----
// ------------------------------------------------------------------------------------------------

typedef struct {                            /*!< (@ 0x4003C000) FLASHCTRL Structure    */
  __I  uint32_t RESERVED0[4];
  __IO uint32_t FLASHCFG;                   /*!< (@ 0x4003C010) Flash memory access time configuration register */
  __I  uint32_t RESERVED1[3];
  __IO uint32_t FMSSTART;                   /*!< (@ 0x4003C020) Signature start address register */
  __IO uint32_t FMSSTOP;                    /*!< (@ 0x4003C024) Signature stop-address register */
  __I  uint32_t RESERVED2[1];
  __I  uint32_t FMSW0;                      /*!< (@ 0x4003C02C) Word 0 [31:0]          */
  __I  uint32_t FMSW1;                      /*!< (@ 0x4003C030) Word 1 [63:32]         */
  __I  uint32_t FMSW2;                      /*!< (@ 0x4003C034) Word 2 [95:64]         */
  __I  uint32_t FMSW3;                      /*!< (@ 0x4003C038) Word 3 [127:96]        */
  __I  uint32_t RESERVED3[1001];
  __I  uint32_t FMSTAT;                     /*!< (@ 0x4003CFE0) Signature generation status register */
  __I  uint32_t RESERVED4[1];
  __IO uint32_t FMSTATCLR;                  /*!< (@ 0x4003CFE8) Signature generation status clear register */
} LPC_FLASHCTRL_Type;


/*------------- General Purpose Input/Output (GPIO) --------------------------*/
/** @addtogroup LPC112x_GPIO LPC112x General Purpose Input/Output 
  @{
*/
typedef struct
{
  union {
    __IO uint32_t MASKED_ACCESS[4096];  /*!< Offset: 0x0000 to 0x3FFC Port data Register for pins PIOn_0 to PIOn_11 (R/W) */
    struct {
         uint32_t RESERVED0[4095];
    __IO uint32_t DATA;                 /*!< Offset: 0x3FFC Port data Register (R/W) */
    };
  };
       uint32_t RESERVED1[4096];
  __IO uint32_t DIR;                    /*!< Offset: 0x8000 Data direction Register (R/W) */
  __IO uint32_t IS;                     /*!< Offset: 0x8004 Interrupt sense Register (R/W) */
  __IO uint32_t IBE;                    /*!< Offset: 0x8008 Interrupt both edges Register (R/W) */
  __IO uint32_t IEV;                    /*!< Offset: 0x800C Interrupt event Register  (R/W) */
  __IO uint32_t IE;                     /*!< Offset: 0x8010 Interrupt mask Register (R/W) */
  __I uint32_t RIS;                    /*!< Offset: 0x8014 Raw interrupt status Register (R/ ) */
  __I uint32_t MIS;                    /*!< Offset: 0x8018 Masked interrupt status Register (R/ ) */
  __O uint32_t IC;                     /*!< Offset: 0x801C Interrupt clear Register (/W) */
} LPC_GPIO_TypeDef;
/*@}*/ /* end of group LPC112x_GPIO */

/*------------- Timer (TMR) --------------------------------------------------*/
/** @addtogroup LPC112x_TMR LPC112x 16/32-bit Counter/Timer 
  @{
*/
typedef struct
{
  __IO uint32_t IR;                     /*!< Offset: 0x000 Interrupt Register (R/W) */
  __IO uint32_t TCR;                    /*!< Offset: 0x004 Timer Control Register (R/W) */
  __IO uint32_t TC;                     /*!< Offset: 0x008 Timer Counter Register (R/W) */
  __IO uint32_t PR;                     /*!< Offset: 0x00C Prescale Register (R/W) */
  __IO uint32_t PC;                     /*!< Offset: 0x010 Prescale Counter Register (R/W) */
  __IO uint32_t MCR;                    /*!< Offset: 0x014 Match Control Register (R/W) */
  __IO uint32_t MR0;                    /*!< Offset: 0x018 Match Register 0 (R/W) */
  __IO uint32_t MR1;                    /*!< Offset: 0x01C Match Register 1 (R/W) */
  __IO uint32_t MR2;                    /*!< Offset: 0x020 Match Register 2 (R/W) */
  __IO uint32_t MR3;                    /*!< Offset: 0x024 Match Register 3 (R/W) */
  __IO uint32_t CCR;                    /*!< Offset: 0x028 Capture Control Register (R/W) */
  __I  uint32_t CR0;                    /*!< Offset: 0x02C Capture Register 0 (R/ ) */
  __I  uint32_t CR1;                    /*!< Offset: 0x030 Capture Register 1 (R/ ) */
       uint32_t RESERVED1[2];
  __IO uint32_t EMR;                    /*!< Offset: 0x03C External Match Register (R/W) */
       uint32_t RESERVED2[12];
  __IO uint32_t CTCR;                   /*!< Offset: 0x070 Count Control Register (R/W) */
  __IO uint32_t PWMC;                   /*!< Offset: 0x074 PWM Control Register (R/W) */
} LPC_TMR_TypeDef;
/*@}*/ /* end of group LPC112x_TMR */


/*------------- Universal Asynchronous Receiver Transmitter (UART) -----------*/
/** @addtogroup LPC112x_UART LPC112x Universal Asynchronous Receiver/Transmitter 
  @{
*/
typedef struct
{
  union {
  __I  uint32_t  RBR;                   /*!< Offset: 0x000 Receiver Buffer  Register (R/ ) */
  __O  uint32_t  THR;                   /*!< Offset: 0x000 Transmit Holding Register ( /W) */
  __IO uint32_t  DLL;                   /*!< Offset: 0x000 Divisor Latch LSB (R/W) */
  };
  union {
  __IO uint32_t  DLM;                   /*!< Offset: 0x004 Divisor Latch MSB (R/W) */
  __IO uint32_t  IER;                   /*!< Offset: 0x000 Interrupt Enable Register (R/W) */
  };
  union {
  __I  uint32_t  IIR;                   /*!< Offset: 0x008 Interrupt ID Register (R/ ) */
  __O  uint32_t  FCR;                   /*!< Offset: 0x008 FIFO Control Register ( /W) */
  };
  __IO uint32_t  LCR;                   /*!< Offset: 0x00C Line Control Register (R/W) */
  __IO uint32_t  MCR;                   /*!< Offset: 0x010 Modem control Register (R/W) */
  __I  uint32_t  LSR;                   /*!< Offset: 0x014 Line Status Register (R/ ) */
  __I  uint32_t  MSR;                   /*!< Offset: 0x018 Modem status Register (R/ ) */
  __IO uint32_t  SCR;                   /*!< Offset: 0x01C Scratch Pad Register (R/W) */
  __IO uint32_t  ACR;                   /*!< Offset: 0x020 Auto-baud Control Register (R/W) */
       uint32_t  RESERVED0;
  __IO uint32_t  FDR;                   /*!< Offset: 0x028 Fractional Divider Register (R/W) */
       uint32_t  RESERVED1;
  __IO uint32_t  TER;                   /*!< Offset: 0x030 Transmit Enable Register (R/W) */
       uint32_t  RESERVED2[6];
  __IO uint32_t  RS485CTRL;             /*!< Offset: 0x04C RS-485/EIA-485 Control Register (R/W) */
  __IO uint32_t  ADRMATCH;              /*!< Offset: 0x050 RS-485/EIA-485 address match Register (R/W) */
  __IO uint32_t  RS485DLY;              /*!< Offset: 0x054 RS-485/EIA-485 direction control delay Register (R/W) */
  __I  uint32_t  FIFOLVL;               /*!< Offset: 0x058 FIFO Level Register (R) */
} LPC_UART_TypeDef;
/*@}*/ /* end of group LPC112x_UART */


/*------------- Synchronous Serial Communication (SSP) -----------------------*/
/** @addtogroup LPC112x_SSP LPC112x Synchronous Serial Port 
  @{
*/
typedef struct
{
  __IO uint32_t CR0;                    /*!< Offset: 0x000 Control Register 0 (R/W) */
  __IO uint32_t CR1;                    /*!< Offset: 0x004 Control Register 1 (R/W) */
  __IO uint32_t DR;                     /*!< Offset: 0x008 Data Register (R/W) */
  __I  uint32_t SR;                     /*!< Offset: 0x00C Status Registe (R/ ) */
  __IO uint32_t CPSR;                   /*!< Offset: 0x010 Clock Prescale Register (R/W) */
  __IO uint32_t IMSC;                   /*!< Offset: 0x014 Interrupt Mask Set and Clear Register (R/W) */
  __I uint32_t RIS;                    /*!< Offset: 0x018 Raw Interrupt Status Register (R/) */
  __I uint32_t MIS;                    /*!< Offset: 0x01C Masked Interrupt Status Register (R/) */
  __O uint32_t ICR;                    /*!< Offset: 0x020 SSPICR Interrupt Clear Register (/W) */
} LPC_SSP_TypeDef;
/*@}*/ /* end of group LPC112x_SSP */


/*------------- Inter-Integrated Circuit (I2C) -------------------------------*/
/** @addtogroup LPC112x_I2C LPC112x I2C-Bus Interface 
  @{
*/
typedef struct
{
  __IO uint32_t CONSET;                 /*!< Offset: 0x000 I2C Control Set Register (R/W) */
  __I  uint32_t STAT;                   /*!< Offset: 0x004 I2C Status Register (R/ ) */
  __IO uint32_t DAT;                    /*!< Offset: 0x008 I2C Data Register (R/W) */
  __IO uint32_t ADR0;                   /*!< Offset: 0x00C I2C Slave Address Register 0 (R/W) */
  __IO uint32_t SCLH;                   /*!< Offset: 0x010 SCH Duty Cycle Register High Half Word (R/W) */
  __IO uint32_t SCLL;                   /*!< Offset: 0x014 SCL Duty Cycle Register Low Half Word (R/W) */
  __O  uint32_t CONCLR;                 /*!< Offset: 0x018 I2C Control Clear Register ( /W) */
  __IO uint32_t MMCTRL;                 /*!< Offset: 0x01C Monitor mode control register (R/W) */
  __IO uint32_t ADR1;                   /*!< Offset: 0x020 I2C Slave Address Register 1 (R/W) */
  __IO uint32_t ADR2;                   /*!< Offset: 0x024 I2C Slave Address Register 2 (R/W) */
  __IO uint32_t ADR3;                   /*!< Offset: 0x028 I2C Slave Address Register 3 (R/W) */
  __I  uint32_t DATA_BUFFER;            /*!< Offset: 0x02C Data buffer register ( /W) */
  __IO uint32_t MASK0;                  /*!< Offset: 0x030 I2C Slave address mask register 0 (R/W) */
  __IO uint32_t MASK1;                  /*!< Offset: 0x034 I2C Slave address mask register 1 (R/W) */
  __IO uint32_t MASK2;                  /*!< Offset: 0x038 I2C Slave address mask register 2 (R/W) */
  __IO uint32_t MASK3;                  /*!< Offset: 0x03C I2C Slave address mask register 3 (R/W) */
} LPC_I2C_TypeDef;
/*@}*/ /* end of group LPC112x_I2C */


/*------------- Watchdog Timer (WDT) -----------------------------------------*/
/** @addtogroup LPC112x_WDT LPC112x WatchDog Timer 
  @{
*/
typedef struct
{
  __IO uint32_t MOD;                    /*!< Offset: 0x000 Watchdog mode register (R/W) */
  __IO uint32_t TC;                     /*!< Offset: 0x004 Watchdog timer constant register (R/W) */
  __O  uint32_t FEED;                   /*!< Offset: 0x008 Watchdog feed sequence register (W) */
  __I  uint32_t TV;                     /*!< Offset: 0x00C Watchdog timer value register (R) */
       uint32_t RESERVED0;
  __IO uint32_t WARNINT;				/*!< Offset: 0x014 Watchdog timer warning int. register (R/W) */
  __IO uint32_t WINDOW;					/*!< Offset: 0x018 Watchdog timer window value register (R/W) */
} LPC_WDT_TypeDef;
/*@}*/ /* end of group LPC112x_WDT */


/*------------- Analog-to-Digital Converter (ADC) ----------------------------*/
/** @addtogroup LPC112x_ADC LPC112x Analog-to-Digital Converter 
  @{
*/
typedef struct
{
  __IO uint32_t  CTRL;        		/*!< A/D Control Register */
  __I  uint32_t  RESERVED0;
  __IO uint32_t  SEQA_CTRL;   		/*!< A/D Conversion Sequence-A control Register*/
  __IO uint32_t  SEQB_CTRL;   		/*!< A/D Conversion Sequence-B Control Register*/
  __IO uint32_t  SEQA_GDAT;   		/*!< A/D Sequence-A Global Data Register. */
  __IO uint32_t  SEQB_GDAT;  		/*!< A/D Sequence-B Global Data Register */
  __I  uint32_t  RESERVED1[3];
  __I  uint32_t  DAT1;           	/*!< A/D Channel 1 Data Register*/
  __I  uint32_t  DAT2;                  /*!< A/D Channel 1 Data Register*/
  __I  uint32_t  DAT3;                  /*!< A/D Channel 1 Data Register*/
  __I  uint32_t  DAT4;                  /*!< A/D Channel 1 Data Register*/
  __I  uint32_t  DAT5;                 /*!< A/D Channel 1 Data Register */
  __I  uint32_t  DAT6;                 /*!< A/D Channel 1 Data Register.*/
  __I  uint32_t  DAT7;                 /*!< A/D Channel 1 Data Register.*/
  __I  uint32_t  DAT8;                 /*!< A/D Channel 1 Data Register*/
  __I  uint32_t  RESERVED2[3];
  __IO uint32_t  THR0_LOW;             /*!< A/D Low Compare Threshold Register 0 */
  __IO uint32_t  THR1_LOW;             /*!< A/D Low Compare Threshold Register 1 */
  __IO uint32_t  THR0_HIGH;            /*!< A/D High Compare Threshold Register 0:*/
  __IO uint32_t  THR1_HIGH;            /*!< A/D High Compare Threshold Register 1*/
  __IO uint32_t  CHAN_THRSEL;          /*!< A/D Channel-Threshold Select Register*/
  __IO uint32_t  INTEN;                /*!< A/D Interrupt Enable Register.*/
  __IO uint32_t  FLAGS;                /*!< A/D Flags Register*/
  __IO uint32_t  TRM;                  /*!< ADC trim register*/
} LPC_ADC_TypeDef;
/*@}*/ /* end of group LPC112x_ADC */



#if defined ( __CC_ARM   )
#pragma no_anon_unions
#endif

/******************************************************************************/
/*                         Peripheral memory map                              */
/******************************************************************************/
/* Base addresses                                                             */
#define LPC_FLASH_BASE        (0x00000000UL)
#define LPC_RAM_BASE          (0x10000000UL)
#define LPC_APB0_BASE         (0x40000000UL)
#define LPC_AHB_BASE          (0x50000000UL)

/* APB0 peripherals                                                           */
#define LPC_I2C_BASE          (LPC_APB0_BASE + 0x00000)
#define LPC_WDT_BASE          (LPC_APB0_BASE + 0x04000)
#define LPC_UART0_BASE        (LPC_APB0_BASE + 0x08000)
#define LPC_UART1_BASE        (LPC_APB0_BASE + 0x20000)
#define LPC_UART2_BASE        (LPC_APB0_BASE + 0x24000)
#define LPC_CT16B0_BASE       (LPC_APB0_BASE + 0x0C000)
#define LPC_CT16B1_BASE       (LPC_APB0_BASE + 0x10000)
#define LPC_CT32B0_BASE       (LPC_APB0_BASE + 0x14000)
#define LPC_CT32B1_BASE       (LPC_APB0_BASE + 0x18000)
#define LPC_ADC_BASE          (LPC_APB0_BASE + 0x1C000)
#define LPC_PMU_BASE          (LPC_APB0_BASE + 0x38000)
#define LPC_FLASHCTRL_BASE    (LPC_APB0_BASE + 0x3C000)
#define LPC_SSP0_BASE         (LPC_APB0_BASE + 0x40000)
#define LPC_IOCON_BASE        (LPC_APB0_BASE + 0x44000)
#define LPC_SYSCON_BASE       (LPC_APB0_BASE + 0x48000)
#define LPC_SSP1_BASE         (LPC_APB0_BASE + 0x58000)

/* AHB peripherals                                                            */
#define LPC_GPIO_BASE         (LPC_AHB_BASE  + 0x00000)
#define LPC_GPIO0_BASE        (LPC_AHB_BASE  + 0x00000)
#define LPC_GPIO1_BASE        (LPC_AHB_BASE  + 0x10000)
#define LPC_GPIO2_BASE        (LPC_AHB_BASE  + 0x20000)
#define LPC_GPIO3_BASE        (LPC_AHB_BASE  + 0x30000)

/******************************************************************************/
/*                         Peripheral declaration                             */
/******************************************************************************/
#define LPC_I2C               ((LPC_I2C_TypeDef    *) LPC_I2C_BASE   )
#define LPC_WDT               ((LPC_WDT_TypeDef    *) LPC_WDT_BASE   )

#define LPC_UART0             ((LPC_UART_TypeDef   *) LPC_UART0_BASE  )

#define LPC_TMR16B0           ((LPC_TMR_TypeDef    *) LPC_CT16B0_BASE)
#define LPC_TMR16B1           ((LPC_TMR_TypeDef    *) LPC_CT16B1_BASE)
#define LPC_TMR32B0           ((LPC_TMR_TypeDef    *) LPC_CT32B0_BASE)
#define LPC_TMR32B1           ((LPC_TMR_TypeDef    *) LPC_CT32B1_BASE)
#define LPC_ADC               ((LPC_ADC_TypeDef    *) LPC_ADC_BASE   )

#define LPC_UART1             ((LPC_UART_TypeDef   *) LPC_UART1_BASE  )
#define LPC_UART2             ((LPC_UART_TypeDef   *) LPC_UART2_BASE  )

#define LPC_PMU               ((LPC_PMU_TypeDef    *) LPC_PMU_BASE   )
#define LPC_FLASHCTRL         ((LPC_FLASHCTRL_Type *) LPC_FLASHCTRL_BASE)
#define LPC_SSP0              ((LPC_SSP_TypeDef    *) LPC_SSP0_BASE  )
#define LPC_SSP1              ((LPC_SSP_TypeDef    *) LPC_SSP1_BASE  )
#define LPC_IOCON             ((LPC_IOCON_TypeDef  *) LPC_IOCON_BASE )
#define LPC_SYSCON            ((LPC_SYSCON_TypeDef *) LPC_SYSCON_BASE)
#define LPC_GPIO0             ((LPC_GPIO_TypeDef   *) LPC_GPIO0_BASE )
#define LPC_GPIO1             ((LPC_GPIO_TypeDef   *) LPC_GPIO1_BASE )
#define LPC_GPIO2             ((LPC_GPIO_TypeDef   *) LPC_GPIO2_BASE )
#define LPC_GPIO3             ((LPC_GPIO_TypeDef   *) LPC_GPIO3_BASE )

#ifdef __cplusplus
}
#endif

#endif  /* __LPC112x_H__ */
