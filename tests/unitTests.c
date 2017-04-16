#include <stdio.h>
#include <string.h>

#include "minunit.h"
#include "../src/HString_Util.c"

MU_TEST(hstrNew_TEST){
	hstr s = hstrNew("Hello World!");

	mu_check(s != NULL);

	mu_check(0 == strcmp("Hello World!",s->str));

	free(s->str);
	free(s);
}

MU_TEST(hstrFree_TEST){
	hstr s = hstrNew("Hello World!");

	mu_check(EXIT_FAILURE == hstrFree(NULL));

	mu_check(EXIT_SUCCESS == hstrFree(s));

	mu_check(EXIT_FAILURE == hstrFree(s));

	hstrFree(s);
}

MU_TEST(hstrInit_TEST){
	hstr s = NULL;

	s = hstrInit(0);
	mu_check(NULL == s);

	s = hstrInit(89);
	mu_check(NULL != s);

	hstrFree(s);
}

MU_TEST(hstrExtend_TEST){
	hstr s = NULL;

	mu_check(EXIT_FAILURE == hstrExtend(NULL,1));

	mu_check(EXIT_FAILURE == hstrExtend(s,1));
	
	mu_check(EXIT_FAILURE == hstrExtend(s,0));

	s = hstrNew("Hello World!");
	mu_check(EXIT_FAILURE == hstrExtend(s,-1));

	mu_check(EXIT_SUCCESS == hstrExtend(s,1000));

	hstrFree(s);
}

MU_TEST(hstrResize_TEST){
	hstr s = hstrNew("Hello World!");

	mu_check(EXIT_FAILURE == hstrResize(NULL,1));
	
	mu_check(EXIT_FAILURE == hstrResize(s,0));

	mu_check(EXIT_SUCCESS == hstrResize(s,5));
	mu_check(0 == strcmp("Hello",s->str));
	mu_check(5 == s->size);
	mu_check(5 == s->capacity);

	mu_check(EXIT_SUCCESS == hstrResize(s,100));
	mu_check(5 == s->size);
	mu_check(100 == s->capacity);

	hstrFree(s);
}

MU_TEST(hstrClear_TEST){

}

MU_TEST_SUITE(test_suite){
	MU_RUN_TEST(hstrNew_TEST);
	MU_RUN_TEST(hstrFree_TEST);
	MU_RUN_TEST(hstrInit_TEST);
	MU_RUN_TEST(hstrExtend_TEST);
	MU_RUN_TEST(hstrResize_TEST);
	MU_RUN_TEST(hstrClear_TEST);
}

int main(int argc, char *argv[]) {
	MU_RUN_SUITE(test_suite);
	MU_REPORT();
	return 0;
}