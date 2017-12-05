/*
 * StmUartPort1.h
 *
 *  Created on: Dec 23, 2016
 *      Author: denizcan
 */

#ifndef SOURCE_ART_PRIVATE_STM32_STM32F4_STMUART1_H_
#define SOURCE_ART_PRIVATE_STM32_STM32F4_STMUART1_H_

#include <Art/Uart.h>

namespace Art
{
	namespace Private
	{
		extern "C" void USART1_IRQHandler();

		class StmUart1 : public StmUart
		{
		public:
			StmUart1();
			virtual ~StmUart1();
		private:
			virtual void powerUp();
			virtual void powerDown();

			friend void USART1_IRQHandler();
		};
	}

	Private::StmUart* usart1();

} /* namespace Art */

#endif /* SOURCE_ART_PRIVATE_STM32_STM32F4_STMUART1_H_ */
