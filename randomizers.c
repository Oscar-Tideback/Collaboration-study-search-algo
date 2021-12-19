#include "randomizers.h"
#include "menu.h"
#include "qsort_std.h"
#include "help_functions.h"
#include <stdio.h> 
#include <stdlib.h>
#include <time.h> 

unsigned* random(size_t size) {
    int i;
    time_t t1;
    unsigned* array = malloc(sizeof(unsigned) * size); 
    srand((unsigned) time(&t1));
    for(i = 0; i < size; i++) {
        array[i] = rand();
    }
    return array;
}

unsigned* reversed_sorted(size_t size) {
    unsigned* array = random(size);
    qsort_std_reversed(array, size);
    /*unsigned* array = malloc(sizeof(unsigned) * size); 
    for (int i = size; i > 0; i--){
        array[i] = i - 1;
    }*/
    return array;
}

unsigned* sorted(size_t size) {
    unsigned* array = random(size);
    qsort_std(array, size);
    /*unsigned* array = malloc(sizeof(unsigned) * size); 
    for (int i = 0; i < size; i++){
        array[i] = i + 1;
    }*/
    return array;
}

unsigned* unique_random(size_t size) {
    unsigned* array = malloc(sizeof(unsigned) * size); 
    srand(time(NULL));
    int i;
    for (i = 0; i < size; i++){
        array[i] = i + 1;
    }
    for (i = 0; i < size; i++) {
        int randIndex = rand() % size; 
        int temp = array[i]; 
        array[i] = array[randIndex];
        array[randIndex] = temp; 
    } 
    return array;
}

unsigned* almostsorted(size_t size) {
    unsigned* array = malloc(sizeof(unsigned) * size); 
    srand(time(NULL));
    int i;
    for (i = 0; i < size; i++){
        array[i] = i + 1;
    }
    for (i = 0; i < size; i = i + 10) {
        int randIndex = rand() % size; 
        int temp_sorted = array[i]; 
        array[i] = array[randIndex];
        array[randIndex] = temp_sorted; 
    } 
    return array;
}