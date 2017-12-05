/*****************************************************************************
	Arselon Electronic (c) 2012

	Uart HAL for LPC devices 
 *****************************************************************************/
#ifndef ART_PRIVATE_LPC_LPCUARTPORT_H
#define ART_PRIVATE_LPC_LPCUARTPORT_H

#include <Art/Mcu.h>

namespace Art
{	
	class LpcUartPort : public UartPort
	{		
	protected:
        LpcUartPort(LPC_UART_TypeDef* port);
		void processIrq();
		virtual void setClockDivider(UWord value) = 0;
	
		// Uart			
		virtual void configurePort();
		virtual void transmit();
		virtual void flushRxFifo();
		virtual void flushTxFifo();
	
	private:
		LPC_UART_TypeDef* 	m_port;	
	};	
}

#endif
