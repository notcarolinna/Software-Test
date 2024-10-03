#include "unity_fixture.h"

static void RunAllTests(void)
{
  RUN_TEST_GROUP(Foo);
}

int main(int argc, const char * argv[])
{
  return UnityMain(argc, argv, RunAllTests);
}
