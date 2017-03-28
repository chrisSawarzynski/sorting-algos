#ifndef REG_CALLBACK
#define REG_CALLBACK


void register_callback( struct TestedFunctions* sortingAlgos, unsigned int index, char * name, void (*callback)(int, int*)) {
        sortingAlgos[index].name = name;
        sortingAlgos[index].callback = callback;
        sortingAlgos[index].resultCount = 0;
}


#endif