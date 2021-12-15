#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h> 
#include <time.h> 
#include <string.h>
#include "menu.h"
#include "quicksort.h"
#include "heapsort.h"
#include "random_array.h"

void printArray(unsigned *arr, size_t size);

static void sorting_test(unsigned* (radnomizer)(size_t), void (algorithm)(unsigned*, size_t), 
                        size_t num_of_tests, size_t size_of_first_test, size_t size_increase, const char *filename){
  clock_t start, end;
  double cpu_time_used;
  char str_arr[64][32];
  unsigned* arr = radnomizer(size_of_first_test); 
  if (algorithm == quicksort) { filename = "quicksort"; }
  else if(algorithm == heapSort){ filename = "heapsort"; }
  /*else if(algorithm == bublesort){filename = "bublesort";}*/
  //printArray(arr, size_of_first_test);
  for(int i = 0; i < num_of_tests; i++){
    if(i != 0){// Räkna bort första körning
      size_of_first_test = size_of_first_test + size_increase;  
      arr = radnomizer(size_of_first_test); 
    }
    start = clock();
    algorithm(arr, size_of_first_test);
    end = clock();

    if(i != 0){
      int value = (end-start), results, element = size_of_first_test/(num_of_tests-1);
      int length = snprintf( NULL, 0, "%d", value );
      char* valueAsString = malloc( length + 1 );
      snprintf( valueAsString, length + 1, "%d", value );
      strcpy(&str_arr[i][0], valueAsString);
      FILE *file = fopen(filename, "w");
      for(int i = 1; i < num_of_tests; i++){
        printf("\n");
        results = fprintf(file, "%i, %s\n", element * i , str_arr+i);
        printf("%s\n", str_arr+i);
      }
      if (results == EOF) {
      printf("Fail...");
      }
      fclose(file);
    }
  }
  free(arr);  
}

void printArray(unsigned *arr, size_t size){
  for(int i = 0; i < size; i++){
    printf("%u ", arr[i]);
  }
}

int main(int argc, char *argv[]){
  printf("Heapsort:\n");
	sorting_test(shuffle, heapSort,  4, 0, 500000, "file_name");
 // printf("Quicksort:\n");
  //sorting_test(shuffle, quicksort,  11, 500, 500000, "file_name");
  while(true){
    the_menu();
  }
}