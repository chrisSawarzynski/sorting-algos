#ifndef COPY_ARRAY
#define COPY_ARRAY

void copy_array(int* array, int* buffer, int length) {
    
    for (int i =0; i < length; i++) {
        buffer[i] = array[i];
    }

}

#endif