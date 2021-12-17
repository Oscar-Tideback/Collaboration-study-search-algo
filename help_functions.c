#include "help_functions.h"

// Swaps elements A[i] and A[j];
void swap(unsigned *A, int i, int j) {
    unsigned tmp = A[i];
    A[i] = A[j];
    A[j] = tmp;
}

void printArray(unsigned *arr, size_t size){
  for(int i = 0; i < size; i++){
    printf("%u ", arr[i]);
  }
}