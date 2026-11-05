#define _POSIX_C_SOURCE 200809L

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]){

    FILE *fp;
    char *line =  NULL;
    size_t capacity = 0;
    ssize_t characters_read;
    char *pattern;

    if(argc != 3){
        fprintf(stderr, "Usage: %s pattern <filepath>\n", argv[0]);
        return EXIT_FAILURE;
    }

    pattern = argv[1];
    fp = fopen(argv[2], "r");

    if(fp == NULL){
        perror("Unable to open file");
        return EXIT_FAILURE;
    }

    while((characters_read = getline(&line, &capacity, fp)) != -1) {
        if(strstr(line, pattern) != NULL){
            printf("%s", line);
        }
    }

    if(ferror(fp)){
        perror("Error reading file");
        return EXIT_FAILURE;
    }

    free(line);
    fclose(fp);

    return EXIT_SUCCESS;
}