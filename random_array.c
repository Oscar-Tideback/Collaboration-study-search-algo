#include "random_array.h"
#include "menu.h"
#include <stdio.h> 
#include <stdlib.h>
#include <time.h> 


unsigned* random_array(size_t size) {

    int i;
    time_t t1;
    unsigned* array = malloc(sizeof(unsigned) * size); 

    srand((unsigned) time(&t1));

    for(i = 0; i < size; i++) {
        array[i] = rand(); //slumpmässigt värde i [i]
    }

    return array;
}
unsigned* shuffle(size_t size) {
    unsigned* shuffle_array = malloc(sizeof(unsigned) * size); 
    srand(time(NULL));

    int i;
    for (i = 0; i < size; i++){
        shuffle_array[i] = i + 1;
    }
    for (i = 0; i < size; i++) {
        int randIndex = rand() % size; 
        int temp = shuffle_array[i]; 
        shuffle_array[i] = shuffle_array[randIndex];
        shuffle_array[randIndex] = temp; 
    } 
    return shuffle_array;
}
unsigned* almostsorted(size_t size) {
    unsigned* sorted_array = malloc(sizeof(unsigned) * size); 
    srand(time(NULL));

    int i;
    for (i = 0; i < size; i++){
        sorted_array[i] = i + 1;
    }
    for (i = 0; i < size; i = i + 10) {
        int randInt = rand() % size; 
        int temp_sorted = sorted_array[i]; 
        sorted_array[i] = sorted_array[randInt];
        sorted_array[randInt] = temp_sorted; 
    } 
    return sorted_array;
}
/*int main() {
    int size = 100000000; 
    unsigned array = almostsorted(size); // shuffle(size); / /random_array(size);

    for(int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }

    return 0;
}*/