#ifndef ART_SDRAM_H
#define ART_SDRAM_H

#include <Art/Types.h>

#if defined(__STM32F429__)
#include <Art/Private/stm32/stm32f4/Fmc-stm32f4.h>
#endif

namespace Art
{

	class Sdram
	{
	public:
		Sdram();
		virtual ~Sdram();
		SdramController* controller() const;
		void setController(SdramController* controller);
		Word open();
		void* pointer();
		Word test();
		virtual UInt capacity() = 0;
	private:
		virtual void configureController() = 0;

		SdramController*	m_controller;
		UWord				m_active;
	};

	inline Art::SdramController* Sdram::controller() const
	{
		return m_controller;
	}

	inline void Sdram::setController(SdramController* controller)
	{
		m_controller = controller;
	}

	inline void* Sdram::pointer()
	{
		return m_controller->pointer();
	}


} /* namespace Art */
#endif

