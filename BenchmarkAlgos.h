#ifndef BENCHMARK_ALGOS
#define BENCHMARK_ALGOS
#include <time.h>
#include "TestedFunctions.h"
#include "TestInstances.h"
#include "copy_array.h"


double callback_execution_time(struct TestedFunctions sortingAlgo, struct TestInstances testInstance){
        clock_t start = 0;
        clock_t stop = 0;
        int testTmp[testInstance.size];

        copy_array(testInstance.elements, testTmp, testInstance.size);

        start = clock();
        sortingAlgo.callback(testTmp, testInstance.size);
        stop = clock();

        return difftime(stop,start)/CLOCKS_PER_SEC;
};    

void benchmark_algos( struct TestedFunctions* sortingAlgos, struct TestInstances* testInstances) {

    for (int i = 0; i < CALLBACK_COUNT; i++) {
        for (int j = 0; j < INSTANCE_COUNT; j++) {

            sortingAlgos[i].resultCount += 1;
            sortingAlgos[i].results[j].instance_type = testInstances[j].type_name;
            sortingAlgos[i].results[j].instance_size = testInstances[j].size;
            sortingAlgos[i].results[j].time = callback_execution_time(sortingAlgos[i], testInstances[j]);
        }
    }

}


  


#endif