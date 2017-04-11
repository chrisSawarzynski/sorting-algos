#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>



#define CALLBACK_COUNT 5
#define INSTANCE_LENGTHS_COUNT 15
#define INSTANCE_TYPES 6
#define INSTANCE_COUNT INSTANCE_TYPES * INSTANCE_LENGTHS_COUNT

#include "TestedFunctions.h"
#include "TestInstances.h"
#include "RegisterCallback.h"
#include "FillTestInstances.h"
#include "BenchmarkAlgos.h"
#include "SelectionSort.h"
#include "InsertionSort.h"
#include "HeapSort.h"
#include "QuickSort.h"
#include "qsi.h"
#include "SaveResult.h"


int main(int argc, char *argv[]) {

    srand(time(NULL));
    struct TestedFunctions sortingAlgos[CALLBACK_COUNT];
    struct TestInstances testInstances[INSTANCE_COUNT];

    int lengths[INSTANCE_LENGTHS_COUNT] = {100000, 200000, 300000, 400000, 500000, 600000, 700000, 800000, 900000, 1000000, 1100000, 1200000, 1300000, 1400000, 1500000};

    fill_test_instances(testInstances, lengths);


    register_callback(sortingAlgos, "selectionSort", SelectionSort);
    register_callback(sortingAlgos, "InsertionSort", InsertionSort);
    register_callback(sortingAlgos, "HeapSort", HeapSort);
    register_callback(sortingAlgos, "QuickSort", QuickSortMain);
    register_callback(sortingAlgos, "QuickSort Iteracyjny", qsi);


    benchmark_algos(sortingAlgos, testInstances);


    save_results(sortingAlgos);

    return 0;
}
