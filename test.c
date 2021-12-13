#include "quicksort.h"

#include <stdio.h>
#include <stddef.h>

#define ARRAY_SIZE(A) ( sizeof(A) / sizeof(A[0]) )

static void print_array (unsigned *A, size_t num_of_elements) {
    printf("{");
    for (size_t i = 0; i < num_of_elements; i++) {
        printf("%u, ", A[i]);
    }
    printf("}\n");
}

int main() {
    unsigned A[] = {1, 2, 3, 4, 5};

    printf("Before sorting\n");
    print_array(A, ARRAY_SIZE(A));

    printf("\n");
    quicksort(A, ARRAY_SIZE(A));

    printf("After sorting\n");
    print_array(A, ARRAY_SIZE(A));

    return 0;
}