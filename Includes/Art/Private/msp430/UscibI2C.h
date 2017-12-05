/*
 * I2C.h
 *
 *  Created on: Apr 27, 2013
 *      Author: denizcan
 */

#ifndef ART_MSP430_USCIBI2C_H_
#define ART_MSP430_USCIBI2C_H_

#include <Art/I2C.h>

namespace Art
{
	class UscibI2C : public I2C
	{
	public:
		UscibI2C();
		void setSdaPin(PinId value) { sdaPin = value; }
		void setSclPin(PinId value) { sclPin = value; }

		virtual void resetBus();
	protected:
		virtual void startWritingPort(Word address);
		virtual void writePort();
		virtual void stopWritingPort();
		virtual void openPort();
		virtual void closePort();

		friend void USCI_B0_ISR(void);
	private:
		PinId sdaPin;
		PinId sclPin;
	};

	extern UscibI2C uscibI2C;
}

#endif /* I2C_MSP_430_H_ */
