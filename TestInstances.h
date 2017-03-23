#ifndef INSTANCES
#define INSTANCES

#include "Config.h"


struct TestInstances {
    int* growing;
};


struct TestInstances getInstancesFromFile(char *fileName) {
    struct TestInstances instances;

    return instances;
}


struct TestInstances generateInstances(struct Config config) {
    struct TestInstances instances;

    return instances;
}

#endif