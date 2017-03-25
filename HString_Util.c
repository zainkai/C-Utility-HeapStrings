#include "HString_Util.h"

char* hstrnew(const char* init)
{
    return strdup(init);
}

void hstrfree(char* string)
{
    if(string == NULL){
        return;
    }

    free(string);
}

char* hstrinit(int n)
{
    if(n == 0){
        return NULL;
    }

    char* string = malloc((n + 1) * sizeof(char));
    memset(string,'\0',n + 1);

    return string;
}

char* hstrextend(char* string,int n)
{
    int strLen = strlen(string);
    char* newString = hstrinit((strLen + n));

    strncpy(newString,string,strLen);

    hstrfree(string);
    string = newString;

    return string;
}

char* hstrclear(char* string)
{
    memset(string,'\0',strlen(string));

    return string;
}

char** hstrsplit(char* string, char* delims)
{
    int n_tokens = 1;
    char* stringcpy = strdup(string);//copy for strtok to destroy.
    char** strArray = malloc(n_tokens * sizeof(char*));

    char* token = strtok(stringcpy,delims);
    while(token != NULL){
        strArray[n_tokens - 1] = hstrnew(token);
        strArray = realloc(strArray, ++n_tokens * sizeof(char*));

        token = strtok(NULL,delims);
    }

    hstrfree(stringcpy);
    return strArray;
}