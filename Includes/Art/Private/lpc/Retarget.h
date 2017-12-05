#ifndef RETARGET_H
#define RETARGET_H

#include <Art/Types.h>
#include <stdio.h>

//#include <rt_misc.h>

typedef enum
{
	RC_PUT,
	RC_GET,
	RC_ERROR
} RetargetCommand;

typedef int (*RetargetCallback)(void* instance, RetargetCommand command, int ch); 

struct __FILE 
{ 
	void* instance;
	RetargetCallback callback;
};

#ifdef __cplusplus
	EXTERNC void retarget(void* f, void *instance, RetargetCallback callback);
	
	template <class T>
	void retarget(void* f, void* instance, int (T::*callback)(RetargetCommand, int));
#else
	EXTERNC void retarget(FILE* f, void *instance, RetargetCallback callback);
#endif


#endif
