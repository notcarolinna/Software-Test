#include "../Unity/src/unity.h"
#include "../Unity/extras/fixture/src/unity_fixture.h"

TEST_GROUP_RUNNER(Sorting){
    RUN_TEST_CASE(Sorting, TestSortingAscending);
    RUN_TEST_CASE(Sorting, TestSortingDescending);
    RUN_TEST_CASE(Sorting, TestSortingDuplicates);
    RUN_TEST_CASE(Sorting, TestSortingNegative);
    RUN_TEST_CASE(Sorting, TestSortingMixed);
    RUN_TEST_CASE(Sorting, TestSortingMinSize);
    RUN_TEST_CASE(Sorting, TestSortingMaxSize);
    RUN_TEST_CASE(Sorting, TestSortingInvalidSize);
    RUN_TEST_CASE(Sorting, TestSortingZeroSize);   
    RUN_TEST_CASE(Sorting, TestNegativeValuesFunction);   
}

