#include <stdio.h> 
#include <stdlib.h>
#include <time.h> 




unsigned* random_array(size_t size) {

    int i;
    time_t t1;
    unsigned* array = malloc(sizeof(unsigned) * size); 

    srand((unsigned) time(&t1));
    printf("\n"); 
    
    for(i = 0; i < size; i++) {
        array[i] = rand(); //slumpmässigt värde i [i]
    }

    return array;
}

int main() {
    int i; 
    unsigned* array = random_array(5); 

    for(i = 0; i < 5; i++) {
        printf("%d\n", array[i]);
    }  

    return 0;
}
 
