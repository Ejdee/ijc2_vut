// htab_erase.c --

#include <stdlib.h>
#include "htab_struct.h"

bool htab_erase(htab_t * t, htab_key_t key) {
    size_t position = htab_hash_function(key) % t->arr_size;
    
    htab_item_t *temp = t->ptr[position];
    htab_item_t *prev = NULL;
    while(temp != NULL) {
        if(strcmp(temp->pair.key, key) == 0) {
            prev->next = temp->next;
            temp->next = NULL;
            free(temp->pair);
            free(temp);
            return true;
        } else {
            prev = temp;
            temp = temp->next;
        }
    }
}