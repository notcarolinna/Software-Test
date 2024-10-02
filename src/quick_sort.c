//Implementation of Quick Sort in C
#include <stdio.h>
#include <stdlib.h>
#define swap(t, x, y) { t z = x; x = y; y = z; }
typedef int TYPE;
int partition(TYPE [], int, int);
void quick_sort(TYPE [], int, int);

int partition(TYPE A[], int p, int r) {
    TYPE x = A[r]; //pivot
    int i = p - 1, j;
    for(j = p; j < r ; j++) {
        if(A[j] <= x) {
            i = i + 1;
            swap(TYPE, A[i], A[j]); 
        }
    }
    i = i + 1;
    swap(TYPE, A[i], A[r]);
    return i;
}
void quick_sort(TYPE A[], int p, int r) {
    if(p < r) {
        int t = (rand() % ( r - p + 1) + p);
        swap(TYPE, A[t], A[r]); 
        //Used to avoid O(n^2) worst case
        
        int q = partition(A, p, r);
        quick_sort(A, p, q - 1);
        quick_sort(A, q + 1, r);
    }
}