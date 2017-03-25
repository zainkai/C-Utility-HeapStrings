#include "HString_Util.h"

// NAME: hstrnew
// DESC:
hstring hstrnew(const hstring init)
{
    return strdup(init);
}

// NAME: hstrfree
// DESC:
void hstrfree(hstring string)
{
    if(string == NULL){
        return;
    }

    free(string);
}

// NAME: hstrinit
// DESC:
hstring hstrinit(size_t n)
{
    if(n == 0){
        return NULL;
    }

    hstring string = malloc((n + 1) * sizeof(char));
    memset(string,'\0',n + 1);

    return string;
}

// NAME: hstrextend
// DESC:
hstring hstrextend(hstring string,size_t n)
{
    size_t strLength = strlen(string);
    hstring newString = hstrinit((strLength + n));

    strncpy(newString,string,strLength);

    hstrfree(string);
    string = newString;

    return string;
}

// NAME: hstrresize
// DESC:
hstring hstrresize(hstring string, size_t newlength)
{
    int offset = newlength - hstrtruelen(string);

    if(offset == 0){
        return string;
    }
    else if(offset < 0){
        hstring newString = hstrinit(newlength);

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

// NAME: hstrtruelen
// DESC:
size_t hstrtruelen(hstring string)
{
    if(string == NULL){
        return 0;
    }

    return (sizeof(string)/sizeof(char));
}

// NAME: hstrclear
// DESC:
hstring hstrclear(hstring string)
{
    memset(string,'\0',hstrtruelen(string));

    return string;
}

// NAME: hstrsplit
// DESC:
hstring* hstrsplit(hstring string, hstring delims)
{
    int n_tokens = 1;
    hstring stringcpy = strdup(string);//copy for strtok to destroy.
    hstring* strArray = malloc(n_tokens * sizeof(hstring));

    hstring token = strtok(stringcpy,delims);
    while(token != NULL){
        strArray[n_tokens - 1] = hstrnew(token);
        strArray = realloc(strArray, ++n_tokens * sizeof(hstring));

        token = strtok(NULL,delims);
    }

    hstrfree(stringcpy);
    return strArray;
}