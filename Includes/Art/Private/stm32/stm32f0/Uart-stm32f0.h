#ifndef ART_STM32F0_UART_H
#define ART_STM32F0_UART_H

namespace Art
{
	namespace Private
	{
		class StmUart : public SerialPort
		{
		// Uart Interface
		public:
			virtual void flushRxFifo();
			virtual void flushTxFifo();
		protected:
			virtual Result openPort();
			virtual void startTransmitting();
			//virtual void disableRxInterrupt();
			//virtual void enableRxInterrupt();
			//virtual void disableTxInterrupt();
			//virtual void enableTxInterrupt();

		// StmUart
		protected:
			virtual USART_TypeDef* getPort() = 0;
			void processIrq();
		};
		
		extern "C" void USART1_IRQHandler(void);
		class StmUsart1 : public Private::StmUart
		{
		protected:
			virtual USART_TypeDef* getPort();		
			friend void USART1_IRQHandler();
		};
	}
	
	extern Private::StmUsart1 usart1;
	
};

#endif

