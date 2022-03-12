#ifndef _TEST_H_
#define _TEST_H_

#include <stdio.h>
#include <assert.h>

#define CHECK(TEST_RESULT, EXPECTED_RESULT, ACTUAL_RESULT) { \
		TEST_RESULT &=(EXPECTED_RESULT == ACTUAL_RESULT); \
		if (EXPECTED_RESULT != ACTUAL_RESULT) printf("TEST ERROR on file: %s, line: %d\n", __FILE__, __LINE__); }
//#define CHECK(B) if (!B) printf("TEST ERROR on file: %s, line: %d\n", __FILE__, __LINE__)
//#define CHECK(B) assert(B)

#endif