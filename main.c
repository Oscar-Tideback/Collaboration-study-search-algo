#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h> 
#include <time.h> 
#include "menu.h"
#include "quicksort.h"
#include "heapsort.h"
#include "random_array.h"

typedef struct List{
  char *array[16];
} list;

void printArray(unsigned *arr, size_t size);

static void sorting_test(unsigned* (radnomizer)(size_t), void (algorithm)(unsigned*, size_t), 
                        size_t num_of_tests, size_t size_of_first_test, size_t size_increase, const char *filename){
  clock_t start, end;
  double cpu_time_used;
  char str_arr[64][32];
  unsigned* arr = radnomizer(size_of_first_test); 
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
      //int result = end-start;
      sprintf(*str_arr+i, "%i, %i",i , (end-start));
      printf("%s\n", *str_arr+i);
    }
    //cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    //printf("Size:(%d) Start: %d End: %d: CPU Time: %d, Time: %d\n",size, start, end, cpu_time_used, (end-start));
    }
    //printArray(arr, size_of_first_test);
    if (algorithm == quicksort) {
      filename = "quicksort";
    }
    else if(algorithm == heapSort){
      filename = "heapsort";
    }
    /*else if(algorithm == bublesort){
      filename = "bublesort";
    }*/
    saveFile(str_arr, filename, num_of_tests);
  free(arr);  
}

void printArray(unsigned *arr, size_t size){
  for(int i = 0; i < size; i++){
    printf("%u ", arr[i]);
  }
}

void saveFile(char *str_arr, const char *filename, int antal){
  //FILE *file = fopen(filename, "w");
  //int results = fputs(str_arr, file);
  for(int i = 1; i < antal; i++){
    printf("Save function\n");
    //fprintf(file,"%s\n", *str_arr+x);
    printf("%s\n", str_arr+i);
  }
  /*if (results == EOF) {
      printf("Fail...");
  }
  fclose(file);*/
}

int main(int argc, char *argv[]){
  printf("Heapsort:\n");
	sorting_test(shuffle, heapSort,  4, 500, 500000, "file_name");
 // printf("Quicksort:\n");
  //sorting_test(shuffle, quicksort,  11, 500, 500000, "file_name");
  while(true){
    the_menu();
  }
}