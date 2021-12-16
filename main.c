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
#include "qsort_std.h"

void printArray(unsigned *arr, size_t size){
  for(int i = 0; i < size; i++){
    printf("%u ", arr[i]);
  }
}

void sorting_test(unsigned* (radnomizer)(size_t), void (algorithm)(unsigned*, size_t),
                  size_t num_of_tests, size_t size_of_first_test, size_t size_increase){
  clock_t start, end;
  char str_arr[128][32];
  int current_test = size_of_first_test;
  unsigned* arr = radnomizer(current_test);
  const char *filename;
  if(radnomizer == shuffle){
    if (algorithm == quicksort){ filename = "01shuffle_quicksort.txt"; }
    else if(algorithm == heapsort){ filename = "01shuffle_heapsort.txt"; }
    else if(algorithm == qsort_std){ filename = "01shuffle_qsort_std.txt"; }
    else if(algorithm == bubblesort){ filename = "01shuffle_bubblesort.txt"; }
  }
  else if(radnomizer == almostsorted){
    if (algorithm == quicksort){ filename = "01almostsorted_quicksort.txt"; }
    else if(algorithm == heapsort){ filename = "01almostsorted_heapsort.txt"; }
    else if(algorithm == qsort_std){ filename = "01almostsorted_qsort_std.txt"; }
    else if(algorithm == bubblesort){ filename = "01almostsorted_bubblesort.txt"; }
  }
  else if(radnomizer == qsort_std){
    if (algorithm == quicksort){ filename = "01qsort_std_quicksort.txt"; }
    else if(algorithm == heapsort){ filename = "01qsort_std_heapsort.txt"; }
    else if(algorithm == qsort_std){ filename = "01qsort_std_qsort_std.txt"; }
    else if(algorithm == bubblesort){ filename = "01qsort_std_bubblesort.txt"; }
  }
  else if(radnomizer == random_array){
    if (algorithm == quicksort){ filename = "01random_array_quicksort.txt"; }
    else if(algorithm == heapsort){ filename = "01random_array_heapsort.txt"; }
    else if(algorithm == qsort_std){ filename = "01random_arrayqsort_std.txt"; }
    else if(algorithm == bubblesort){ filename = "01random_array_bubblesort.txt"; }
  }
  else if(radnomizer == radnomizer){
    if (algorithm == quicksort){ filename = "01quicksort.txt"; }
    else if(algorithm == heapsort){ filename = "01heapsort.txt"; }
    else if(algorithm == qsort_std){ filename = "01qsort_std.txt"; }
    else if(algorithm == bubblesort){ filename = "01bubblesort.txt"; }
  }
  for(int i = 0; i < num_of_tests; i++){
    if(i != 0){// Räkna bort första körning
      current_test = current_test + size_increase;  
      arr = radnomizer(current_test); 
    }
    start = clock();
    algorithm(arr, current_test);
    end = clock();
    printf("Run: %d\nTime: %lu\n",current_test, (end-start));
    if(i != 0){
      int value = (end-start), results; 
      int length = snprintf(NULL, 0, "%d", value);
      snprintf(&str_arr[i][0], length + 1, "%d", value);
      FILE *file = fopen(filename, "w");
      for(int i = 1; i < num_of_tests; i++){
        results = fprintf(file, "%lli, %s\n", ((i * size_increase) + size_of_first_test), *(str_arr+i));
      }
      if (results == EOF){
        printf("File fail...");
      }
      fclose(file);
    }
  }
  free(arr);  
}

int main(int argc, char *argv[]){
  printf("Sorting:\n");
  sorting_test(random_array,       quicksort,  25, 10000, 500000);
  sorting_test(shuffle,            quicksort,  25, 10000, 500000);
  sorting_test(almostsorted,       quicksort,  25, 10000, 500000);
	
  sorting_test(random_array,       heapsort,  25, 10000, 500000);
  sorting_test(shuffle,            heapsort,  25, 10000, 500000);
  sorting_test(almostsorted,       heapsort,  25, 10000, 500000);

  sorting_test(random_array,       qsort_std,  25, 10000, 500000);
  sorting_test(shuffle,            qsort_std,  25, 10000, 500000);
  sorting_test(almostsorted,       qsort_std,  25, 10000, 500000);

  sorting_test(random_array,       bubblesort,  25, 10000, 5000);
  sorting_test(shuffle,            bubblesort,  25, 10000, 5000);
  sorting_test(almostsorted,       bubblesort,  25, 10000, 5000);
  /*while(true){
    the_menu();
  }*/
}