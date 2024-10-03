#include "unity.h"
#include "unity_fixture.h"

TEST_GROUP_RUNNER(Foo)
{
  RUN_TEST_CASE(Foo, TestFoo1);
  RUN_TEST_CASE(Foo, TestFoo2);
}
