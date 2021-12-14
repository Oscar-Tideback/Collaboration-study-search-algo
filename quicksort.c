#include "quicksort.h"
#include "menu.h"
#include <stddef.h>
#include <stdio.h>

// Swaps elements A[i] and A[j];
static void swap(unsigned *A, int i, int j) {
    unsigned tmp = A[i];
    A[i] = A[j];
    A[j] = tmp;
}

// Divides array into two partitions
static int partition(unsigned *A, int low, int high) {
    unsigned pivot = A[high]; // Choose the last element as the pivot
    int i = low - 1; // Temporary pivot index

    for (int j = low; j < high; j++) {
        // If the current element is less than or equal to the pivot
        if (A[j] <= pivot) {
            i++; // Move the temporary pivot index forward
            swap(A, i, j); // Swap the current element with the element at the temporary pivot index
        }
    }

    //Move the pivot element to the corrent position (between the smaller and larger elements)
    i++;
    swap(A, i, high);

    return i; // the pivot index
}

// Sorts a (portion of an) array, divides it into partitions, then sorts those
static void quicksort_recursive_helper (unsigned *A, int low, int high) {
    
    // If indices are in correct order
    if (low >= high || low < 0) {
        return;
    }

    // Partition array and get the pivot index
    int p = partition(A, low, high);

    // Sort the two partitions
    quicksort_recursive_helper(A, low, p - 1); // Left side of pivot
    quicksort_recursive_helper(A, p + 1, high); // Right side of pivot
}

void quicksort(unsigned *A, int n) {
    quicksort_recursive_helper(A, 0, n - 1);
}