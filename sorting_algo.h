#ifndef SORTING_ALGO
#define SORTING_ALGO
#include <time.h>


int* sorting_algo (int* instance, int n){
    time_t start = clock();
    while(difftime(clock(), start)/CLOCKS_PER_SEC < 5.6);
    
    return instance;
}

#endif