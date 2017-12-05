/*
 * SPI.h
 *
 *  Created on: May 4, 2013
 *      Author: denizcan
 */

#ifndef ART_SPI_H_
#define ART_SPI_H_

#include <Art/Event.h>
#include <Art/Private/SpiDefines.h>
#include <Art/Svc.h>
#include <Art/Task.h>

namespace Art
{

	class SpiMaster;

	class SpiPort
	{
	public:
		SpiPort();
	protected:
		struct Settings
		{
			SpiSpeed	speed: 5;
			SpiPolarity	polarity: 1;
			SpiPhase	phase: 1;
		};

		virtual void powerUpPort() = 0;
		virtual void powerDownPort() = 0;
		virtual void configurePinsPort() = 0;
		virtual Word startMasterPort(const Settings& settings) = 0;
		virtual Word startSlavePort(const Settings& settings) = 0;
		virtual Word stopPort() = 0;
		virtual Word readPort(void* readData, Word length) = 0;
		virtual Word writePort(const void* writeData, Word length) = 0;
		virtual Word writeReadPort(const void* writeData,
				void* readData, Word length) = 0;

		Word open();
		Word startMaster(SpiMaster* node);
		Word startSlave(SpiMaster* node);
		Word stop(SpiMaster* node);
		//void doWriteReadCompletedIrq();
	private:
		/*
		class WriteReadCompletedTask : public Task
		{
		public:
			virtual void execute();
		};
		*/

		SpiMaster* activeNode_;
		//WriteReadCompletedTask writeReadCompletedTask_;
		Bool isOpen_;

		friend class SpiMaster;
	};

	inline SpiPort::SpiPort()
	{
		isOpen_ = 0;
	}

	/*
	inline void Spi::doWriteReadCompletedIrq()
	{
		Svc::enqueueIrq(writeReadCompletedTask_);
	}
	*/
}

#if defined(__STM32F4XX__)
	#include <Art/Private/stm32/stm32f4/StmSpi-stm32f4.h>
#endif

#endif /* SPI_H_ */
