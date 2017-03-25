/*******************************************************************************
* Copyright (c) 2017 Kevin Turkington
* 
* Permission is hereby granted, free of charge, to any person obtaining a copy
* of this software and associated documentation files (the "Software"), to deal
* in the Software without restriction, including without limitation the rights
* to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
* copies of the Software, and to permit persons to whom the Software is
* furnished to do so, subject to the following conditions:
* 
* The above copyright notice and this permission notice shall be included in all
* copies or substantial portions of the Software.
*
* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
* IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
* FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
* AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
* LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
* OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
* SOFTWARE.
*******************************************************************************/

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