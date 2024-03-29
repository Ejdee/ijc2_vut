#ifndef CBUF_H
#define CBUF_H

#define MAX_LINE_SIZE 2047

typedef struct tcbuf {
    char (*lines)[MAX_LINE_SIZE];
    int windex;
    int rindex;
    int count;
} cbuf;

/**
 * @brief function creates and allocates space for cbuf and return pointer to it
 * 
 * @param n number of lines, we want to track
 * @return cbuf* created cbuf structure
 */
cbuf* cbuf_create(int n);

/**
 * @brief function puts read line to position where write_index is pointing
 * 
 * @param cb cyclic buffer structure
 * @param line read line
 */
void cbuf_put(cbuf *cb, char *line);

char* cbuf_get(cbuf *cb);
void cbuf_free(cbuf *cb);

#endif // CBUF_H