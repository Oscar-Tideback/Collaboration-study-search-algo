#include <stddef.h>
#include <stdio.h>
#include "heapsort.h"
#include "menu.h"

// max heap, make largest value as root "child key will be less or same as parent"
static void heapify(unsigned *arr, int i, int size){
  //printf("HS2\n");
  int largest = i, right = (2*i) + 2, left = (2*i) + 1; 
  //printf("HS3\n");                                        // asumes (initialize) that largest is "root" in subtree
  if(left < size && arr[left] > arr[largest]){            // check if left child is grater then parrent (root "largest")
    largest = left;                                       // and it should not be larger then size, ignoring leafs. 
  }
  if(right < size && arr[right] > arr[largest]){
    largest = right;
  }                                                       
  if(largest != i){                                       // if largest has changed
    if(arr[i] != arr[largest]){
      unsigned temp;                                    
      temp = arr[largest];
      arr[largest] = arr[i];
      arr[i] = temp;
      //printf("HS4\n");
      heapify(arr, largest, size);                        // test again to see if larges is largest
    }
  }                                                       
}

void heapSort(unsigned *arr, size_t size){
  //printf("HS1\n");
  //printArray(arr, size);
  for(int i = (size/2) -1; i >= 0; --i){                  // will ignore leafs and start at (size/2)-1 and go to 0 "root"
    heapify(arr, i, size);                                // start heaper() from (size/2)-1 as "largest" 
  }
  for(int i = size-1; i >= 0; --i){                       // swaping by sending hole array exept largest value of all (--i) to heaper()
    unsigned temp;                                      
    temp = arr[0];
    arr[0] = arr[i];                                    
    arr[i] = temp;                                        // swap root with last
    heapify(arr, 0, i);                                   // search for largest value in heap, "i" will be size-1, one less for every call
  }
}