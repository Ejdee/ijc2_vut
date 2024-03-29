#include <stdio.h>
#include <string.h>
#include "tail.h"
#include "error.h"

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
        }
    } else {
        error_exit("Failed to allocate cbuf structure.");
    }

    return cb;
}

void cbuf_put(cbuf *cb, char *line) {
    strncpy(cb->lines[cb->windex%10], line, MAX_LINE_SIZE);
    cb->windex++;
}

int main() {
    printf("Hello,world !\n");
    return 0;
}