#ifndef FILL_TEST_INSTANCES
#define FILL_TEST_INSTANCES
#include "TestInstances.h"
#include "generator.h"
#include "copy_array.h"

void fill_using_generator(struct TestInstances* testInstances, int* lengths, void (*generator)(struct TestInstances*, int)) {
        static int testInstancesIndex = 0;
        for (int j = 0; j < INSTANCE_LENGTHS_COUNT; j++) {
            generator(&testInstances[testInstancesIndex++], lengths[j]);
        }

}


void fill_test_instances(struct TestInstances* testInstances, int* lengths) {

    fill_using_generator(testInstances, lengths, Random);
    fill_using_generator(testInstances, lengths, AscSort);
    fill_using_generator(testInstances, lengths, DescSort);
    fill_using_generator(testInstances, lengths, fnVShaped);
    fill_using_generator(testInstances, lengths, fnAShaped);
    fill_using_generator(testInstances, lengths, Constant);

}



#endif