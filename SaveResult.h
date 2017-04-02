#ifndef SAVE_RESULT
#define SAVE_RESULT
#include <conio.h>
#include <conio.h>

void save_results(struct TestedFunctions* sortingAlgos) {
    FILE * output_file = fopen("result.txt", "w");

    if (output_file == NULL) {
        perror("Error");
    }

     for (int i = 0; i < CALLBACK_COUNT; i++) {

        fprintf(output_file,"%s\n", sortingAlgos[i].name);

        for (int j = 0; j < sortingAlgos[i].resultCount ;j++ ) {
            fprintf(output_file,"%s\t", sortingAlgos[i].results[j].instance_type);
            fprintf(output_file,"%d\t", sortingAlgos[i].results[j].instance_size);
            fprintf(output_file,"%f\n", sortingAlgos[i].results[j].time);
        }
    }
    
    fclose(output_file);
}

#endif