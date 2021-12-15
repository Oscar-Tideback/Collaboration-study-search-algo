#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h> 
#include <time.h> 
#include <string.h>
#include "menu.h"
#include "quicksort.h"
#include "heapsort.h"
#include "bubblesort.h"
#include "random_array.h"


void printArray(unsigned *arr, size_t size){
  for(int i = 0; i < size; i++){
    printf("%u ", arr[i]);
  }
}

void sorting_test(unsigned* (radnomizer)(size_t), void (algorithm)(unsigned*, size_t), 
                        size_t num_of_tests, size_t size_of_first_test, size_t size_increase){
  clock_t start, end;
  double cpu_time_used;
  char str_arr[64][32];
  unsigned* arr = radnomizer(size_of_first_test); 
  const char *filename;
  if (algorithm == quicksort) { filename = "quicksort.txt"; }
  else if(algorithm == heapSort){ filename = "heapsort.txt"; }
  else if(algorithm == bubblesort){filename = "bubblesort.txt";}
  //printArray(arr, size_of_first_test);
  for(int i = 0; i < num_of_tests+1; i++){
    if(i != 0){// Räkna bort första körning
      size_of_first_test = size_of_first_test + size_increase;  
      arr = radnomizer(size_of_first_test); 
    }
    start = clock();
    algorithm(arr, size_of_first_test);
    end = clock();

    if(i != 0){
      int value = (end-start), results, element = size_of_first_test/(num_of_tests);///1000;  Denna använder jag då mina tider har mindre antal siffror.
      int length = snprintf(NULL, 0, "%d", value);
      //char* valueAsString = malloc(length + 1);
      snprintf(&str_arr[i][0], length + 1, "%d", value);
      //snprintf(valueAsString, length + 1, "%d", value);
      //strcpy(&str_arr[i][0], valueAsString);
      FILE *file = fopen(filename, "w");
      for(int i = 1; i < num_of_tests; i++){
        results = fprintf(file, "%i, %s\n", element * i , *(str_arr+i));
      }
      if (results == EOF) {
        printf("Fail...");
      }
      fclose(file);
    }
  }
  free(arr);  
}

int main(int argc, char *argv[]){
  printf("Sorting:\n");
	//sorting_test(shuffle, bubblesort,  5, 0, 5000);
 // printf("Quicksort:\n");
  sorting_test(shuffle, quicksort,  11, 500, 500000);
  while(true){
    the_menu();
  }
}