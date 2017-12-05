#ifndef ART_LPC_INTERNALFLASH_H
#define ART_LPC_INTERNALFLASH_H

namespace Art
{
	class InternalFlash : public Flash
	{
	public:
		InternalFlash();
	
		// Flash Interface
		virtual Result erase(UInt startAddress, UInt endAddress);
		virtual Result write(UInt address, const void* buffer, UShortL length);
		virtual Result read(UInt address, void* buffer, UShortL length);
		virtual Int getPageSize();
		virtual UInt getMemorySize();
		virtual Int getSectorSize();
		virtual UShortL getMinimumChunkSize();
	
	protected:
	};
};

#endif
