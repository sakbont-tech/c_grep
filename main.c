#define _POSIX_C_SOURCE 200809L

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){

    FILE *fp;
    char *line =  NULL;
    size_t capacity = 0;
    ssize_t characters_read;

    if(argc != 2){
        fprintf(stderr, "Usage: %s <filepath>\n", argv[0]);
        return EXIT_FAILURE;
    }

    fp = fopen(argv[1], "r");

    if(fp == NULL){
        perror("Unable to open file");
        return EXIT_FAILURE;
    }

    while((characters_read = getline(&line, &capacity, fp)) != -1) {
        printf("%s", line);
    }

    if(ferror(fp)){
        perror("Error reading file");
    }

    free(line);
    fclose(fp);
    return EXIT_SUCCESS;
}