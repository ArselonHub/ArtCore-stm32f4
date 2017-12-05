#ifndef ART_LPC_IAP_H
#define ART_LPC_IAP_H

#include <Art/Types.h>

namespace Art
{
	enum IapResult
	{
		IapResultSuccess = 0,
		IapResultInvalidCommand = 1,
		IapResultInvalidSourceAddress = 2,
		IapResultInvalidDestinationAddress = 3,
		IapResultSourceAddressNotMapped = 4,
		IapResultInvalidSector = 7,
		IapNotPrepared = 9
	};
	
	enum IapCommand
	{
		IapCommandPrepare = 50,
		IapCommandWrite = 51,
		IapCommandErase = 52,
		IapCommandBlankCheck = 53,
		IapCommandCompare = 56
	};
	
	class Iap
	{
	public:
		static inline void execute(UInt* command, UInt* result)
		{
			((void(*)(UInt*, UInt*))0x1FFF1FF1)(command, result);
		}
		
		static UInt getSectorNumber(UInt address);
		static UInt getSectorSize(UInt sector);
		static UInt getSectorSizeAtAddress(UInt address);
		static IapResult prepare(UInt startSector, UInt endSector);
		static IapResult prepareAndEraseSectors(UInt startSector, UInt endSector);
		static IapResult prepareAndWrite(UInt address, const void* data, UInt length);		
		static IapResult eraseSectors(UInt startSector, UInt endSector);
		static IapResult write(UInt address, const void* data, UInt length);		
		static IapResult write(UInt startSector, UInt endSector, const void* data, UInt length);
	};
}

#endif
