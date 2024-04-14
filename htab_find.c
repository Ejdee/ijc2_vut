// htab_find.c --

#include "htab.h"
#include "htab_struct.h"
#include "htab_item.h"

htab_pair_t * htab_find(const htab_t * t, htab_key_t key) {

    // calculate the position using hash function and modulo
    size_t position = htab_hash_function(key) % t->arr_size;

    htab_item_t *temp = t->ptr[position];
    while(temp != NULL) {
        if(strcmp(temp->pair.key, key) == 0) {
            return &temp->pair;
        } else {
            temp = temp->next;
        }
    }

    // if the key was not found, return NULL
    return NULL;
}