#ifndef MCU_LPC_H
#define MCU_LPC_H

/*****************************************************************************
  I2C
 *****************************************************************************/
#define UART_RXEVENT	0x0100
#define UART_TXEVENT	0x0200

/*****************************************************************************
  I2C
 *****************************************************************************/
#define I2C_WRITE	0
#define I2C_READ	1

#define I2C_CONSET_I2EN				(1 << 6)
#define I2C_CONSET_STA				(1 << 5)
#define I2C_CONSET_STO				(1 << 4)
#define I2C_CONSET_SI				(1 << 3)
#define I2C_CONSET_AA				(1 << 2)

#define I2C_CONCLR_I2ENC			(1 << 6)
#define I2C_CONCLR_STAC				(1 << 5)
#define I2C_CONCLR_STOC				(1 << 4)
#define I2C_CONCLR_SIC				(1 << 3)
#define I2C_CONCLR_AAC				(1 << 2)

#define I2C_STAT_STATE_START		(0x08)
#define I2C_STAT_STATE_START_REP	(0x10)


#define I2C_STAT_BUSERROR			0x00
#define I2C_STAT_IDLE				0xF8
#define I2C_STAT_START				0x08
#define I2C_STAT_REPEATED_START		0x10
#define I2C_STAT_SLAW_ACK			0x18
#define I2C_STAT_SLAW_NACK			0x20
#define I2C_STAT_DATAW_ACK			0x28
#define I2C_STAT_DATAW_NACK			0x30
#define I2C_STAT_ARBITRATION_LOST	0x38 
#define I2C_STAT_SLAR_ACK			0x40
#define I2C_STAT_SLAR_NACK			0x48
#define I2C_STAT_DATAR_ACK			0x50
#define I2C_STAT_DATAR_NACK			0x58


/*****************************************************************************
  SSP
 *****************************************************************************/
#define SSP_CR0_DSS_8BIT	(0x07 << 0)
#define SSP_CR0_FRF_SPI		(0x00 << 4)
#define SSP_CR0_FRF_TI		(0x01 << 4)
#define SSP_CR0_CPOL		(1 << 6)
#define SSP_CR0_CPHA		(1 << 7)

#define SSP_CR1_SSE			(1 << 1)
#define SSP_CR1_SLAVE		(1 << 2)

#define SSP_SR_TFE			(1 << 0)
#define SSP_SR_TNF			(1 << 1)
#define SSP_SR_RNE			(1 << 2)
#define SSP_SR_RFF			(1 << 3)
#define SSP_SR_BSY			(1 << 4)

#define SSP_IM_ROR			(1 << 0)
#define SSP_IM_RT			(1 << 1)
#define SSP_IM_RX			(1 << 2)
#define SSP_IM_TX			(1 << 3)

#define SSP_RIS_ROR			(1 << 0)
#define SSP_RIS_RT			(1 << 1)
#define SSP_RIS_RX			(1 << 2)
#define SSP_RIS_TX			(1 << 3)

#define SSP_MIS_ROR			(1 << 0)
#define SSP_MIS_RT			(1 << 1)
#define SSP_MIS_RX			(1 << 2)
#define SSP_MIS_TX			(1 << 3)


/*****************************************************************************
  UART
 *****************************************************************************/
#define UART_LCR_WORD_5BITS		(0 << 0)
#define UART_LCR_WORD_6BITS		(1 << 0)
#define UART_LCR_WORD_7BITS		(2 << 0)
#define UART_LCR_WORD_8BITS		(3 << 0)
#define UART_LCR_STOP_1BIT		(0 << 2)
#define UART_LCR_STOP_2BITS		(1 << 2)
#define UART_LCR_PARITY_OFF		(0 << 3)
#define UART_LCR_PARITY_ON		(1 << 3)
#define UART_LCR_PARITY_ODD		(0 << 4)
#define UART_LCR_PARITY_EVEN	(1 << 4)
#define UART_LCR_PARITY_MARK	(2 << 4)
#define UART_LCR_PARITY_SPACE	(3 << 4)
#define UART_LCR_BREAK			(1 << 6)
#define UART_LCR_DLAB_ACCESS	(1 << 7)

