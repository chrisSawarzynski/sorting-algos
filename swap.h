#ifndef SWAP
#define SWAP

void swap(int * a, int * b) {
    int tmp = *a;
    *a = *b;
    *b = tmp; 
}


#endif