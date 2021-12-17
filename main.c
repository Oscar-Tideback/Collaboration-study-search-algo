#include "randomizers.h"
#include "heapsort.h"
#include "quicksort.h"
#include "heapsort.h"
#include "bubblesort.h"
#include "sorting_test2.h"

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
    
    /* size_t n0 = 100000;
    size_t size_N = 10;
    unsigned* (*randomizer)(size_t) = random_;

    size_t N[size_N];
    for (size_t i = 0, n = n0; i < size_N; i++, n <<= 1) {
        N[i] = n;
    }

    // Quicksort
    //sorting_test(randomizer, quicksort, N, size_N, "quicksort.txt");

    // Heapsort
    //sorting_test(randomizer, heapsort, N, size_N, "heapsort.txt");

    // Bubblesort
    //sorting_test(randomizer, bubblesort, N, size_N, "bubblesort.txt"); */

    return 0;
}  
