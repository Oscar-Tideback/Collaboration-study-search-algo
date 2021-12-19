/* #include "randomizers.h"
#include "heapsort.h"
#include "quicksort.h"
#include "heapsort.h"
#include "bubblesort.h"
#include "sorting_test2.h"
#include "help_functions.h"
#include "qsort_std.h"

#include <stdio.h>
#include <stdbool.h>
#include <time.h>

int main (void) {
    
    size_t n0 = 10000000;
    size_t size_N = 10;
    unsigned* (*randomizer)(size_t) = almostsorted;

    size_t N[size_N];

    // Linear increase
    for (size_t i = 0, n = n0; i < size_N; i++, n += n0) {
        N[i] = n;
    }

    // Exponential increase
    for (size_t i = 0, n = n0; i < size_N; i++, n <<= 1) {
        N[i] = n;
    }

    // Quicksort
    //sorting_test2(randomizer, quicksort, N, size_N, "quicksort.txt");

    // Heapsort
    //sorting_test2(randomizer, heap_sort, N, size_N, "heapsort.txt");

    // Bubblesort
    //sorting_test2(randomizer, bubblesort, N, size_N, "bubblesort.txt");

    // std::qsort
    sorting_test2(randomizer, qsort_std, N, size_N, "qsort_almost_sorted_lin.txt");

    return 0;
}   */
