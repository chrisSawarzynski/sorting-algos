#ifndef SELECTION_SORT
#define SELECTION_SORT
#include "swap.h"


int* SelectionSort(int* Tab, int length)
{
    int max;
    for (int j = length - 1; j >= 1; j--){
        max = j;
        for (int i = j - 1; i >= 0; i--){
            if (Tab[i] > Tab[max])
                max = i;
        }

        swap(&Tab[j], &Tab[max]);

    }
}

#endif 