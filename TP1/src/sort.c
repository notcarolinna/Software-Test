#include "sort.h"

int sort(int* a, int length, char* type, int algorithm) {
    int status = 0;
    int *s = (int*)malloc(sizeof(int)*length);
    memcpy(s,a,sizeof(int)*(length));
    if (length < 2 || length > 20) {
        status = 1;
    }
    else {
        switch(algorithm){
            case COUNTING:
                if (!strcmp(type,"On"))
                    counting_sort(s, length);
                else
                    status = 1;
                break;
            case RADIX:
                if (!strcmp(type,"On"))
                    radix_sort(s, length);
                else
                    status = 1;
                break;
            case BUBBLE:
                if (!strcmp(type,"On2"))
                    bubble_sort(s, length);
                else
                    status = 1;
                break;
            case INSERTION:
                if (!strcmp(type,"On2"))
                    insertion_sort(s, length);
                else
                    status = 1;
                break;
            case SELECTION:
                if (!strcmp(type,"On2"))
                    selection_sort(s, length);
                else
                    status = 1;
                break;
            case HEAP:
                if (!strcmp(type,"Onlogn"))
                    heap_sort(s, length);
                else
                    status = 1;
                break;
            case MERGE:
                if (!strcmp(type,"Onlogn"))
                    merge_sort(s, 0, length - 1);
                else
                    status = 1;
                break;
            case QUICK:
                if (!strcmp(type,"Onlogn"))
                    quick_sort(s, 0, length - 1);
                else
                    status = 1;
                break;
            default:
                status = 1;
                break;
            }
    }
    memcpy(a,s,sizeof(int)*(length));
    free(s);
    return status;
}