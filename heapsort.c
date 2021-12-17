#include <stddef.h>
#include <stdio.h>
#include "heapsort.h"
#include "help_functions.h"
#include "menu.h"

// max heap, make largest value as root "child key will be less or same as parent"
static void heapify(unsigned *arr, int i, int size){   
  int largest = i, right = (2*i) + 2, left = (2*i) + 1;   // asumes (initialize) that largest is "root" in subtree
  if(left < size && arr[left] > arr[largest]){            // check if left child is grater then parrent (root "largest") -
    largest = left;                                       //and it should not be larger then size, ignoring leafs. 
  }
  if(right < size && arr[right] > arr[largest]){
    largest = right;
  }                                                       
  if(largest != i){                                       // if largest has changed
    if(arr[i] != arr[largest]){
      swap(arr, i, largest);
      /*arr[largest] = arr[largest] - arr[i];
      arr[i] = arr[largest] + arr[i];
      arr[largest] = arr[i] - arr[largest];*/             
      heapify(arr, largest, size);                        // test again to see if larges is largest
    }
  }                                                       
}

void heap_sort(unsigned *arr, size_t size){
  for(int i = (size/2) -1; i >= 0; --i){                  // will ignore leafs and start at (size/2)-1 and go to 0 "root"
    heapify(arr, i, size);                                // start heapify() from (size/2)-1 as "largest" 
  }
  for(int i = size-1; i >= 0; --i){                       // put largest last in array 
    swap(arr, i, 0);                                      // swaping by sending hole array exept largest value of all (size-1) to heapify()
    /*arr[0] = arr[0] - arr[i];
    arr[i] = arr[0] + arr[i];
    arr[0] = arr[i] - arr[0];*/
    heapify(arr, 0, i);                                   // swap root with last, search for largest value in heap, "i" will be size-1, one less for every call
  }
}