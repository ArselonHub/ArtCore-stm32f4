/*
 * I2C3.h
 *
 *  Created on: Dec 3, 2016
 *      Author: denizcan
 */

#ifndef ART_PRIVATE_STM32_STM32F4_STMI2CPORT2_H_
#define ART_PRIVATE_STM32_STM32F4_STMI2CPORT2_H_

#include <Art/Private/stm32/stm32f4/StmI2CPort.h>

namespace Art
{
	namespace Private
	{

		extern "C" void I2C2_EV_IRQHandler();
		extern "C" void I2C2_ER_IRQHandler();

		class StmI2CPort2 : public StmI2CPort
		{
		public:
			StmI2CPort2();
		private:
			virtual void powerUp();
			virtual void powerDown();

			friend void I2C2_EV_IRQHandler();
			friend void I2C2_ER_IRQHandler();
		};

	}

	extern Private::StmI2CPort2* i2c2();
}

#endif
