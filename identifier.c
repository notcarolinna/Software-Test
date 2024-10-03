#include <stdlib.h>
#include <stdio.h>
#include "src/sort.h"
#include "Unity/src/unity.h"

void setUp(void) {
}

void tearDown(void) {
}

void test_bubble_sort(void) {
    int a[] = {9, 8, 7, 6, 5, 4, 3, 2, 1};
    int length = sizeof(a) / sizeof(int);
    int expected[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};

    int status = sort(a, length, "On2", BUBBLE);
    TEST_ASSERT_EQUAL(0, status);
    TEST_ASSERT_EQUAL_INT8_ARRAY(expected, a, length); 
}

void test_invalid_length(void) {
    int a[] = {1};
    int status = sort(a, 1, "On2", BUBBLE);
    TEST_ASSERT_EQUAL(1, status); 
}

int main(void) {
    UNITY_BEGIN();
    RUN_TEST(test_bubble_sort);
    RUN_TEST(test_invalid_length);
    return UNITY_END();
}


/*
int sort(int* a, int lenght, char* type, int algorithm)
    - a: ponteiro para o vetor de inteiros a ser ordenado
    - lenght: comprimento do vetor passado (contém de 2 a 20 elementos)
    - type: complexidade do algoritmo, podendo ser On, On2, Onlogn
    - algorithm: COUNTING, RADIX, BUBBLE, INSERTION, SELECTION
                 HEAP, MERGE, QUICK
*/
