#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>



#define CALLBACK_COUNT 3
#define INSTANCE_LENGTHS_COUNT 15
#define INSTANCE_TYPES 5
#define INSTANCE_COUNT INSTANCE_TYPES * INSTANCE_LENGTHS_COUNT

#include "TestedFunctions.h"
#include "TestInstances.h"
#include "RegisterCallback.h"
#include "FillTestInstances.h"
#include "SerializeResults.h"
#include "BenchmarkAlgos.h"
#include "SelectionSort.h"
#include "InsertionSort.h"
#include "HeapSort.h"


int main(int argc, char *argv[]) {

    srand(time(NULL));
    struct TestedFunctions sortingAlgos[CALLBACK_COUNT];
    struct TestInstances testInstances[INSTANCE_COUNT];

    int lengths[INSTANCE_LENGTHS_COUNT] = {10, 50, 100, 500, 1000,2000, 4000, 5000, 7000, 10000, 20000, 30000, 40000, 50000, 60000};

    fill_test_instances(testInstances, lengths);


    register_callback(sortingAlgos, 0, "selectionSort", SelectionSort);
    register_callback(sortingAlgos, 1, "InsertionSort", InsertionSort);
    register_callback(sortingAlgos, 2, "HeapSort", HeapSort);


    benchmark_algos(sortingAlgos, testInstances);

    char* serializedResult = serialize_results(sortingAlgos);

    printf("%s", serializedResult);

    return 0;
}
