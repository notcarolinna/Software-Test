#include "../Unity/src/unity.h"
#include "../Unity/extras/fixture/src/unity_fixture.h"

TEST_GROUP_RUNNER(Sorting){
    RUN_TEST_CASE(Sorting, TestSorting1);
    RUN_TEST_CASE(Sorting, TestSorting2);
    RUN_TEST_CASE(Sorting, TestSorting3);
    RUN_TEST_CASE(Sorting, TestSorting4);
}