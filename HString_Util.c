#include "HString_Util.h"

// NAME:
// DESC:
char* hstrnew(const char* init)
{
    return strdup(init);
}

// NAME:
// DESC:
void hstrfree(char* string)
{
    if(string == NULL){
        return;
    }

    free(string);
}

// NAME:
// DESC:
char* hstrinit(size_t n)
{
    if(n == 0){
        return NULL;
    }

    char* string = malloc((n + 1) * sizeof(char));
    memset(string,'\0',n + 1);

    return string;
}

// NAME:
// DESC:
char* hstrextend(char* string,size_t n)
{
    size_t strLength = strlen(string);
    char* newString = hstrinit((strLength + n));

    strncpy(newString,string,strLength);

    hstrfree(string);
    string = newString;

    return string;
}

// NAME:
// DESC:
char* hstrresize(char* string, size_t newlength)
{
    int offset = newlength - hstrtruelen(string);

    if(offset == 0){
        return string;
    }
    else if(offset < 0){
        char* newString = hstrinit(newlength);

        strncpy(newString,string,newlength);
        newString[newlength + 1] = '\0';

        hstrfree(string);
        string = newString;
    }
    else{
        string = hstrextend(string,offset);
    }

    return string;
}

// NAME:
// DESC:
size_t hstrtruelen(char* string)
{
    if(string == NULL){
        return 0;
    }

    return (sizeof(string)/sizeof(char));
}

// NAME:
// DESC:
char* hstrclear(char* string)
{
    memset(string,'\0',hstrtruelen(string));

    return string;
}

// NAME:
// DESC:
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