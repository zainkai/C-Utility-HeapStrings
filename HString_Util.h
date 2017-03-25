#ifndef _HSTRING_UTIL_
#define _HSTRING_UTIL_

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct hstring{
    int len;
    char* str;
} hstring;

char* createstr(const char* init);
void freestr(char* string);
char* initnstr(int n);
char** splitstr(char* string, char* delims);


#endif