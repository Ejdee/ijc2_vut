// htab_for_each.c --

#include "htab_struct.h"

void htab_for_each(const htab_t *t, void (*f)(htab_pair_t *data)) {
    for(int i = 0; i < t->arr_size; i++) {
        htab_item_t *temp = t->ptr[i];
        while(temp != NULL) {
            // create new pair, so the function will not change the original hash table
            htab_pair_t temp_pair = temp->pair;
            f(&temp_pair);
            temp = temp->next;
        }
    }
}