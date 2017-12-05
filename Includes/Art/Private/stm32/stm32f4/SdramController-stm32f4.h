#ifndef ART_STM32_STM32F4_SDRAMCONTROLLER_H
#define ART_STM32_STM32F4_SDRAMCONTROLLER_H

#include <Art/Pin.h>

namespace Art
{		
	enum SdramReadPipeDelay
	{
		SdramReadPipeDelay0,
		SdramReadPipeDelay1,
		SdramReadPipeDelay2
	};
	
	enum SdramBurstReadMode
	{
		SdramBurstReadModeNever,
		SdramBurstReadModeAlways
	};
	
	enum SdramClockDivision
	{
		SdramClockDivision2 = 2,
		SdramClockDivision3 = 3
	};
	
	enum SdramCasLatency
	{
		SdramCasLatency1 = 1,
		SdramCasLatency2,
		SdramCasLatency3
	};
	
	enum SdramInternalBankCount
	{
		SdramInternalBankCount2,
		SdramInternalBankCount4		
	};
	
	enum SdramDataBusWidth
	{
		SdramDataBusWidth8Bits,
		SdramDataBusWidth16Bits,
		SdramDataBusWidth32Bits
	};
	
	enum SdramRowAdressWidth
	{
		SdramRowAdressWidth11Bits,
		SdramRowAdressWidth12Bits,
		SdramRowAdressWidth13Bits
	};
	
	enum SdramColumnAdressWidth
	{
		SdramColumnAdressWidth8Bits,
		SdramColumnAdressWidth9Bits,
		SdramColumnAdressWidth10Bits,
		SdramColumnAdressWidth11Bits
	};
	
	enum SdramMode
	{
		SdramModeBurstLength1			= 0 << 0,
		SdramModeBurstLength2			= 1 << 0,
		SdramModeBurstLength4			= 2 << 0,
		SdramModeBurstLength8			= 3 << 0,
		SdramModeBurstLengthFullPage	= 7 << 0,

		SdramModeBurstTypeSequential	= 0 << 3,
		SdramModeBurstTypeInterleaved	= 1 << 3,

		SdramModeLatency2				= 2 << 4,
		SdramModeLatency3				= 3 << 4,

		SdramModeWriteBurstProgrammed	= 0 << 9,
		SdramModeWriteBurstSingle = 1 << 9
	};

	enum SdramCommand
	{
		SdramCommandNormalMode = 0,
		SdramCommandEnableClock	= 1,
		SdramCommandPrechargeAll = 2,
		SdramCommandAutorefresh = 3,
		SdramCommandLoadMode = 4,
		SdramCommandSelfRefresh = 5,
		SdramCommandPowerDown = 6
	};

	class SdramController
	{
	public:
		SdramController(Word index);
		void* pointer();
		void setRowToColumnDelay(Word value);
		void setRowPrechargeDelay(Word value);
		void setRecoveryDelay(Word value);
		void setRowCycleDelay(Word value);
		void setSelfRefreshTime(Word value);
		void setSelfRefreshExitDelay(Word value);
		void setLoadModeToActiveDelay(Word value);		
		void setBurstReadMode(SdramBurstReadMode value);
		void setReadPipeDelay(SdramReadPipeDelay value);
		void setClockDivision(SdramClockDivision value);
		void setCasLatency(SdramCasLatency value);
		void setInternalBankCount(SdramInternalBankCount value);
		void setDataBusWidth(SdramDataBusWidth value);
		void setRowAddressWidth(SdramRowAdressWidth value);
		void setColumnAddressWidth(SdramColumnAdressWidth value);
		void executeCommand(SdramCommand command, UWord argument = 0);
		void open();
	private:
		UWord					m_index:1;
		SdramColumnAdressWidth	m_columnAdressWidth:2;
		SdramRowAdressWidth		m_rowAdressWidth:2;
		SdramDataBusWidth		m_dataBusWidth:2;
		SdramInternalBankCount	m_internalBankCount:2;
		SdramCasLatency			m_casLatency:2;
		UWord					m_writeProtection:1;
		SdramClockDivision		m_clockDivision:2;
		SdramBurstReadMode		m_burstReadMode:2;
		SdramReadPipeDelay		m_readPipeDelay:2;
		UWord					m_loadModeToActiveDelay:4;
		UWord					m_selfRefreshExitDelay:4;
		UWord					m_selfRefreshTime:4;
		UWord					m_rowCycleDelay:4;
		UWord					m_recoveryDelay:4;
		UWord					m_rowPrechargeDelay:4;
		UWord					m_rowToColumnDelay:4;
	};

	inline SdramController::SdramController(Word index)
	{
		m_index = index;
	}
	
	inline void* SdramController::pointer()
	{
		return (m_index == 0) ? (void*)0xC0000000 : (void*)0xD0000000;
	}

	inline void SdramController::setRowToColumnDelay(Word value)
	{
		m_rowToColumnDelay = value - 1;
	}

	inline void SdramController::setRowPrechargeDelay(Word value)
	{
		m_rowPrechargeDelay = value - 1;
	}

	inline void SdramController::setRecoveryDelay(Word value)
	{
		m_recoveryDelay = value - 1;
	}

	inline void SdramController::setRowCycleDelay(Word value)
	{
		m_rowCycleDelay = value - 1;
	}

	inline void SdramController::setSelfRefreshTime(Word value)
	{
		m_selfRefreshTime = value - 1;
	}

	inline void SdramController::setSelfRefreshExitDelay(Word value)
	{
		m_selfRefreshExitDelay = value - 1;
	}

	inline void SdramController::setLoadModeToActiveDelay(Word value)
	{
		m_loadModeToActiveDelay = value - 1;
	}

	inline void SdramController::setBurstReadMode(SdramBurstReadMode value)
	{
		m_burstReadMode = value;
	}

	inline void SdramController::setReadPipeDelay(SdramReadPipeDelay value)
	{
		m_readPipeDelay = value;
	}

	inline void SdramController::setClockDivision(SdramClockDivision value)
	{
		m_clockDivision = value;
	}

	inline void SdramController::setCasLatency(SdramCasLatency value)
	{
		m_casLatency = value;
	}

	inline void SdramController::setInternalBankCount(SdramInternalBankCount value)
	{
		m_internalBankCount = value;
	}

	inline void SdramController::setDataBusWidth(SdramDataBusWidth value)
	{
		m_dataBusWidth = value;
	}

	inline void SdramController::setRowAddressWidth(SdramRowAdressWidth value)
	{
		m_rowAdressWidth = value;
	}

	inline void SdramController::setColumnAddressWidth(SdramColumnAdressWidth value)
	{
		m_columnAdressWidth = value;
	}
}

#endif
