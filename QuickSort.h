#ifndef QUICKSORT_H_INCLUDED
#define QUICKSORT_H_INCLUDED

int Partition(int* Tab, int p, int r)
{
    int x = Tab[(p+r)/2];
    int i = p - 1;
    int j = r + 1;
    int temp = 0;

    while(true){
       do{
            j = j - 1;
       }while(Tab[j] > x);

       do{
            i = i + 1;
       }while(Tab[i] < x);

        if (i < j){
            temp = Tab[i];
            Tab[i] = Tab[j];
            Tab[j] = temp;
            }
        else{
            return j;
            }
        }
}

void QuickSort (int* Tab, int p, int r)
{
    int q = 0;

    if(p < r){
        q = Partition(Tab, p, r);
        QuickSort(Tab, p, q);
        QuickSort(Tab, q+1, r);
        }
}

int* QuickSortMain(int* elements, int length) {
    QuickSort(elements, 1, length);
    return elements;
}

#endif // QUICKSORT_H_INCLUDED
