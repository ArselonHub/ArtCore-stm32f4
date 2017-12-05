#ifndef MCU_LPC17_H
#define MCU_LPC17_H

#include <Art/Private/cm/cmsis/lpc17xx.h>
#include <Art/Private/lpc/Mcu-lpc.h>

/******************************************************************************
  GPIO INT
 ******************************************************************************/

#define GPIOINT_IS_P0INT	(1 << 0)
#define GPIOINT_IS_P2INT	(1 << 2)

/******************************************************************************
  DAC
 ******************************************************************************/

#define DAC_CONTROL_DMA_REQ			(1 << 0)
#define DAC_CONTROL_DOUBLE_BUFFER	(1 << 1)
#define DAC_CONTROL_COUNTER_ENABLE	(1 << 2)
#define DAC_CONTROL_DMA_ENABLE		(1 << 3)

/******************************************************************************
  ADC
 ******************************************************************************/
#define ADC_CR_SEL0		(1 << 0)
#define ADC_CR_SEL1		(1 << 1)
#define ADC_CR_SEL2		(1 << 2)
#define ADC_CR_SEL3		(1 << 3)
#define ADC_CR_SEL4		(1 << 4)
#define ADC_CR_SEL5		(1 << 5)
#define ADC_CR_SEL6		(1 << 6)
#define ADC_CR_SEL7		(1 << 7)

#define ADC_CR_DIV2		(2 << 8)
#define ADC_CR_DIV3		(3 << 8)
#define ADC_CR_DIV4		(4 << 8)
#define ADC_CR_DIV5		(5 << 8)
#define ADC_CR_DIV6		(6 << 8)
#define ADC_CR_DIV7		(7 << 8)
#define ADC_CR_DIV(v)	(v << 8)

#define ADC_CR_SINGLE	(0 << 16)
#define ADC_CR_BURST	(1 << 16)
#define ADC_CR_PDN		(1 << 21)
#define ADC_CR_IDLE		(0 << 24)
#define ADC_CR_START	(1 << 24)
#define ADC_CR_EDGE		(1 << 27)

#define ADC_CR_DEFAULT			(ADC_CR_DIV4 | ADC_CR_PDN)
#define ADC_CR_DEFAULT_START	(ADC_CR_DIV4 | ADC_CR_PDN | ADC_CR_START)

/******************************************************************************
  RIT
 ******************************************************************************/
#define RIT_CTRL_ENABLE		(1 << 0)
#define RIT_CTRL_TICKINT	(1 << 1)
#define RIT_CTRL_CLKSRC		(1 << 2)

/******************************************************************************
  SYSTEM
 ******************************************************************************/

#define PCONP_TIMER0	(1U << 1)
#define PCONP_TIMER1	(1U << 2)
#define PCONP_UART0		(1U << 3)
#define PCONP_UART1		(1U << 4)
#define PCONP_RES1		(1U << 5)
#define PCONP_PWM1		(1U << 6)
#define PCONP_SSP1		(1U << 10)
#define PCONP_ADC		(1U << 12)
#define PCONP_I2C1		(1U << 19)
#define PCONP_SSP0		(1U << 21)
#define PCONP_TIMER2	(1U << 22)
#define PCONP_TIMER3	(1U << 23)
#define PCONP_UART2		(1U << 24)
#define PCONP_UART3		(1U << 25)
#define PCONP_PCGPDMA	(1U << 29)
#define PCONP_USB		(1U << 31)

#define CLKSRCSEL_IRC	(0 << 0)
#define CLKSRCSEL_OSC	(1 << 0)
#define CLKSRCSEL_RTC	(2 << 0)
#define CCLKSEL(v)		(v - 1)

#define SCS_OSCRANGE	(1 << 4)
#define SCS_OSCRANGE_20MHZ (0 << 4)
#define SCS_OSCRANGE_25MHZ (1 << 4)
#define SCS_OSCEN		(1 << 5)
#define SCS_OSCSTAT		(1 << 6)

// PLL0
#define PLL0CON_PLLE	(1 << 0)
#define PLL0CON_PLLC	(1 << 1)

#define PLL0STAT_PLOCK (1 << 26)
#define PLL0STAT_PLLC	(1 << 25)
#define PLL0STAT_PLLE	(1 << 24)

#define PLL0CFG_M(m) ((m - 1) << 0)
#define PLL0CFG_N(n) ((n - 1) << 16)

// PLL1
#define PLL1CON_PLLE	(1 << 0)
#define PLL1CON_PLLC	(1 << 1)
#define PLL1STAT_PLOCK	(1 << 10)
#define PLL1CFG_M(m)	((m - 1) << 0)
#define PLL1CFG_P1		(0 << 5)
#define PLL1CFG_P2		(1 << 5)
#define PLL1CFG_P4		(2 << 5)
#define PLL1CFG_P8		(3 << 5)

