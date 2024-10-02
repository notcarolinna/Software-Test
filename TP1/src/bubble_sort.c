//Implementation of Bubble sort in C
#include <stdio.h>
#include <stdlib.h>
#define swap(t, x, y) t z = x; x = y; y = z;
typedef int TYPE;
void bubble_sort(TYPE [], int);

void bubble_sort(TYPE A[], int n) {
    int i, j, sorted;
    
    for(i = 0; i < n; i++) {
        sorted = 1; 
        
        for(j = 0; j < n - 1; j++) {
            if(A[j] > A[j + 1]) {
                swap(TYPE, A[j], A[j+1]);
                sorted = 0;
            }
        }
        
        if(sorted) break; 
        /*if array is sorted break. 
        This way we have O(n) in best case, instead of always O(n^2)*/
    }
}