#define UART_FCR_FIFO_ENABLE	(1 << 0)
#define UART_FCR_RXFIFO_RESET	(1 << 1)
#define UART_FCR_TXFIFO_RESET	(1 << 2)
#define UART_FCR_RX_TRIGGER1	(0 << 6)
#define UART_FCR_RX_TRIGGER4	(1 << 6)
#define UART_FCR_RX_TRIGGER8	(2 << 6)
#define UART_FCR_RX_TRIGGER14	(3 << 6)

#define UART_LSR_RDR			(1 << 0)
#define UART_LSR_OE				(1 << 1)
#define UART_LSR_PE				(1 << 2)
#define UART_LSR_FE				(1 << 3)
#define UART_LSR_BI				(1 << 4)
#define UART_LSR_THRE			(1 << 5)
#define UART_LSR_TEMT			(1 << 6)
#define UART_LSR_RXFE			(1 << 7)

#define UART_IIR_MASK			(0x0E)
#define UART_IIR_PENDING		(0x01)

#define UART_IIR_RLS			(3 << 1)
#define UART_IIR_RDA			(2 << 1)
#define UART_IIR_CTI			(6 << 1)
#define UART_IIR_THRE			(1 << 1)

#define UART_IER_RBR			(1 << 0)
#define UART_IER_THRE			(1 << 1)
#define UART_IER_RXLS			(1 << 2)


#define UART_RS485CTRL_SEL		(1 << 3)
#define UART_RS485CTRL_DCTRL	(1 << 4)
#define UART_RS485CTRL_OINV		(1 << 5)

/******************************************************************************
  TIMER/COUNTER
 ******************************************************************************/
#define TMR_IR_MR0			(1 << 0)
#define TMR_IR_MR1			(1 << 1)
#define TMR_IR_MR2			(1 << 2)
#define TMR_IR_MR3			(1 << 3)
#define TMR_IR_CR0			(1 << 4)
#define TMR_IR_CR1			(1 << 5)
#define TMR_IR_CR2			(1 << 6)
#define TMR_IR_CR3			(1 << 7)

#define TMR_TCR_ENABLE		(1 << 0)
#define TMR_TCR_RESET		(1 << 1)
#define TMR_TCR_PWM			(1 << 3)

#define TMR_MCR_MR0I		(1 << 0)
#define TMR_MCR_MR0R		(1 << 1)
#define TMR_MCR_MR0S		(1 << 2)
#define TMR_MCR_MR1I		(1 << 3)
#define TMR_MCR_MR1R		(1 << 4)
#define TMR_MCR_MR1S		(1 << 5)
#define TMR_MCR_MR2I		(1 << 6)
#define TMR_MCR_MR2R		(1 << 7)
#define TMR_MCR_MR2S		(1 << 8)
#define TMR_MCR_MR3I		(1 << 9)
#define TMR_MCR_MR3R		(1 << 10)
#define TMR_MCR_MR3S		(1 << 11)

#define TMR_CCR_CAP0RE		(1 << 0)
#define TMR_CCR_CAP0FE		(1 << 1)
#define TMR_CCR_CAP0I		(1 << 2)
#define TMR_CCR_CAP1RE		(1 << 3)
#define TMR_CCR_CAP1FE		(1 << 4)
#define TMR_CCR_CAP1I		(1 << 5)
#define TMR_CCR_CAP2RE		(1 << 6)
#define TMR_CCR_CAP2FE		(1 << 7)
#define TMR_CCR_CAP2I		(1 << 8)
#define TMR_CCR_CAP3RE		(1 << 9)
#define TMR_CCR_CAP3FE		(1 << 10)
#define TMR_CCR_CAP3I		(1 << 11)

#define TMR_EMR_EM0			(1 << 0)
#define TMR_EMR_EM1			(1 << 1)
#define TMR_EMR_EM2			(1 << 2)
#define TMR_EMR_EM3			(1 << 3)
#define TMR_EMR_EMC0		(1 << 4)
#define TMR_EMR_EMC1		(1 << 6)
#define TMR_EMR_EMC2		(1 << 8)
#define TMR_EMR_EMC3		(1 << 10)

#define TMR_EMR_EMC_NOM		(0)
#define TMR_EMR_EMC_COM		(1)
#define TMR_EMR_EMC_SOM		(2)
#define TMR_EMR_EMC_TOM		(3)

#endif
