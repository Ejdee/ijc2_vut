#include <stdbool.h>

#ifndef CBUF_H
#define CBUF_H

#define MAX_LINE_SIZE 2047
#define MAX_FILE_NAME_LENGTH 256

/**
 * @brief cyclic buffer structure, that stores N elements of lines, read index, write index,
 * and size of buffer
 *
 */
typedef struct tcbuf {
    char (*lines)[MAX_LINE_SIZE];
    int windex;
    int rindex;
    int size;
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

/**
 * @brief function gets a line written in read_index position and returns it
 * 
 * @param cb cyclic buffer structure
 * @return char* line that is stored in read_index position
 */
char* cbuf_get(cbuf *cb);

/**
 * @brief function frees allocated cyclic buffer structure
 * 
 * @param cb cyclic buffer structure
 */
void cbuf_free(cbuf *cb);

/**
 * @brief function checks if buffer of cbuf structure is empty or not
 * 
 * @param cb cyclic buffer structure
 * @return true if write index is 0
 * @return false if write index is not 0
 */
bool cbuf_empty(cbuf *cb);

#endif // CBUF_H