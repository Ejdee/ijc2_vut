#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "tail.h"
#include "error.h"

bool cbuf_empty(cbuf *cb) {
    return cb->count == 0;
}

cbuf* cbuf_create(int n) {
    cbuf *cb = malloc(sizeof(cbuf));

    if (cb != NULL) {
        cb->lines = malloc(n * sizeof(char[MAX_LINE_SIZE]));
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
    strncpy(cb->lines[cb->windex], line, MAX_LINE_SIZE-1);
    cb->lines[cb->windex][MAX_LINE_SIZE-1] = '\0';

    if(!cbuf_empty(cb) && cb->windex == cb->rindex)
        cb->rindex = (cb->rindex + 1) % cb->size;

    cb->windex = (cb->windex + 1) % cb->size;
    cb->count ++;
}

char* cbuf_get(cbuf *cb) {
    if(cbuf_empty(cb))
        error_exit("Buffer is empty.");

    char *to_return = cb->lines[cb->rindex];
    cb->rindex = (cb->rindex + 1) % cb->size;
    cb->count --;

    return to_return;
}

void cbuf_free(cbuf* cb) {
    free(cb->lines);
    free(cb);
}

int main(int argc, char *argv[]) {
    int size = 10;
    FILE *fp = stdin;

    if(argc > 4)
        error_exit("Wrong arguments.");

    for(int i = 1; i < argc; i++) {
        if(strcmp("-n", argv[i]) == 0) {
            if(i+1 <= argc) {
                size = atoi(argv[i+1]);
                i++;
            } else {
                error_exit("Wrong arguments.");
            }
        } else {
            if(fp != stdin) {
                error_exit("Wrong arguments.");
            }
            fp = fopen(argv[i], "r");
            if(fp == NULL) {
                error_exit("Failed to open file %s.", argv[i]);
            }
        }
    }

    cbuf* cb = cbuf_create(size);

    char line[MAX_LINE_SIZE];
    while(fgets(line, MAX_LINE_SIZE, fp) != NULL) {
        cbuf_put(cb, line);
    }

    for(int i = 0; i < size; i++) {
        printf("%s", cbuf_get(cb));
    }

    cbuf_free(cb);

    if(fp != stdin)
        fclose(fp);

    return 0;
}