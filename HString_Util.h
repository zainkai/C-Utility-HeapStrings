#ifndef _HSTRING_UTIL_
#define _HSTRING_UTIL_

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct hstring{
    int len;
    char* str;
} hstring;

char* hstrnew(const char* init);
void hstrfree(char* string);
char* hstrinit(size_t n);
char* hstrextend(char* string,size_t n);
char* hstrclear(char* string);
char** hstrsplit(char* string, char* delims);

#endif