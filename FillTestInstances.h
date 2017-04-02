#ifndef FILL_TEST_INSTANCES
#define FILL_TEST_INSTANCES
#include "TestInstances.h"
#include "generator.h"
#include "copy_array.h"

void fill_using_generator(struct TestInstances* testInstances, int* lengths, int* testInstancesIndex, void (*generator)(struct TestInstances*, int)) {

        for (int j = 0; j < INSTANCE_LENGTHS_COUNT; j++) {

            generator(&testInstances[(*testInstancesIndex)++], lengths[j]);

        }

}


void fill_test_instances(struct TestInstances* testInstances, int* lengths) {
    int testInstancesIndex = 0;

    fill_using_generator(testInstances, lengths, &testInstancesIndex, Random);
    fill_using_generator(testInstances, lengths, &testInstancesIndex, AscSort);
    fill_using_generator(testInstances, lengths, &testInstancesIndex, DescSort);
    fill_using_generator(testInstances, lengths, &testInstancesIndex, fnVShaped);
    fill_using_generator(testInstances, lengths, &testInstancesIndex, fnAShaped);
    fill_using_generator(testInstances, lengths, &testInstancesIndex, Constant);

}



#endif