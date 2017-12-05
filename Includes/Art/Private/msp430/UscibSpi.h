/*
 * UscibSpi.h
 *
 *  Created on: May 13, 2013
 *      Author: denizcan
 */

#ifndef USCIBSPI_H_
#define USCIBSPI_H_

#include <Art/Spi.h>

namespace Art
{
	class UscibSpi : public Spi
	{
	public:
		void setSckPin(const PinPort& value);
		void setMosiPin(const PinPort& value);
		void setMisoPin(const PinPort& value);

		virtual UWord shift(UWord value);
		virtual void shift(void* txBuffer, void* rxBuffer, UShort length);

	protected:
		virtual void openPort();
		virtual void closePort();
		virtual void configurePort();

		friend void USCI_B0_ISR(void);
	};

	extern UscibSpi uscibSpi;
}

#endif /* USCIBSPI_H_ */
