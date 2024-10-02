#include <stdlib.h>
#include <string.h>

// Functions    
void counting_sort(int*, int);
void radix_sort(int*, int);
void bubble_sort(int*, int);
void insertion_sort(int*, int);
void selection_sort(int*, int);
void heap_sort(int*, int);
void merge_sort(int*, int, int);
void quick_sort(int*, int, int);
int sort(int*, int, char*, int);

enum types{COUNTING, RADIX, BUBBLE, INSERTION, SELECTION, HEAP, MERGE, QUICK};