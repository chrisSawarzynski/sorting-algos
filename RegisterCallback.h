#ifndef REG_CALLBACK
#define REG_CALLBACK


void register_callback( struct TestedFunctions* sortingAlgos, char * name, int* (*callback)(int*, int)) {
        unsigned static int index = 0;
        sortingAlgos[index].name = name;
        sortingAlgos[index].callback = callback;
        sortingAlgos[index].resultCount = 0;
        index++;
}


#endif