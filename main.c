#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "TestedFunctions.h"
#include "sorting_algo.h"

#define CALLBACK_COUNT 1



void register_callback( struct TestedFunctions* sortingAlgos, int index, char * name, void (*callback)(int, int*));



int main(int argc, char *argv[]) {
    struct TestedFunctions sortingAlgos[CALLBACK_COUNT];


    register_callback(sortingAlgos, 0, "sorting_algo", sorting_algo);


    for (int i = 0; i < CALLBACK_COUNT; i++) {
        int instance[2] = {1,2};
        sortingAlgos[i].callback(1, instance);
    }

    return 0;
}

void register_callback( struct TestedFunctions* sortingAlgos, int index, char * name, void (*callback)(int, int*)) {
    if ( index < 0 || index > CALLBACK_COUNT - 1) {
        printf("CALLBACK INDEX OUT OF RANGE!\n");
    } else {
        sortingAlgos[index].name = name;
        sortingAlgos[index].callback = callback;
    }
}
