#ifndef INSERTION_SORT
#define INSERTION_SORT

int* InsertionSort(int* Tab, int length)
{
    int i;
    int key;
    for(int j = 1; j < length; j++){
        
        key = Tab[j];
        i = j - 1;
        while(i>=0 && Tab[i] > key){
            Tab[i + 1] = Tab[i];
            i = i - 1;
            }
        Tab[i + 1] = key;
    }
    return Tab;
}

#endif