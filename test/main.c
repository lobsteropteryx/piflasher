#include "unity_fixture.h"

static void runAllTests() {
    RUN_TEST_GROUP(module);
    RUN_TEST_GROUP(flasher);
}

int main(int argc, char * argv[]) {
    UnityMain(argc, argv, runAllTests);
}