// FLASH
#define FLASHCFG_FETCH_ONE			(1 << 0)
#define FLASHCFG_FETCH_ALL			(2 << 0)
#define FLASHCFG_DATA_ONE			(1 << 2)
#define FLASHCFG_DATA_ALL			(2 << 2)
#define FLASHCFG_ACCELERATE			(1 << 4)
#define FLASHCFG_PREFETCH			(1 << 5)
#define FLASHCFG_PREFETCH_OVERFLOW	(1 << 6)

#define FLASHCFG_MAX20MHZ	(0 << 12)
#define FLASHCFG_MAX40MHZ	(1 << 12)
#define FLASHCFG_MAX60MHZ	(2 << 12)
#define FLASHCFG_MAX80MHZ	(3 << 12)
#define FLASHCFG_MAX100MHZ	(4 << 12)
#define FLASHCFG_SAFE		(5 << 12)

#define PCLKSEL_DIV4	0
#define PCLKSEL_DIV1	1
#define PCLKSEL_DIV2	2
#define PCLKSEL_DIV8	3

/******************************************************************************
  PWM
 ******************************************************************************/

#define PWM_TCR_ENABLE		(1 << 0)
#define PWM_TCR_RESET		(1 << 1)
#define PWM_TCR_PWM_ENABLE	(1 << 3)

#define PWM_MCR_MR0I		(1 << 0)
#define PWM_MCR_MR0R		(1 << 1)
#define PWM_MCR_MR0S		(1 << 2)
#define PWM_MCR_MR1I		(1 << 3)
#define PWM_MCR_MR1R		(1 << 4)
#define PWM_MCR_MR1S		(1 << 5)
#define PWM_MCR_MR2I		(1 << 6)
#define PWM_MCR_MR2R		(1 << 7)
#define PWM_MCR_MR2S		(1 << 8)
#define PWM_MCR_MR3I		(1 << 9)
#define PWM_MCR_MR3R		(1 << 10)
#define PWM_MCR_MR3S		(1 << 11)
#define PWM_MCR_MR4I		(1 << 12)
#define PWM_MCR_MR4R		(1 << 13)
#define PWM_MCR_MR4S		(1 << 14)
#define PWM_MCR_MR5I		(1 << 15)
#define PWM_MCR_MR5R		(1 << 16)
#define PWM_MCR_MR5S		(1 << 17)
#define PWM_MCR_MR6I		(1 << 18)
#define PWM_MCR_MR6R		(1 << 19)
#define PWM_MCR_MR6S		(1 << 20)

#define PWM_PCR_SEL2	(1 << 2)
#define PWM_PCR_SEL3	(1 << 3)
#define PWM_PCR_SEL4	(1 << 4)
#define PWM_PCR_SEL5	(1 << 5)
#define PWM_PCR_SEL6	(1 << 6)
#define PWM_PCR_ENA1	(1 << 9)
#define PWM_PCR_ENA2	(1 << 10)
#define PWM_PCR_ENA3	(1 << 11)
#define PWM_PCR_ENA4	(1 << 12)
#define PWM_PCR_ENA5	(1 << 13)
#define PWM_PCR_ENA6	(1 << 14)

#define PWM_LER_L0		(1 << 0)
#define PWM_LER_L1		(1 << 1)
#define PWM_LER_L2		(1 << 2)
#define PWM_LER_L3		(1 << 3)
#define PWM_LER_L4		(1 << 4)
#define PWM_LER_L5		(1 << 5)
#define PWM_LER_L6		(1 << 6)

/******************************************************************************
  DMA
 ******************************************************************************/

typedef struct 
{
  UInt 	source;		// start of source area
  UInt	destination;	// start of destination area
  UInt	next;		// address of next strLLI in chain
  UInt	control;		// DMACCxControl register
} DMALLI;


// DMA CONFIG
#define DMA_CONFIG_ENABLE		(1 << 0)
#define DMA_CONFIG_BIGENDIAN	(1 << 1)

// DMA CONNECTION
#define DMA_CONNECTION_SSP0TX	(0)
#define DMA_CONNECTION_SSP0RX	(1)
#define DMA_CONNECTION_DAC		(7)


// DMA CHANNEL CONFIG
#define DMA_CCONFIG_ENABLE			(1 << 0)

#define DMA_CCONFIG_SRC_NONE		(0 << 1)

