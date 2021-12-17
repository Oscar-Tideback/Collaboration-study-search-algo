#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

int cmpfunc (const void * a, const void * b) {
   return ( *(int*)a - *(int*)b );
}

int cmpfunc_reversed (const void * a, const void * b) {
   return ( *(int*)b - *(int*)a );
}

void qsort_std(unsigned *a, int length) {
   qsort(a, length, sizeof(int), cmpfunc);
}

void qsort_std_reversed(unsigned *a, int length) {
   qsort(a, length, sizeof(int), cmpfunc_reversed);
}
