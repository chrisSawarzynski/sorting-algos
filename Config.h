#ifndef CONFIG
#define CONFIG

#include "TestInstances.h"

struct Config {
    int instanceSize;
    char *instanceFile;
    struct TestInstances instances;
};


//TODO: wywalić do pliku *.c ? Jak to sie robiło?
struct Config getConfig(int argc, char* argv[]) {

    struct Config config = {100};

    for (int i = 0; i < argc; i++) {

        if (strcmp(argv[i], "-n") == 0 && i+1 < argc) {
                config.instanceSize = atoi(argv[i + 1]);
        }

        if (strcmp(argv[i], "-i") == 0 && i+1 < argc) {
                config.instanceFile = argv[i + 1];
        }

    }

    if (config.instanceFile != NULL) {
        config.instances = getInstancesFromFile(config.instanceFile);
    } else {
        config.instances = generateInstances(config);
    }

    return config;
};

#endif