/*
 * GpioPort.h
 *
 *  Created on: 26 �ub 2015
 *      Author: denizcan
 */

#ifndef ART_PRIVATE_PORT_H_
#define ART_PRIVATE_PORT_H_

namespace Art
{
	class Port
	{
	public:
		UWord direction() const;
		UWord value() const;
		void setDirection(UWord value) const;
		void setValue(UWord value) const;
	};
}

#endif /* GPIOPORT_H_ */
