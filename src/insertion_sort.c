//Implementation of Insertion sort in C
#include <stdio.h>
#include <stdlib.h>
typedef int TYPE;
void insertion_sort(TYPE [], int);

void insertion_sort(TYPE A[], int n) {
    int i, j;
    TYPE temp;
    
    for(i = 1; i < n; i++) {
        temp = A[i];
        j = i;
        while(j > 0 && A[j-1] > temp) {
            A[j] = A[j - 1];
            j--;
        }
        A[j] = temp;
    }
}