#ifndef test_module_INC
#define test_module_INC
#include "unity_fixture.h"
#endif

TEST_GROUP_RUNNER(module) {
    RUN_TEST_CASE(module, dummyTest);
}