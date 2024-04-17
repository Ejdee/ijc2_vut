#include "io.h"

int read_word(char *s, int max, FILE *f) {
    int c = getc(f);

    while(isspace(c) && c != EOF) {
        c = getc(f); // skip the isspace characters
    }

    int position = 0;
    while(!isspace(c) && c != EOF && position < max) {
        s[position] = c;
        position++;
        c = getc(f);
    } 

    s[position] = '\0';

    while(!isspace(c) && c != EOF) {
        c = getc(f); // skip the remaining characters
        position ++; // increment the position so we can detect that we cut the word
    }

    if(c == EOF) {
        return -1;
    }

    return position;
}