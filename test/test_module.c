#include "unity_fixture.h"
#include test_module.h"

TEST_GROUP(module);

TEST_SETUP(module) {

}

TEST_TEAR_DOWN(module) {

}

TEST(module, DoNothing) {
	TEST_ASSERT_EQUAL(2, dummyFunction(2));
}