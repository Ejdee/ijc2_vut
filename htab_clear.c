// htab_clear.c--

#include <stdlib.h>
#include "htab_struct.h"

void htab_clear(htab_t * t) {
    for(int i = 0; i < t->arr_size; i++) {
        htab_item_t *temp = t->ptr[i];
        htab_item_t *next_item = NULL;

        while(temp != NULL) {
            next_item = temp->next;
            htab_erase(t, temp->pair.key);
            temp = next_item;
        }
    }
    t->size = 0; // set number of records to 0
    
}