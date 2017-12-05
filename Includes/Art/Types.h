#ifndef ART_TYPES_H
#define ART_TYPES_H

#if defined(__LPC1756__) || defined(__LPC1758__)
#	define LPC175X
#		ifndef __LPC17XX__
#			define __LPC17XX__
#		endif
#elif defined(__LPC17XX__) || defined(__LPC1766__) || defined(__LPC1768__) || defined(__LPC1769__)
#		ifndef __LPC17XX__
#			define __LPC17XX__
#		endif
#	define __LPC176X__
#	define __LQFP100__
#endif

#if defined(STM32F429ZITx)
#	define __STM32F429__
#	define STM32F429xx  // for Ac9
#endif

#if defined(__STM32F407__) || defined(__STM32F429__) || defined(__STM32F4XX__)
#	ifndef __STM32F4XX__
#		define __STM32F4XX__
#	endif
#	define WORD32
#	define CORTEX_CM3
#elif defined(STM32F051)
#	define __STM32F0XX__
#	define WORD32
#	define CORTEX_CM0
#elif defined(__LPC112X__)
#	define WORD32
#	define CORTEX_CM0
#elif defined(__LPC17XX__)
#	define WORD32
#	define CORTEX_CM3
#elif defined(__CC430F5137__)
#	define CC430
#	define MSP430
#	define WORD16
#elif defined (__CC2541__)
#	define I8051
#	define WORD8
#	define FASTCALL __near_func 
#elif defined (__AVR_ATmega168__)
#	define ATMEGA
#	define WORD8
#elif defined(QT_CORE_LIB)
#   define WORD32
#else
#	error A device (ex: __LPC1756__) or family (ex:LPC17xx) should be defined
#endif

#if !defined(FASTCALL)
#	define FASTCALL
#endif

#if defined(CORTEX_CM0) || defined(CORTEX_CM3)
#	define IRQ_NESTING
#endif

#include <stdio.h>


#define M_PI		(3.1415926535)
#define PI2DEGREES 	(180.0 / M_PI)

/*
Byte: 1 byte
Short: 2 bytes
Long: 4 bytes

Int and Word are platform dependent.
Int: at least 2 bytes
Word: at least 1 bytes, exactly the word length of the CPU.

Prefer using Word to Int to other types.. Especially in arguments..
Prefer Byte, Short, Long as storage types..
*/

typedef char Char;
typedef unsigned char UByte;
typedef signed char Byte;
typedef signed short Short;
typedef unsigned short UShort;
typedef float Float;
typedef double Double;
typedef float Real;

#if defined(WORD8)
	typedef unsigned char ByteL;
	typedef signed short ShortL;
	typedef unsigned short UShortL;
	typedef signed long Int;
	typedef unsigned long UInt;
	typedef signed long Long;
	typedef unsigned long ULong;
	typedef signed char Word;
	typedef unsigned char UWord;
	typedef unsigned short IntPtr;
#elif defined(WORD16)
	typedef signed int Word;
	typedef unsigned int UWord;
	typedef signed short ByteL;
	typedef unsigned short ByteL;
	typedef signed int ShortL;
	typedef unsigned int UShortL;
	typedef signed long Int;
	typedef unsigned long UInt;
	typedef signed long Long;
	typedef unsigned long ULong;
	typedef unsigned short IntPtr;
	#define ShortLMax	0x7FFF
	#define ShortLMin	0x8000
#else
	typedef signed int Word;
	typedef unsigned int UWord;
	typedef signed int ByteL;
	typedef unsigned int UByteL;
	typedef signed int ShortL;
	typedef unsigned int UShortL;
	typedef signed int Int;
	typedef unsigned int UInt;
	typedef signed long long Long;
	typedef unsigned long long ULong;
	typedef unsigned int IntPtr;
	static const Word BitsInWord = 32;
	static const Word WordMax = 0x7FFFFFFF;
	static const Word WordMin = 0x80000000;
	static const UWord UWordMax = 0xFFFFFFFF;
	static const UWord UWordMin = 0x00000000;

	#define ShortLMax	0x7FFFFFFF
	#define ShortLMin	0x80000000
#endif

static const Int kFrequency1KHz = 1000;
static const Int kFrequency100KHz = kFrequency1KHz * 100;
static const Int kFrequency1MHz = 1000000;
static const Int kFrequency4MHz = kFrequency1MHz * 4;
static const Int kFrequency8MHz = kFrequency1MHz * 8;
static const Int kFrequency16MHz = kFrequency1MHz * 16;

#if defined(I8051)
	struct MethodData
	{
		UShort d;
		UShort i;
		IntPtr address;		
	};
#elif defined(MSP430) || defined(CORTEX_CM0) || defined(CORTEX_CM3)
	struct MethodData
	{
		IntPtr address;	
	};
#endif
	
#define ShortMin (-32768)
#define ShortMax (32767)

#ifdef __cplusplus
	typedef bool 	Bool;
	#define TRUE 	true
	#define FALSE 	false
#else
	#define Bool 	Word;
	#define TRUE 	1
	#define FALSE 	0
#endif

typedef Char* PChar;
typedef UByte* PByte;
typedef void* PVoid;
typedef Short* PShort;
typedef UShort* PUShort;
typedef Int* PInt;
typedef UInt* PUInt;
typedef Long* PLong;
typedef ULong* PULong;
typedef Word* PWord;
typedef UWord* PUWord;

#define IntMax (0x7FFFFFFF)
#define IntMin (-0x80000000)	
	
typedef union
{
	UShort value;
	struct
	{
		UByte lo;
		UByte hi;
	} bytes;
} ShortRec;

union UIntRec
{
	UIntRec() { }
	UIntRec(UShortL lo, UShortL hi)
	{
		ushorts[0] = lo;
		ushorts[1] = hi;
	}

