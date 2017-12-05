#ifndef ART_MATH_H
#define ART_MATH_H

#include <Art/Types.h>

namespace Art
{
	/****************************************************************************
		Short Functions
	 ****************************************************************************/

	inline Short absShort(Short a)
	{
		return (a < 0) ? -a : a;
	}

	inline Short minShort(Short a, Short b)
	{
		return (a < b) ? a : b;
	}

	inline Short maxShort(Short a, Short b)
	{
		return (a > b) ? a : b;
	}

    inline Short clipShort(Int value, Short lower, Short upper)
	{
		if (value < lower)
			return lower;
		if (value > upper)
			return upper;
        return (Short)value;
	}

	inline Short clipShort(Int value)
	{
        return clipShort(value, ShortMin, ShortMax);
	}

	inline void swapShort(Short& a, Short& b)
	{
		Short c = a;
		a = b;
		b = c;
	}

	/****************************************************************************
		ShortL Functions
	 ****************************************************************************/

	inline ShortL absShortL(ShortL a)
	{
		return (a < 0) ? -a : a;
	}

	inline ShortL minShortL(ShortL a, ShortL b)
	{
		return (a < b) ? a : b;
	}

	inline ShortL maxShortL(ShortL a, ShortL b)
	{
		return (a > b) ? a : b;
	}

	inline void swapShortL(ShortL& a, ShortL& b)
	{
		ShortL c = a;
		a = b;
		b = c;
	}

	inline ShortL clipShortL(ShortL value, ShortL min, ShortL max)
	{
		return (value < min) ? min : ((value > max) ? max : value);
	}

	/****************************************************************************
		Int Functions
	 ****************************************************************************/

	inline Int absInt(Int a)
	{
		return (a < 0) ? -a : a;
	}

	inline Int minInt(Int a, Int b)
	{
		return (a < b) ? a : b;
	}

	inline Int maxInt(Int a, Int b)
	{
		return (a > b) ? a : b;
	}

	inline Int clipInt(Int value, Int lower, Int upper)
	{
		if (value < lower)
			return lower;
		if (value > upper)
			return upper;
		return value;
	}

	/****************************************************************************
		UShortL Functions
	 ****************************************************************************/

	inline UShortL minUShortL(UShortL a, UShortL b)
	{
		return (a < b) ? a : b;
	}

	inline UShortL maxUShortL(UShortL a, UShortL b)
	{
		return (a > b) ? a : b;
	}

	inline UShortL clipUShortL(UShortL value, UShortL lower, UShortL upper)
	{
		if (value < lower)
			return lower;
		if (value > upper)
			return upper;
		return value;
	}

	/****************************************************************************
		Word Functions
	 ****************************************************************************/

	inline Word absWord(Word a)
	{
		return (a < 0) ? -a : a;
	}

	inline Word minWord(Word a, Word b)
	{
		return (a < b) ? a : b;
	}

	inline Word maxWord(Word a, Word b)
	{
		return (a > b) ? a : b;
	}

	inline Word clipWord(Word value, Word lower, Word upper)
	{
		if (value < lower)
			return lower;
		if (value > upper)
			return upper;
		return value;
	}

	inline void swapWord(Word& a, Word& b)
	{
		Word c = a;
		a = b;
		b = c;
	}

	inline UWord minUWord(UWord a, UWord b)
	{
		return (a < b) ? a : b;
	}

	inline UWord maxUWord(UWord a, UWord b)
	{
		return (a > b) ? a : b;
	}


	/****************************************************************************
		Float Functions
	 ****************************************************************************/

	inline Float minFloat(Float a, Float b)
	{
		return (a < b) ? a : b;
	}

	inline Float maxFloat(Float a, Float b)
	{
		return (a > b) ? a : b;
	}

	inline Float clipFloat(Float value, Float lower, Float upper)
	{
		if (value < lower)
			return lower;
		if (value > upper)
			return upper;
		return value;
	}
	
	
	/****************************************************************************
		Generic Functions
	 ****************************************************************************/

	template <class T>
	Bool isEven(T value)
	{
		return (value & 0x1) == 0;
	}

	template <class T>
	Bool isOdd(T value)
	{
		return (value & 0x1);
	}
}

#endif
