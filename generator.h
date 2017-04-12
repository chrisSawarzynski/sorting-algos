#ifndef GENERATOR_H_INCLUDED
#define GENERATOR_H_INCLUDED
#include <string.h>
#include "TestInstances.h"


//generowanie losowych elementow
void Random(struct TestInstances* Instance, int length)
{
    (*Instance).elements = malloc(length * sizeof(int));

    
    (*Instance).type_name = strdup("Losowa");
    (*Instance).size = length;

    for(int i = 0; i < length; i++){
        (*Instance).elements[i] = 1 + rand()%length;

    }

}



//generowanie losowych elementow
void Constant(struct TestInstances* Instance, int length)
{
    (*Instance).elements = malloc(length * sizeof(int));

    
    (*Instance).type_name = strdup("Stabilna");
    (*Instance).size = length;

    for(int i = 0; i < length; i++){
        (*Instance).elements[i] = 666;
    }

}



//funkcja generujaca tablice posortowana rosnaco
void AscSort(struct TestInstances* Instance,int length)
{
    (*Instance).elements = malloc(length * sizeof(int));

    (*Instance).type_name = strdup("Posortowana");
    (*Instance).size = length;

    for(int i = 0; i < length; i++){
        (*Instance).elements[i]=i;
    }
}

//funkcja generujaca tablice posortowana malejaco
void DescSort(struct TestInstances* Instance,int length)
{
    (*Instance).elements = malloc(length * sizeof(int));

    (*Instance).type_name = strdup("Odwrotnie posortowana");
    (*Instance).size = length;
    
    for(int i = length - 1, x = 0; i >= 0; i--, x++){
        (*Instance).elements[i] = 0;
    }

}
//funkcja generujaca tablice o rozkladzie elementow V-ksztaltnym
void fnVShaped(struct TestInstances* Instance, int length)
{
    (*Instance).elements = malloc(length * sizeof(int));

    (*Instance).type_name = strdup("V-ksztaltna");
    (*Instance).size = length;
    int half = length/2;

    for(int i = 0 ; i < half; i++){
        (*Instance).elements[i] = length - i;
    }

    for(int i = half; i < length; i++){
        (*Instance).elements[i] = i;
    }

}
//funkcja generujaca tablice o rozkladzie elementow A-ksztaltnym
void fnAShaped(struct TestInstances* Instance, int length)
{
    (*Instance).elements = malloc(length * sizeof(int));
    
    (*Instance).type_name = strdup("A-ksztaltna");
    (*Instance).size = length;
    int half = length/2;

    for(int i = 0 ; i < half; i++){
        (*Instance).elements[i] = i;
    }

    for(int i = 0; i < length; i++){
        while (half + i > length - 1) {
            half -= 1;
        }
        (*Instance).elements[i + half] = half - i;
    }

}



#endif // GENERATOR_H_INCLUDED
