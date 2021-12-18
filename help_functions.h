#ifndef HELP_FUNCTIONS_H
#define HELP_FUNCTIONS_H
#include <stddef.h>
#include <stdio.h>
#include <stdbool.h>


// Swaps elements A[i] and A[j];
void swap(unsigned *A, int i, int j);
void printArray(unsigned *arr, size_t size);
bool is_sorted (unsigned *A, size_t n);

#endif // #ifndef HELP_FUNCTIONS_H