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
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#define SAFE_FREE(x) do { if ((x) != NULL) {free(x); x=NULL;} } while(0)

typedef struct{
    unsigned int size;
    unsigned int capacity;
    char* str;
} hstr_s; //optional type definition.
typedef hstr_s* hstr;

// NAME: hstrNew
// DESC:
hstr hstrNew(const char* init)
{
    hstr s = malloc(sizeof(hstr_s));
    s->size = strlen(init);
    s->capacity = s->size;

    s->str = strdup(init);

    return s;
}

char* hstrGet(hstr s)
{
    if(s == NULL || s->str == NULL ||s->str[0] == '\0'){
        return "";
    }

    return s->str;
}

// NAME: hstrFree
// DESC:
int hstrFree(hstr s)
{
    if(s == NULL || s->str == NULL){
        return EXIT_SUCCESS;
    }
    free(s->str);
    s->str = NULL;
    free(s);
    s = NULL;

    return EXIT_SUCCESS;
}

// NAME: hstrInit
// DESC:
hstr hstrInit(int n)
{
    if(n <= 0){
        return NULL;
    }

    hstr s = malloc(sizeof(hstr));
    s->size = 0;
    s->capacity = n;

    s->str = malloc(n+1 * sizeof(char));
    memset(s,'\0',n);

    return s;
}

// NAME: hstrExtend
// DESC:
int hstrExtend(hstr s, int n)
{
    if(n < 1 || s == NULL || n < s->capacity || s->str == NULL){
        return EXIT_FAILURE;
    }
    int NewLength = s->size + n;
    char* sdup = strdup(s->str);

    SAFE_FREE(s->str);
    s->str = malloc(NewLength * sizeof(char));

    strncpy(s->str,sdup,NewLength);
    SAFE_FREE(sdup);

    return EXIT_SUCCESS;
}

// NAME: hstrResize
// DESC:
int hstrResize(hstr s, int n)
{
    if(n <= 0 || s == NULL || s->str == NULL){
        return EXIT_FAILURE;
    }
    char* sdup = strdup(s->str);

    s->capacity = n;
    if(s->size > n){
        s->size = n;
    }

    SAFE_FREE(s->str);
    s->str = malloc(n * sizeof(char));
    strncpy(s->str,sdup,n);
    SAFE_FREE(sdup);

    return EXIT_SUCCESS;
}

// NAME: hstrClear
// DESC:
int hstrClear(hstr s)
{
    if(s == NULL){
        return EXIT_FAILURE;
    }

    memset(s->str,'\0',s->capacity);

    return EXIT_SUCCESS;
}

// NAME: hstrSplit
// DESC:
char** strSplit(char* string, char* delims)
{
    if(string == NULL || delims == NULL){
        return NULL;
    }

    int n_tokens = 1;
    char* stringcpy = strdup(string);//copy for strtok to destroy.
    char** strArray = malloc(n_tokens * sizeof(char*));

    char* token = strtok(stringcpy,delims);
    while(token != NULL){
        strArray[n_tokens - 1] = strdup(token);
        strArray = realloc(strArray, ++n_tokens * sizeof(char*));

        token = strtok(NULL,delims);
    }

    SAFE_FREE(stringcpy);
    return strArray;
}