    UInt value;
    UShort ushorts[2];
    UByte bytes[4];
};

union IntRec
{
	IntRec() { }

	IntRec(Int value)
	{
		this->value = value;
	}

    Int value;
    UShort ushorts[2];
    UByte bytes[4];
};

typedef union
{
	void* value;
	struct
	{
		UByte lo;
#if defined(WORD32)
		UByte mid0;
		UByte mid1;
#endif
		UByte hi;
	} bytes;
} PointerRec;

#define forever while (true)

#define offsetOf(type, field)(((IntPtr)&(((type*)1)->field)) - 1)
#define ownerOf(instance, type, member) ((type*)(((Byte*)instance) - offsetOf(type, member)))


#define setBits(p, v) p = p | (v)
#define clearBits(p, v) p = p & ~(v)
#define bit(i) (1 << (i))
#define setBit(t, i) (t |= Bit(i))
#define getBit(t, i) (t & Bit(i))
#define clearBit(t, i) (t &= ~Bit(i))
#define modifyBit(t, i, v) (t = t & ~Bit(i) | ((v) << i))

#define getByteOf(v, i) (((Byte*)&v)[i])
#define setByteOf(v, i, value) (((Byte*)&v)[i] = value)
//typedef Short (*GetCharFn)(FILE * f);
//typedef Short (*PutCharFn)(FILE * f, Char c);

#define TEMPLATE template <typename T>
#define NORETURN __attribute__ ((noreturn))
#define VARAT(addr) __attribute__((at(addr)))

#ifdef __cplusplus
	#define EXTERNC 	extern "C"
	#define EXTERNCPP 	extern "C++"
	#define EXTERN		extern "C++"
#else
	#define EXTERNC		extern
	#define EXTERN		extern
#endif

#if defined(CORTEX_M3)
#define INLINE __attribute__((always_inline))
#define WEAK __atrribute__((weak))
#else
#define INLINE inline
#endif

/*****************************************************************************
	Memory Locations
 *****************************************************************************/
#if defined(__LPC17XX__) || defined(__STM32F4XX__)

inline Word isInRom(const void* p)
{
	return p < (const void*)0x10000000;
}

inline Word isInRam(const void* p)
{
	return p >= (const void*)0x10000000;

}

#endif



/*****************************************************************************
	ASCII Codes
 *****************************************************************************/

#define ASCII_STX	((Char)2)
#define ASCII_ETX	((Char)3)
#define ASCII_EOT	((Char)4)
#define ASCII_ENQ	((Char)5)
#define ASCII_ACK	((Char)6)
#define ASCII_BS	((Char)8)
#define ASCII_TAB	((Char)9)
#define ASCII_LF	((Char)10)
#define ASCII_CR	((Char)13)
#define ASCII_DLE	((Char)16)
#define ASCII_NAK	((Char)21)
#define ASCII_ETB	((Char)23)
#define ASCII_ESC	((Char)27)
#define ASCII_SPACE	((Char)32)
#define ASCII_DEL	((Char)127)

static const Char AsciiBS	= (Char)8;
static const Char AsciiCR	= (Char)13;
static const Char AsciiLF	= (Char)10;

/*****************************************************************************
	Enumaration Operators
 *****************************************************************************/

#define ENUMFLAGS(T)\
	inline T operator|(const T a, const T b) { return (T)((Word)a | b); }\
	inline void operator|=(T& l, const T r) { l = l | r; }\
	inline void operator&=(T& l, const Word r) { l = (T)(l & r); }

#define ENUMETIC(T)\
	inline T operator-(const T l, const Word r) { return (T)((Word)l - r); }\
	inline T operator+(const T l, const Word r) { return (T)((Word)l + r); }\
	inline void operator+=(T& l, const Word r) { l = l + r; }\
	inline void operator-=(T& l, const Word r) { l = l - r; }\
	inline void operator++(T& l) { l = l + 1; }\
	inline void operator++(T& l, Word dummy) { l = l + 1; }\
	inline void operator--(T& l) { l = l - 1; }\
	inline void operator--(T& l, Word dummy) { l = l - 1; }

/*****************************************************************************
	Error Definitions
 *****************************************************************************/

/* Error Handling, first 64 is standard */
typedef Word Result;

enum Errors
{
	ErrorOk = 0,
	ErrorUnsuccessful		= -1,
	ErrorEndOfFile			= -2,
	ErrorNotImplemented 	= -3,
	ErrorReadOnly			= -4,
	ErrorInvalidData		= -6,
	ErrorUnknown			= -7, //TODO make this InvalidOperation
	ErrorOutOfRange 		= -8,
	ErrorCrc				= -9,
	ErrorParity				= -10,
	ErrorTimeOut 			= -11,
	ErrorInvalidFrame		= -12,
	ErrorDuplicate			= -13,
	ErrorOverflow			= -14,
	ErrorInvalidParameter 	= -15,
	ErrorInvalidFormat		= -16,
	ErrorOutOfMemory 		= -17,
	ErrorBusy				= -18,
	ErrorNoCarrier			= -19,
	ErrorUnsupported		= -20,
	ErrorDisabled			= -21,
	ErrorAborted			= -22,
	ErrorInvalidOperation	= -23,
	ErrorAddressNotAcknowledged = -24,
	ErrorDataNotAcknowledged 	= -25,
	ErrorInsufficientResources 	= -26,
	ErrorNotFound				= -27,
	ErrorInvalidVersion			= -28,
	ErrorInvalidSettings		= -29,
	ErrorAccessDenied			= -30,
	ErrorInsufficientSpace		= -31,
	ErrorInvalidBusActivity		= -32
};

#endif

