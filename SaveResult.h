#ifndef SAVE_RESULT
#define SAVE_RESULT

void SaveResult(char* result) {
    File* output_file;
    
    *output_file = fopen("result.txt", "w");
    
    fclose(output_file);
}

#endif