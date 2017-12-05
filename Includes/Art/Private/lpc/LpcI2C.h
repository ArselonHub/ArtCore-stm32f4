#ifndef ART_LPC_LPCI2C_H
#define ART_LPC_LPCI2C_H

#include <Art/Gpio.h>
#include <Art/I2CPort.h>

namespace Art
{
	typedef struct
	{
	  __IO uint32_t CONSET;                 /*!< Offset: 0x000 (R/W)  I2C Control Set Register */
	  __I  uint32_t STAT;                   /*!< Offset: 0x004 (R/ )  I2C Status Register */
	  __IO uint32_t DAT;                    /*!< Offset: 0x008 (R/W)  I2C Data Register */
	  __IO uint32_t ADR0;                   /*!< Offset: 0x00C (R/W)  I2C Slave Address Register 0 */
	  __IO uint32_t SCLH;                   /*!< Offset: 0x010 (R/W)  SCH Duty Cycle Register High Half Word */
	  __IO uint32_t SCLL;                   /*!< Offset: 0x014 (R/W)  SCL Duty Cycle Register Low Half Word */
	  __O  uint32_t CONCLR;                 /*!< Offset: 0x018 ( /W)  I2C Control Clear Register */
	  __IO uint32_t MMCTRL;                 /*!< Offset: 0x01C (R/W)  Monitor mode control register */
	  __IO uint32_t ADR1;                   /*!< Offset: 0x020 (R/W)  I2C Slave Address Register 1 */
	  __IO uint32_t ADR2;                   /*!< Offset: 0x024 (R/W)  I2C Slave Address Register 2 */
	  __IO uint32_t ADR3;                   /*!< Offset: 0x028 (R/W)  I2C Slave Address Register 3 */
	  __I  uint32_t DATA_BUFFER;            /*!< Offset: 0x02C (R/ )  Data buffer Register */
	  __IO uint32_t MASK0;                  /*!< Offset: 0x030 (R/W)  I2C Slave address mask register 0 */
	  __IO uint32_t MASK1;                  /*!< Offset: 0x034 (R/W)  I2C Slave address mask register 1 */
	  __IO uint32_t MASK2;                  /*!< Offset: 0x038 (R/W)  I2C Slave address mask register 2 */
	  __IO uint32_t MASK3;                  /*!< Offset: 0x03C (R/W)  I2C Slave address mask register 3 */
	} LPC_I2C_TypeDefEx;

	class LpcI2C : public I2CPort
	{
	public:
	protected:
		LPC_I2C_TypeDefEx* port;
		UByte	address;

		virtual void startWritingPort(Word address);
		virtual void writePort();
		virtual void stopWritingPort();
		void processIrq();
	
		friend class I2CIrqLock;
	};

	extern "C" void I2C0_IRQHandler(void);
	
	class LpcI2C0 : public LpcI2C
	{   
	public:
		LpcI2C0();
	
	protected:
		virtual void openPort();
		virtual void closePort();
		virtual void resetBus();

		friend void I2C0_IRQHandler();
	};

	extern LpcI2C0 i2c0;
	
	extern "C" void I2C1_IRQHandler(void);

	class LpcI2C1 : public LpcI2C
	{
	public:
		LpcI2C1();
	
	protected:
		virtual void openPort();
		virtual void closePort();
        virtual void resetBus();
	
		friend void I2C1_IRQHandler();
	};
}

#endif
