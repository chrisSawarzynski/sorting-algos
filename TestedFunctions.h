#ifndef TESTED_FUNCTIONS
#define TESTED_FUNCTIONS
#include "Result.h"

struct TestedFunctions {
    char* name;
    int* (*callback)(int[], int);
    struct Result results[INSTANCE_COUNT];
    int resultCount;//NEEDED?
};

#endif