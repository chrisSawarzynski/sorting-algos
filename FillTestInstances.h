#ifndef FILL_TEST_INSTANCES
#define FILL_TEST_INSTANCES
#include "TestInstances.h"

void fill_test_instances(struct TestInstances* testInstances, int* lengths) {
    for (int i = 0; i < INSTANCE_TYPES; i++) {

        for (int j = 0; j < INSTANCE_LENGTHS_COUNT; j++) {

            testInstances[i+j].type_name = "Some instance type name";
            testInstances[i+j].size = lengths[j];

            int elements[lengths[j]];

            for (int k = 0; k < lengths[j]; k++) {
                elements[k] = k;
            } 

            testInstances[i+j].elements = elements;
        }
    }
}


#endif