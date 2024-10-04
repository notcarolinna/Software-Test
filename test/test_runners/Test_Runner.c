#include "unity.h"
#include "unity_fixture.h"

TEST_GROUP_RUNNER(Sorting){
    RUN_TEST_CASE(Sorting, TestSorting1);
    RUN_TEST_CASE(Sorting, TestSorting2);
    RUN_TEST_CASE(Sorting, TestSorting3);
    RUN_TEST_CASE(Sorting, TestSorting4);
}