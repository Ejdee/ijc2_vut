// wordcount.c --

#include <stdio.h>
#include <stdlib.h>
#include "htab.h"
#include "io.h"

#define HASH_SIZE 1000
#define MAX_LENGTH_WORD 255


void print_pair(htab_pair_t *data) {
    printf("%s\t%d\n", data->key, data->value);
}

int main() {
    htab_t *table = htab_init(HASH_SIZE);
    if(table == NULL) {
        fprintf(stderr, "A word is longer than 254 characters, cutting.\n");
        return 1;
    }

    bool warning = false;
    char string[MAX_LENGTH_WORD];
    int length = 0;

    while((length = read_word(string, MAX_LENGTH_WORD, stdin)) != EOF) {
        if(length > MAX_LENGTH_WORD && !warning) {
            fprintf(stderr, "A word is longer than 254 characters, cutting.\n");
            warning = true;
        }
        //printf("\n-------------------------------\n");
        //printf("%s\n", string);
        //printf("-------------------------------\n\n");
        htab_pair_t *new_item = htab_lookup_add(table, string);
        (void)new_item;
        //printf("%s\n", new_item->key);
    }

    //print_table(table);

    htab_for_each(table, &print_pair);

    htab_free(table);

    return 0;
}
