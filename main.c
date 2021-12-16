#include "random_array.h"
#include "heapsort.h"
#include "quicksort.h"
#include "heapsort.h"
#include "sorting_test.h"

#include <stdio.h>
#include <stdbool.h>
#include <time.h>

/*  static bool is_sorted (unsigned *A, size_t n) {
    for (int i = 0; i < n - 1; i++) {
        if (A[i] > A[i + 1]) {
            return false;
        }
    }
    return true;
} */

int main (void) {
    
    size_t n0 = 100000;
    size_t size_N = 10;
    //const char *filename = "test.txt";

    size_t N[size_N];
    for (size_t i = 0, n = n0; i < size_N; i++, n <<= 1) {
        N[i] = n;
    }

    //size_t N[3] = {10, 20, 30};

    sorting_test(random_array, quicksort, N, size_N, "quicksort.txt");
    sorting_test(random_array, heapSort, N, size_N, "heapsort.txt");

    return 0;
}  