#define DMA_CCONFIG_DST_NONE		(0 << 6)
#define DMA_CCONFIG_DST_DAC			(DMA_CONNECTION_DAC << 6)

#define DMA_CCONFIG_TYPE_MEMTOMEM	(0 << 11)
#define DMA_CCONFIG_TYPE_MEMTOPER	(1 << 11)
#define DMA_CCONFIG_TYPE_PERTOMEM	(2 << 11)
#define DMA_CCONFIG_TYPE_PERTOPER	(3 << 11)

#define DMA_CCONFIG_IE				(1 << 14)
#define DMA_CCONFIG_ITC				(1 << 15)
#define DMA_CCONFIG_LOCK			(1 << 16)
#define DMA_CCONFIG_ACTIVE			(1 << 17)
#define DMA_CCONFIG_HALT			(1 << 18)

// DMA CHANNEL CONTROL
#define DMA_CCONTROL_SBS1		(0 << 12)
#define DMA_CCONTROL_SBS4		(1 << 12)
#define DMA_CCONTROL_SBS8		(2 << 12)
#define DMA_CCONTROL_SBS16		(3 << 12)

#define DMA_CCONTROL_DBS1		(0 << 15)
#define DMA_CCONTROL_DBS4		(1 << 15)
#define DMA_CCONTROL_DBS8		(2 << 15)
#define DMA_CCONTROL_DBS16		(3 << 15)

#define DMA_CCONTROL_S8BIT		(0 << 18)
#define DMA_CCONTROL_S16BIT		(1 << 18)
#define DMA_CCONTROL_S32BIT		(2 << 18)

#define DMA_CCONTROL_D8BIT		(0 << 21)
#define DMA_CCONTROL_D16BIT		(1 << 21)
#define DMA_CCONTROL_D32BIT		(2 << 21)

#define DMA_CCONTROL_SI			(1 << 26)
#define DMA_CCONTROL_DI			(1 << 27)
#define DMA_CCONTROL_IE			(1 << 31)

/******************************************************************************
  RTC
 ******************************************************************************/

#define RTC_CCR_CLKEN	(1 << 0)
#define RTC_CCR_CTCRST	(1 << 1)
#define RTC_CCR_CCALEN	(1 << 4)

/******************************************************************************
  USB
 ******************************************************************************/

#define USB_CLKCTRL_DEV_CLK_EN		(1 << 1)
#define USB_CLKCTRL_PORTSEL_CLK_EN	(1 << 3)
#define USB_CLKCTRL_AHB_CLK_EN		(1 << 4)

#define USB_INTREQ_LP			(1U << 0)
#define USB_INTREQ_HP			(1U << 1)
#define USB_INTREQ_DMA			(1U << 2)
#define USB_INTREQ_NEED_CLK		(1U << 8)
#define USB_INTREQ_EN_USB_INTS	(1U << 31)

#define USB_DEVINT_FRAME	(1U << 0)
#define USB_DEVINT_EP_FAST	(1U << 1)
#define USB_DEVINT_EP_SLOW	(1U << 2)
#define USB_DEVINT_DEV_STAT	(1U << 3)
#define USB_DEVINT_CCEMPTY	(1U << 4)
#define USB_DEVINT_CDFULL	(1U << 5)
#define USB_DEVINT_RxENDPKT	(1U << 6)
#define USB_DEVINT_TxENDPKT	(1U << 7)
#define USB_DEVINT_EP_RLZED	(1U << 8)
#define USB_DEVINT_ERR		(1U << 9)

#define USB_CMDCODE_WRITE	(1U << 8)
#define USB_CMDCODE_READ	(2U << 8)
#define USB_CMDCODE_COMMAND	(5U << 8)

#define USB_CMDCODE_SET_ADDRESS			(0xD0 << 16)
#define USB_CMDCODE_CONFIGURE_DEVICE	(0xD8 << 16)
#define USB_CMDCODE_SET_MODE			(0xF3 << 16)
#define USB_CMDCODE_SET_DEVICE_STATUS	(0xFE << 16)
#define USB_CMDCODE_GET_DEVICE_STATUS	(0xFE << 16)

#define USB_CMDCODE_GET_FRAME_NUMBER	(0xF5 << 16)
#define USB_CMDCODE_GET_TEST_REGISTER	(0xFD << 16)

#define USB_DEVICE_STATUS_CONNECT			(1 << 0)
#define USB_DEVICE_STATUS_CONNECT_CHANGED	(1 << 1)
#define USB_DEVICE_STATUS_SUSPEND			(1 << 2)
#define USB_DEVICE_STATUS_SUSPEND_CHANGED	(1 << 3)
#define USB_DEVICE_STATUS_RESET				(1 << 4)





#endif
