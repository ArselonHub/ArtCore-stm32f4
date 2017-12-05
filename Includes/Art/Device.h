/*
 * Device.h
 *
 *  Created on: Dec 17, 2016
 *      Author: denizcan
 */

#ifndef SOURCE_ART_DEVICE_H_
#define SOURCE_ART_DEVICE_H_

#include <Art/Object.h>

namespace Art
{
	class Device : public Object
	{
	public:
		Device();
		virtual ~Device();

		Bool isOpen() const;
		Bool isEnabled() const;
		Bool isActive() const;

		Word open();
		Word close();
		Word enable();
		Word disable();
		Word setEnabled(Bool value);
	protected:
		void becomeDisabled();
		void becomeClosed();

		virtual Word openDevice();
		virtual Word closeDevice();
		virtual Word enableDevice();
		virtual Word disableDevice();
		virtual void doAfterOpen();
		virtual void doBeforeClose();

	private:
		Bool 	m_open;
		Bool 	m_enabled;
	};

	inline Bool Device::isEnabled() const
	{
		return m_enabled;
	}

	inline Bool Device::isOpen() const
	{
		return m_open;
	}

	inline Word Device::setEnabled(Bool value)
	{
		if (value)
			return enable();
		else
			return disable();
	}

	inline void Device::becomeDisabled()
	{
		m_enabled = 0;
	}

	inline Bool Device::isActive() const
	{
		return m_open && m_enabled;
	}

	inline void Device::becomeClosed()
	{
		m_open = 0;
	}

} /* namespace Art */

#endif /* SOURCE_ART_DEVICE_H_ */
