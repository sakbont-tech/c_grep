#define _POSIX_C_SOURCE 200809L

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <ctype.h>

int main(int argc, char *argv[]){

    FILE *fp;
    char *line =  NULL;
    size_t capacity = 0;
    ssize_t characters_read;
    char *pattern;
    int iflag = 0;
    int c;
    int status = EXIT_SUCCESS;

    while((c = getopt(argc, argv, "i")) != -1){
        switch(c)
        {
            case 'i':
            iflag = 1;
            break;

            case '?':
            fprintf(stderr, "Unknown option character `\\x%x'.\n", optopt);
            return EXIT_FAILURE;
        }
    }

    if(argc - optind != 2){
        fprintf(stderr, "Usage: %s [-i] PATTERN FILE\n", argv[0]);
        return EXIT_FAILURE;
    }

    pattern = argv[optind];

    fp = fopen(argv[optind + 1], "r");

    if(fp == NULL){
        perror("Unable to open file");
        return EXIT_FAILURE;
    }

    while((characters_read = getline(&line, &capacity, fp)) != -1) {
        if (iflag == 1) {
            char *line_cursor = line;

            while (*line_cursor != '\0') {
                char *candidate_cursor = line_cursor;
                char *pattern_cursor = pattern;

                while (*candidate_cursor != '\0' &&
                    *pattern_cursor != '\0' &&
                    tolower((unsigned char)*candidate_cursor) ==
                    tolower((unsigned char)*pattern_cursor)) {
                    candidate_cursor++;
                    pattern_cursor++;
                }

                if (*pattern_cursor == '\0') {
                    printf("%s", line);
                    break;
                }

                line_cursor++;
            }
        } else {
            if (strstr(line, pattern) != NULL) {
                printf("%s", line);
            }
        }
    }

    if(ferror(fp)){
        perror("Error reading file");
        status = EXIT_FAILURE;
    }

    free(line);
    fclose(fp);

    return status;
}
