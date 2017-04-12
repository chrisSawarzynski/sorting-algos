#ifndef QSI_H_INCLUDED
#define QSI_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>

struct Stos
{
    int l;
    int p;
};


void QuickSortIterative(int tab[],int n,struct Stos stos[])
{
    int i, j, l, p;
    int pivot, temp;
    int aktStos;

    aktStos=0;
    stos[0].l = 0;
    stos[0].p = n-1;
    do
    {
        l = stos[aktStos].l;
        p = stos[aktStos].p;
        aktStos--;
        do
        {
            i = l;
            j = p;
            pivot = tab[(l+p)/2];
            do
            {
                while(tab[i]<pivot)
                    i=i+1;
                while(pivot<tab[j])
                    j=j-1;
                if (i<=j)
                {
                    temp= tab[i];
                    tab[i] = tab[j];
                    tab[j] = temp;
                    i++;
                    j--;
                }
            }
            while(i<=j);
            if (i<p)
            {
                aktStos++;
                stos[aktStos].l = i;
                stos[aktStos].p = p;
            }
            p = j;
        }
        while(l<p);
    }
    while(aktStos>=0);
}


int* qsi(int* elements, int length) {
    struct Stos stos[1000 + length];
    
    QuickSortIterative(elements, length, stos);

    return elements;
}

#endif // QSI_H_INCLUDED
