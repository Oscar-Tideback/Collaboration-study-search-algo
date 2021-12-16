#include "sorting_test.h"

#include <stddef.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>

void sorting_test(unsigned* (randomizer)(size_t), void (algorithm)(unsigned*, size_t), size_t *N, size_t size_N, const char *filename) {
    
    // Variables
    size_t n;
    unsigned *A;
    clock_t start, end;

    FILE *file = fopen(filename, "w");

    for (size_t i = 0; i < size_N; i++) {
        n = N[i];
        A = randomizer(n);
        start = clock();
        algorithm(A, n);
        end = clock();
        free(A);

        fprintf(file, "%zu, %ld\n", n, end - start);
    }

    fclose(file);
}