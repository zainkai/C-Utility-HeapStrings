#ifndef _HSTRING_UTIL_
#define _HSTRING_UTIL_

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

typedef char* hstring; //optional type definition.

char* hstrnew(const char* init);
void hstrfree(char* string);
char* hstrinit(size_t n);
char* hstrextend(char* string,size_t n);
size_t hstrtruelen(char* string);
char* hstrclear(char* string);
char** hstrsplit(char* string, char* delims);

#endif