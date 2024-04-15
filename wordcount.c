// wordcount.c --

#include <stdio.h>
#include <stdlib.h>
#include "htab.h"
#include "io.h"
#include "htab_struct.h"
#include "htab_item.h"

#define HASH_SIZE 20
#define MAX_LENGTH_WORD 255

void print_table(htab_t *table) {
    for(int i = 0; i < table->arr_size; i++) {
        printf("%d:", i+1);
        if(table->ptr[i] != NULL) {
            htab_item_t *temp = table->ptr[i];
            while(temp != NULL) {
                printf(" --> (%s, %d)", temp->pair.key, temp->pair.value);
                temp = temp->next;
            }
            printf(" --> %p\n", (void*)temp);
        } else {
            printf(" --> %p\t", (void*)table->ptr[i]);
            printf("\n");
        }
    }
}

void print_pair(htab_pair_t *data) {
    printf("%s\t%d\n", data->key, data->value);
}

int main() {
    htab_t *table = htab_init(HASH_SIZE);

    bool warning = false;
    char string[MAX_LENGTH_WORD];
    int length = 0;

    while((length = read_word(string, MAX_LENGTH_WORD, stdin)) != EOF) {
        if(length > MAX_LENGTH_WORD && !warning) {
            fprintf(stderr, "A word is longer than 254 characters, cutting.\n");
            warning = true;
        }
        printf("\n-------------------------------\n");
        printf("%s\n", string);
        printf("-------------------------------\n\n");
        htab_pair_t *new_item = htab_lookup_add(table, string);
        printf("%s\n", new_item->key);
    }

    print_table(table);

    htab_for_each(table, &print_pair);

    htab_free(table);

    return 0;
}
