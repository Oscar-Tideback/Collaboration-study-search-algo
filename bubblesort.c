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