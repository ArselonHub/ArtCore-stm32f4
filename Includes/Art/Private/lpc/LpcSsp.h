#ifndef ART_SSP_LPC_H
#define ART_SSP_LPC_H

#include <Art/PinPort.h>
#include <Art/SpiPort.h>

namespace Art
{
	/******************************************************************************
	 LpcSsp
	 ******************************************************************************/
	namespace Private
	{
		class LpcSsp : public SpiPort
		{
		public:
			LpcSsp(LPC_SSP_TypeDef* port);
			PinPort* misoPin() const;
			PinPort* mosiPin() const;
			PinPort* sckPin() const;
			void setMisoPin(PinPort* value);
			void setMosiPin(PinPort* value);
			void setSckPin(PinPort* value);
		protected:
			LPC_SSP_TypeDef* port();

		private:
			Word configurePort(const Settings& settings);
			virtual Word startMasterPort(const Settings& settings);
			virtual Word startSlavePort(const Settings& settings);
			virtual Word stopPort();
			virtual Word readPort(void* readData, Word length);
			virtual Word writePort(const void* writeData, Word length);
			virtual Word writeReadPort(const void* writeData, void* readData,
					Word length);

			LPC_SSP_TypeDef* port_;
			PinPort* misoPin_;
			PinPort* mosiPin_;
			PinPort* sckPin_;
		};

		inline LpcSsp::LpcSsp(LPC_SSP_TypeDef* port)
		{
			port_ = port;
		}

		inline PinPort* LpcSsp::misoPin() const
		{
			return misoPin_;
		}

		inline PinPort* LpcSsp::mosiPin() const
		{
			return mosiPin_;
		}

		inline PinPort* LpcSsp::sckPin() const
		{
			return sckPin_;
		}

		inline void LpcSsp::setMisoPin(PinPort* value)
		{
			misoPin_ = value;
		}

		inline void LpcSsp::setMosiPin(PinPort* value)
		{
			mosiPin_ = value;
		}

		inline void LpcSsp::setSckPin(PinPort* value)
		{
			sckPin_ = value;
		}

		inline LPC_SSP_TypeDef* LpcSsp::port()
		{
			return port_;
		}
	}


	/******************************************************************************
	  SSP Ports
	 ******************************************************************************/

	#ifdef LPC_SSP0
	extern Private::LpcSsp* ssp0();
	#endif

	#ifdef LPC_SSP1
	extern Private::LpcSsp* ssp1();
	#endif
}
	
#endif
