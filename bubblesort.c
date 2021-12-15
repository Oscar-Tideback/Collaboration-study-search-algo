#include <stdio.h>



void bubblesort(unsigned *a, size_t length) {
    for (int i = 0; i < length; i++) {
        for (int j = 0; j < (length - 1); j++) {
            if (a[j] > a[j + 1]) {
                int temp = a[j + 1];
                a [j] = a [j + 1]; 
                a [j + 1] = temp; 
            }
        }
    }
}

/* int main (void) {
    unsigned a[10] = {9,8,7,6,5,4,3,2,1,0}; 

    size_t length = 10; 
    bubble_sort(a, length); 

    for (int i = 0; i < length; i++) {
        printf("%d ", i);
    }
    return 0;
} */