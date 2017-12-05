/*
 * UartDefines.h
 *
 *  Created on: Aug 12, 2015
 *      Author: denizcan
 */

#ifndef ART_PRIVATE_UARTDEFINES_H_
#define ART_PRIVATE_UARTDEFINES_H_

#include <Art/Types.h>

namespace Art
{
	enum Baud
	{
		Baud1200,
		Baud2400,
		Baud4800,
		Baud9600 = 9600,
		Baud19200 = 19200,
		Baud38400 = 38400,
		Baud57600 = 57600,
		Baud115200 = 115200,
		BaudUser0,
		BaudUser1,
		BaudUser2,
		BaudUser3,
		BaudUser4,
		BaudUser5,
		BaudUser6,
		BausUser7
	};

	enum DataBits
	{
		DataBits7,
		DataBits8,
		DataBits9
	};

	enum StopBits
	{
		StopBits1,
		StopBits2
	};

	enum Parity
	{
		ParityNone,
		ParityOdd,
		ParityEven
	};
}

#endif /* SOURCE_ART_PRIVATE_UARTDEFINES_H_ */
