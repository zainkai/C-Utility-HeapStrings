#ifndef _HSTRING_UTIL_
#define _HSTRING_UTIL_

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

typedef char* hstring; //optional type definition.

hstring hstrnew(const hstring init);
void hstrfree(hstring string);
hstring hstrinit(size_t n);
hstring hstrextend(hstring string,size_t n);
hstring hstrresize(hstring string, size_t newlength);
size_t hstrtruelen(hstring string);
hstring hstrclear(hstring string);
hstring* hstrsplit(hstring string, hstring delims);

#endif