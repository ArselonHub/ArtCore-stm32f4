#ifndef ART_STR_H
#define ART_STR_H

#include <Art/DateTime.h>
#include <Art/Types.h>

namespace Art
{
	enum NumericFormat
	{
		NumericFormatBinary,
		NumericFormatDecimal,
		NumericFormatHex,
		NumericFormatHexBig
	};
	
	enum FPFormat
	{
		FPFormatNormal,
		FPFormatScientific,
	};

	namespace Str
	{
		extern Char* fromLongDateTime(Char* destination, DateTime& value);
		extern Char* fromLongTime(Char* destination, DateTime& value);
		extern Char* fromLongDate(Char* destination, DateTime& value);
		extern Result toTime(DateTime& destination, const Char* source);
		extern Result toTime(DateTime& dt, const Char* source, UShortL size);		
		extern Result toDate(DateTime& destination, const Char* source);
		extern Result toDate(DateTime& destination, const Char* source, UShortL size);

		extern Char* copy(Char* destination, ShortL destinationSize, const Char* source);
		extern Char* copy(Char* destination, ShortL destinationSize, const Char* source, ShortL sourceSize);
		
		extern Char* append(Char* destination, ShortL destinationSize, const Char c);
		extern Char* append(Char* destination, ShortL destinationSize, const Char* source);
		extern Char* append(Char* destination, ShortL destinationSize, const Char* source, ShortL sourceSize);
		
		extern Word compare(const Char* left, ShortL leftSize, const Char* right);
		extern Word compare(const Char* left, ShortL leftSize, const Char* right, ShortL rightSize);			

		extern Bool isEqual(const Char* left, ShortL leftSize, const Char* right);
		extern Bool isEqual(const Char* left, ShortL leftSize, const Char* right, ShortL rightSize);
		extern Bool isNotEqual(const Char* left, ShortL leftSize, const Char* right);
		extern Bool isNotEqual(const Char* left, ShortL leftSize, const Char* right, ShortL rightSize);
		
		extern const Char* find(const Char* s, Char c);
		inline Char* find(Char* s, Char c) { return (Char*)find(s, c); }
		extern ShortL getLength(const Char* s);
		extern ShortL getLength(const Char* s, ShortL size);
		
		extern const Char* getEnd(const Char* s);
		extern const Char* getEnd(const Char* s, ShortL size);
		
		inline Char* getEnd(Char* s) { return (Char*)getEnd((const Char*)s); }
		inline Char* getEnd(Char* s, ShortL size) { return (Char*)getEnd((const Char*)s, size); }
		
		
		extern Bool startsWith(const Char* left, ShortL leftSize, const Char* right);
		extern Bool startsWith(const Char* left, ShortL leftSize, const Char* right, ShortL rightSize);
		
		extern const Char* trimLeft(const Char* s);
		extern Char* fromIntRaw(Char* s, Int value, NumericFormat base);
		extern Char* fromUIntRaw(Char* s, UInt value, NumericFormat format);
		extern Char* fromFloatRaw(Char* s, Float value, Word precision);
		extern Result toInt(Int& destination, const Char* source, ShortL size, 
			NumericFormat base = NumericFormatDecimal);
	}
}

#endif
