#include "test_module.h"

TEST_GROUP(flasher);

TEST_SETUP(flasher) {

}

TEST_TEAR_DOWN(flasher) {

}

TEST(flasher, dummyTest) {
	TEST_ASSERT_EQUAL(2, dummyFunction(2));
}
