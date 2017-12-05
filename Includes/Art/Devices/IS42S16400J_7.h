/*
 * IS42S16400J_7.h
 *
 *  Created on: Oct 19, 2016
 *      Author: denizcan
 */

#ifndef ART_DEVICE_IS42S16400J_7_H_
#define ART_DEVICE_IS42S16400J_7_H_

#include <Art/Sdram.h>

namespace Art
{
	class IS42S16400J_7 : public Sdram
	{
	public:
		virtual UInt capacity();
	private:
		virtual void configureController();
	};
} /* namespace Art */

#endif /* SOURCE_ART_DEVICE_IS42S16400J_7_H_ */
