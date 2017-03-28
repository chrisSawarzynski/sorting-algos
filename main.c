#include <stdio.h>
#include <string.h>
#include <stdlib.h>


#define CALLBACK_COUNT 1
#define INSTANCE_LENGTHS_COUNT 1
#define INSTANCE_TYPES 1
#define INSTANCE_COUNT INSTANCE_TYPES * INSTANCE_LENGTHS_COUNT

#include "TestedFunctions.h"
#include "TestInstances.h"
#include "RegisterCallback.h"
#include "FillTestInstances.h"
#include "SerializeResults.h"
#include "BenchmarkAlgos.h"
#include "sorting_algo.h"


int main(int argc, char *argv[]) {

    struct TestedFunctions sortingAlgos[CALLBACK_COUNT];
    struct TestInstances testInstances[INSTANCE_COUNT];

    int lengths[INSTANCE_LENGTHS_COUNT] = {200};

    fill_test_instances(testInstances, lengths);


    register_callback(sortingAlgos, 0, "Testowy algorytm niesortujący", sorting_algo);


    benchmark_algos(sortingAlgos, testInstances);

    char* serializedResult = serialize_results(sortingAlgos);

    printf("%s", serializedResult);

    return 0;
}
