/*
 * SpiNodeBase.h
 *
 *  Created on: Oct 20, 2015
 *      Author: denizcan
 */

#ifndef ART_SPINODEBASE_H_
#define ART_SPINODEBASE_H_

#include <Art/Pin.h>
#include <Art/SpiPort.h>

namespace Art
{
	class SpiMaster
	{
	public:
		void setPort(SpiPort* value);
		Pin* selectPin() const;
		void setSelectPin(Pin* pin);
		Word start();
		Word stop();
		Word open();
		Word writeByte(Word value);	
		Word write(const void* buffer, Word length);
		Word read(void* buffer, Word length);
		Word writeRead(const void* writeBuffer, void* readBuffer, Word length);
		void setSpeed(SpiSpeed value);
		void setPolarity(SpiPolarity value);
		void setPhase(SpiPhase value);
	private:
		SpiPort*			port_;
		Pin*			selectPin_;
		SpiPort::Settings	settings_;

		friend class SpiPort;
	};

	inline void SpiMaster::setPort(SpiPort* value)
	{
		port_ = value;
	}

	inline Word SpiMaster::open()
	{
		return port_->open();
	}

	inline void SpiMaster::setSpeed(SpiSpeed value)
	{
		settings_.speed = value;
	}

	inline void SpiMaster::setPolarity(SpiPolarity value)
	{
		settings_.polarity = value;
	}

	inline Pin* SpiMaster::selectPin() const
	{
		return selectPin_;
	}

	inline void SpiMaster::setPhase(SpiPhase value)
	{
		settings_.phase = value;
	}

} /* namespace Art */

#endif /* SOURCE_ART_SPINODEBAS_H_ */
