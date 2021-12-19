#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h> 
#include <time.h> 
#include <string.h>
#include "menu.h"
#include "quicksort.h"
#include "heapsort.h"
#include "bubblesort.h"
#include "randomizers.h"
#include "qsort_std.h"

void sorting_test(unsigned* (radnomizer)(size_t), void (algorithm)(unsigned*, size_t),
                  size_t num_of_tests, size_t size_of_first_test, size_t size_increase){
  clock_t start, end;
  //time_t start, end;
  char str_arr[128][32];
  int current_test = size_of_first_test, counter = 1;
  unsigned* arr = radnomizer(current_test);
  const char *filename;

  if(radnomizer == unique_random){
    if (algorithm == quicksort){ filename = "01unique_random_quicksort.txt"; }
    else if(algorithm == heapsort){ filename = "01unique_random_heapsort.txt"; }
    else if(algorithm == qsort_std){ filename = "01unique_random_qsort_std.txt"; }
    else if(algorithm == bubblesort){ filename = "01unique_random_bubblesort.txt"; }
  }
  else if(radnomizer == almostsorted){
    if (algorithm == quicksort){ filename = "01almostsorted_quicksort.txt"; }
    else if(algorithm == heapsort){ filename = "01almostsorted_heapsort.txt"; }
    else if(algorithm == qsort_std){ filename = "01almostsorted_qsort_std.txt"; }
    else if(algorithm == bubblesort){ filename = "01almostsorted_bubblesort.txt"; }
  }
  else if(radnomizer == random){
    if (algorithm == quicksort){ filename = "01random_quicksort.txt"; }
    else if(algorithm == heapsort){ filename = "01random_heapsort.txt"; }
    else if(algorithm == qsort_std){ filename = "01random_qsort_std.txt"; }
    else if(algorithm == bubblesort){ filename = "01random_bubblesort.txt"; }
  }
  else if(radnomizer == reversed_sorted){
    if (algorithm == quicksort){ filename = "01reversed_sorted_quicksort.txt"; }
    else if(algorithm == heapsort){ filename = "01reversed_sorted_heapsort.txt"; }
    else if(algorithm == qsort_std){ filename = "01reversed_sorted_std.txt"; }
    else if(algorithm == bubblesort){ filename = "01reversed_sorted_bubblesort.txt"; }
  }
  else if(radnomizer == sorted){
    if (algorithm == quicksort){ filename = "01sorted_quicksort.txt"; }
    else if(algorithm == heapsort){ filename = "01sorted_heapsort.txt"; }
    else if(algorithm == qsort_std){ filename = "01sorted_qsort_std.txt"; }
    else if(algorithm == bubblesort){ filename = "01sorted_bubblesort.txt"; }
  }

  for(int i = 0; i < num_of_tests; i++){
    if(i != 0){// Exclude first run
      current_test = current_test + size_increase;  
      arr = radnomizer(current_test); 
    }
    //start = time(NULL);
    start = clock();
    algorithm(arr, current_test);
    end = clock();
    //end = time(NULL);

    counter++;
    printf("Run %i: %d\nTime: %lu\n", counter-1, current_test, (end-start));

    if(i != 0){
        FILE *file = fopen(filename, "w");
        int value = (end-start), results;
        int length = snprintf(NULL, 0, "%d", value);
        snprintf(&str_arr[i][0], length + 1, "%d", value);
        for(int i = 1; i < num_of_tests; i++){
          results = fprintf(file, "%lli, %s\n", ((i * size_increase) + size_of_first_test)/1000, *(str_arr+i));
      }
      if (results == EOF){
        printf("File fail...");
      }
      fclose(file);
    }
  }
  free(arr);  
}
/*
void printGraph(){
  char print[128][128];
  for(int i = 0; i < 0; i++){
    if(print[i][128] == 1)
      printf("1");
    else if(print[i][128] == 0)
      printf("0");
  }
}
*/
int main(int argc, char *argv[]){
  printf("Sorting:\n");
  printf("\n\nheapsort reversed_sorted\n");
  sorting_test( reversed_sorted,    heapsort,   5, 10000, 5000);
  printf("\n\nheapsort sorted\n");
  sorting_test( sorted,             heapsort,   5, 10000, 5000);
  printf("\n\nheapsort almostsorted\n");
  sorting_test( almostsorted,       heapsort,   5, 10000, 5000);
  /*
  sorting_test( random,             qsort_std,   34, 100000, 600000);
  sorting_test( unique_random,      qsort_std,   34, 100000, 600000);
  sorting_test( almostsorted,       qsort_std,   34, 100000, 600000);
  sorting_test( reversed_sorted,    qsort_std,   34, 100000, 600000);
  sorting_test( sorted,             qsort_std,   34, 100000, 600000);

  sorting_test( random,             heapsort,    34, 100000, 600000);
  sorting_test( unique_random,      heapsort,    34, 100000, 600000);
  sorting_test( almostsorted,       heapsort,    34, 100000, 600000);
  sorting_test( reversed_sorted,    heapsort,    34, 100000, 600000);
  sorting_test( sorted,             heapsort,    34, 100000, 600000);

  sorting_test( random,             quicksort,   34, 100000, 600000);
  sorting_test( unique_random,      quicksort,   34, 100000, 600000);
  sorting_test( almostsorted,       quicksort,   34, 100000, 600000);
  sorting_test( reversed_sorted,    quicksort,   34, 100000, 600000);
  sorting_test( sorted,             quicksort,   34, 100000, 600000);

  sorting_test( random,             bubblesort,  14, 10000, 10000);
  sorting_test( unique_random,      bubblesort,  14, 10000, 10000);
  sorting_test( almostsorted,       bubblesort,  14, 10000, 10000);
  sorting_test( reversed_sorted,    bubblesort,  14, 10000, 10000);
  sorting_test( sorted,             bubblesort,  14, 10000, 10000);*/

  /*while(true){
    the_menu();
  }*/
}