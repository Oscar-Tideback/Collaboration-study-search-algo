#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h> 
#include <time.h> 
#include "menu.h"
#include "quicksort.h"
#include "heapsort.h"
#include "random_array.h"

void printArray(unsigned *arr, size_t size);

void sorting_test(unsigned* (radnomizer)(size_t), void (algorithm)(unsigned*, size_t), size_t num_of_tests, size_t size_of_first_test, size_t size_increase, const char *filename){
  double cpu_time_used;
  unsigned* arr = radnomizer(size_of_first_test); 
  printArray(arr, size_of_first_test);
  for(int i = 0; i < num_of_tests; i++){
    if(i != 0){
      size_of_first_test = size_of_first_test + size_increase;  
      arr = radnomizer(size_of_first_test); 
    }
    clock_t start, end;
    start = clock();
    algorithm(arr, size_of_first_test);
    end = clock();
    //cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    //printf("Size:(%d) Start: %d End: %d: CPU Time: %d, Time: %d\n",size, start, end, cpu_time_used, (end-start));
    printf("%d,%d\n", i, (end-start));
    }
    printArray(arr, size_of_first_test);
  free(arr);  
}

void printArray(unsigned *arr, size_t size){
  for(int i = 0; i < size; i++){
    printf("%u ", arr[i]);
  }
}

int main(int argc, char *argv[]){
	sorting_test(shuffle, quicksort,  2, 500, 50, "file_name");
  while(true){
    the_menu();
  }
}