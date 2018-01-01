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
			Pin* misoPin() const;
			Pin* mosiPin() const;
			Pin* sckPin() const;
			void setMisoPin(Pin* value);
			void setMosiPin(Pin* value);
			void setSckPin(Pin* value);
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
			Pin* misoPin_;
			Pin* mosiPin_;
			Pin* sckPin_;
		};

		inline LpcSsp::LpcSsp(LPC_SSP_TypeDef* port)
		{
			port_ = port;
		}

		inline Pin* LpcSsp::misoPin() const
		{
			return misoPin_;
		}

		inline Pin* LpcSsp::mosiPin() const
		{
			return mosiPin_;
		}

		inline Pin* LpcSsp::sckPin() const
		{
			return sckPin_;
		}

		inline void LpcSsp::setMisoPin(Pin* value)
		{
			misoPin_ = value;
		}

		inline void LpcSsp::setMosiPin(Pin* value)
		{
			mosiPin_ = value;
		}

		inline void LpcSsp::setSckPin(Pin* value)
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
