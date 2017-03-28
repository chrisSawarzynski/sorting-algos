#ifndef RESULT
#define RESULT
#include <time.h>

struct Result {
    char * instance_type;
    unsigned int instance_size;
    clock_t time;
};

#endif