#ifndef ART_PRIVATE_STM32F4_SPI_H
#define ART_PRIVATE_STM32F4_SPI_H

#include <Art/Pin.h>
#include <Art/SpiPort.h>

namespace Art
{
	namespace Private
	{
		class StmSpiPort : public SpiPort
		{
		public:
			Pin* misoPin();
			Pin* mosiPin();
			Pin* sckPin();
			void setMisoPin(Pin* value);
			void setMosiPin(Pin* value);
			void setSckPin(Pin* value);
		
		protected:
			// StmSpi interface
			StmSpiPort(SPI_TypeDef* port);
			void handleInterruptIrq();
			SPI_TypeDef* port();
		private:		
			// Spi Port
			virtual Word startMasterPort(const Settings& settings);
			virtual Word startSlavePort(const Settings& settings);
			virtual Word stopPort();
			virtual Word readPort(void* readData, Word length);
			virtual Word writePort(const void* writeData, Word length);
			virtual Word writeReadPort(const void* writeBuffer, void* readBuffer, ShortL length);
		
			void waitIdle();

			SPI_TypeDef*	port_;
			Pin*		misoPin_;
			Pin*		mosiPin_;
			Pin*		sckPin_;
		};
		
		inline StmSpiPort::StmSpiPort(SPI_TypeDef* port)
		{
			port_ = port;
		}

		inline SPI_TypeDef* StmSpiPort::port()
		{
			return port_;
		}
		
		inline Pin* StmSpiPort::misoPin()
		{
			return misoPin_;			
		}
		
		inline Pin* StmSpiPort::mosiPin()
		{
			return mosiPin_;
		}
		
		inline Pin* StmSpiPort::sckPin()
		{
			return sckPin_;
		}
		
		inline void StmSpiPort::setMisoPin(Pin* value)
		{
			misoPin_ = value;
		}
		
		inline void StmSpiPort::setMosiPin(Pin* value)
		{
			mosiPin_ = value;
		}
		
		inline void StmSpiPort::setSckPin(Pin* value)
		{
			sckPin_ = value;
		}

	}
	
	extern Private::StmSpiPort* spi5();

}

#endif
