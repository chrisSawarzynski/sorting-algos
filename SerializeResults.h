#ifndef SERIALIZE_RESULTS
#define SERIALIZE_RESULTS
#include "TestedFunctions.h"

char* serialize_results(struct TestedFunctions* sortingAlgos) {
    char* result;
    for (int i = 0; i < CALLBACK_COUNT; i++) {

        strcat(result, sprintf("===============================\n"));
        strcat(result, sprintf("Alg:\t%s\n", sortingAlgos[i].name));

        for (int j = 0; j < sortingAlgos[i].resultCount ;j++ ) {
            strcat(result, printf("Typ:\t%s\n", sortingAlgos[i].results[j].instance_type));
            strcat(result, printf("Len:\t%d\n", sortingAlgos[i].results[j].instance_size));
            strcat(result, printf("Sec:\t%f\n", sortingAlgos[i].results[j].time));
        }
    }
    return result;
}


#endif