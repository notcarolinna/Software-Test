#include <stdlib.h>
#include <stdio.h>
#include "src/sort.h"
#include "Unity/src/unity.h"

void print_array(int* a, int length){
    int i = 0;
    printf("[");
    do {
        if(i > 0) printf(", ");
        printf("%d", a[i]);
    } while(++i < length);
    printf("]\n");
}


int main(void)
{

    int a[] = {9, 8, 7, 6, 5, 4, 3, 2, 1};
    int length = sizeof(a) / sizeof(int);
    
    printf("Unsorted: \n");
    print_array(a, length);

    int status = sort(a, length, "On2", BUBBLE);
    printf("Status: %d\n", status);
    
    printf("Sorted: \n");
    print_array(a, length);

    return EXIT_SUCCESS;
   
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