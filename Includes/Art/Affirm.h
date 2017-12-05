/*
 * Affirm.h
 *
 *  Created on: 30 Nis 2014
 *      Author: denizcan
 */

#ifndef AFFIRM_H_
#define AFFIRM_H_

#include <Art/Types.h>

#define affirm(x)\
{\
	Result r = (x);\
	if (r < 0) return r;\
}

#define _STR(x) __STR(x)
#define __STR(x) #x

/*
//#define affirmDo(e, d)\
//{\
//	if ((e) == 0) \
//	{\
//		debugf4("Affirmation negative, (" _STR(e) "), file" _STR(__FILE__)  ", line " _STR(__LINE__) "\n");\
//		(d);\
//	}\
//}
//
//#define affirm(e) affirmDo(e, )
//
//
//#define affirmResultDo(e, d)\
//{\
//	Result r = (e);\
//	if (r < 0)\
//	{\
//		debugf4("Affirmation failed, (" _STR(e) "), file" _STR(__FILE__)  ", line " _STR(__LINE__) "\n");\
//		return r;\
//	}\
//}
//
//#define affirmResult(e) affirmDo(e, return )
//
//#define affirmResult(e)\
//{\
//	affirmResultDo(e, return r);\
//}
*/


#endif /* AFFIRM_H_ */
