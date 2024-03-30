#include <stdio.h>
#include <string.h>
#include "tail.h"
#include "error.h"
#include <stdbool.h>

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
    strncpy(cb->lines[cb->windex%cb->size], line, MAX_LINE_SIZE-1);
    cb->lines[cb->windex%cb->size][MAX_LINE_SIZE-1] = '\0';

    if(!cbuf_empty && (cb->windex%cb->size) == cb->rindex%cb->size)
        cb->rindex++;

    cb->windex++;
}

char* cbuf_get(cbuf *cb) {
    if(cb->rindex == cb->windex)
}

int main() {
    printf("Hello,world !\n");
    return 0;
}