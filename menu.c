#include <stdio.h>
#include <stdlib.h>
#include "heapsort.h"
#include "quicksort.h"
#include "menu.h"
#include "main.h"
#include "random_array.h"
#include "bubblesort.h"


static void test_sortingalgorithm() {
        void (*algorithm)(unsigned*, size_t);
        printf("Test soring algorithm\n");
        printf("\n");
        printf("Choose algorithm\n");
        printf("1: Bubblesort\n");
        printf("2: Quicksort\n");
        printf("3: Heapsort\n");


        int choice1;
        scanf("%d", &choice1);
        getc(stdin);
        switch (choice1) 
        {
        case 1: 
        algorithm = bubblesort;
            break;
        case 2: 
        algorithm = quicksort;
            break;
        case 3: 
        algorithm = heapSort;
            break;       
    }

    printf("Enter number of tests: ");
        size_t num_of_tests; 
        scanf("%zu", &num_of_tests); 

        printf("Number of elements of first test: ");
        size_t size_of_first_test;
        scanf("%zu", &size_of_first_test);
        
        printf("Linear increase of number of elements: ");
        size_t size_increase;
        scanf("%zu", &size_increase);

        //printf("Enter the name of the file you wont the result to: ");
        //char filename[32];
        //scanf("%s", filename); 
        sorting_test(shuffle, algorithm, num_of_tests , size_of_first_test , size_increase);
}

void the_menu() {
    menu:
    printf("\n ****MENU**** \n");
    printf("\n");
    printf("Choices\n");
    printf("\n");
    printf("1: Test sorting algorithm\n");
    printf("2: Quit\n");
    printf("\n");
    printf("Choice: \n");
    int choice;
    scanf("%d", &choice);
    getc(stdin);
    switch (choice) 
    {
    case 1: 
        test_sortingalgorithm();
        break;  
    case 2: 
        exit(0);
    }
    goto menu; 
}

