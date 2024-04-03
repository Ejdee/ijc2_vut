#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "tail.h"
#include "error.h"

bool cbuf_empty(cbuf *cb) {
    return cb->count == 0; // if count of lines in the buffer is zero, then the buffer is empty
}

cbuf* cbuf_create(int n) {
    cbuf *cb = malloc(sizeof(cbuf)); // allocate memory for structure

    if (cb != NULL) {
        cb->lines = malloc(n * sizeof(char[MAX_LINE_SIZE])); // allocate memory for each line depending on variable 'n'
        if(cb->lines == NULL) {
            free(cb);
            cb = NULL;
        } else {
            cb->count = 0;
            cb->rindex = 0;
            cb->windex = 0;
            cb->size = n;
        }
    } else {
        error_exit("Failed to allocate cbuf structure.");
    }

    return cb;
}

void cbuf_put(cbuf *cb, char *line) {

    // copy the line in the buffer at the current write index. to ensure that the line does not exceed the maximum length of buffer size,
    // we copy at most MAX_LINE_SIZE - 1 characters, and we add null terminator character at the end.
    strncpy(cb->lines[cb->windex], line, MAX_LINE_SIZE-1);
    cb->lines[cb->windex][MAX_LINE_SIZE-1] = '\0';

    // if the buffer is not empty and write index is equal to read index, we want to increment read index too
    if(!cbuf_empty(cb) && cb->windex == cb->rindex)
        cb->rindex = (cb->rindex + 1) % cb->size;

    cb->windex = (cb->windex + 1) % cb->size; // increment write index
    cb->count ++; // increment number of lines in the buffer
}

char* cbuf_get(cbuf *cb) {
    if(cbuf_empty(cb))
        error_exit("Buffer is empty.");

    char *to_return = cb->lines[cb->rindex]; // store line at the read index in variable
    cb->rindex = (cb->rindex + 1) % cb->size; // increment read index
    cb->count --; // decrement number of lines in the buffer

    return to_return;
}

void cbuf_free(cbuf* cb) {
    free(cb->lines);
    free(cb);
}

int main(int argc, char *argv[]) {
    int size = 10; // default number of lines we want to print out
    FILE *fp = stdin; // default stream

    if(argc > 4)
        error_exit("Wrong arguments.");

    for(int i = 1; i < argc; i++) {
        if(strcmp("-n", argv[i]) == 0) {
            if(i+1 <= argc) { // check if i+1 argc exists
                size = atoi(argv[i+1]);

                if(size <= 0) // if -n argument is less or equal to 0
                    error_exit("Option -n requires a number above 0.");

                i++;
            } else {
                error_exit("Option -n requires argument.");
            }
        } else {
            if(fp != stdin) { // if we are supposed to change file name, but it is not stdin.. it was already changed and we throw error
                error_exit("You cannot type in two files.");
            }
            fp = fopen(argv[i], "r");
            if(fp == NULL) {
                error_exit("Failed to open file %s.", argv[i]);
            }
        }
    }

    cbuf* cb = cbuf_create(size); // create the buffer

    // load the lines from file or stdin to buffer
    char line[MAX_LINE_SIZE];
    while(fgets(line, MAX_LINE_SIZE, fp) != NULL) {
        cbuf_put(cb, line);
    }

    // if 'size' is less than the number of lines in the buffer, print 'size' lines. otherwise print the maximum number of lines.
    int cb_lines_count = size < cb->count ? size : cb->count;

    // print out the lines
    for(int i = 0; i < cb_lines_count; i++) {
        printf("%s", cbuf_get(cb));
    }

    // free the structure
    cbuf_free(cb);

    // if the file is opened, close it
    if(fp != stdin)
        fclose(fp);

    return 0;
}
