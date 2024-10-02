//Implementation of Selection sort in C
#include <stdio.h>
#include <stdlib.h>
#define swap(t, x, y) t z = x; x = y; y = z;
typedef int TYPE;
void selection_sort(TYPE [], int);

void selection_sort(TYPE A[], int n) {
    int i, j, min;
    for(i = 0; i < n - 1; i++) {
        min = i;
        for(j = i + 1; j < n; j++) {
            if(A[min] > A[j]) min = j;
        }
        if(min != i) { 
            swap(TYPE, A[i], A[min]); 
            // '{' and '}' are  needed when using macros inside condition
        }
    }
}