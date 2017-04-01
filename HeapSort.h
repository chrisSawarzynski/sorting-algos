#ifndef HEAP_SORT
#define HEAP_SORT
#include "swap.h"

void Heapify (int* elements, int i, int heapsize) {
    int l = 2 * i;
    int r = (2 * i) + 1;
    int largest = 0;

    if (l <= heapsize && elements[l] > elements[i]) {
        largest = l;
    } else {
        largest = i;
    }

    if (r <= heapsize && elements[r] > elements[largest]) {
        largest = r;
    }
    if (largest != i) {
        swap(&elements[i], &elements[largest]);
        Heapify(elements, largest, heapsize); 
    }
}

void BuildHeap (int* elements, int length) {
    int heapsize = length;
    for (int i = length / 2; i >= 0; i--) {
        Heapify(elements, i, heapsize);
    }
}




int* HeapSort(int* elements, int length) {
    BuildHeap(elements, length);
    
    int heapsize = length;
    
    for (int i = length; i > 0; i-- ) {
        swap(&elements[0], &elements[i]);
        heapsize -= 1;
        Heapify(elements, 0, heapsize);
    }

    return elements;
}


#endif
