#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

int cmpfunc (const void * a, const void * b) {
   return ( *(int*)a - *(int*)b );
}

void qsort_std(unsigned *a, int length) {
   qsort(a, length, sizeof(int), cmpfunc);
}