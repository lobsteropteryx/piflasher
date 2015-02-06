#include "unity_fixture.h"

static void RunAllTests() {
	RUN_TEST_GROUP(module);
}

int main(int argc, const char *argv[]) {
	return UnityMain(argc, argv, RunAllTests);
}