#include "htab.h"
#include "htab_struct.h"

htab_t * resize_hash_table(htab_t * t) {
    int new_size = t->arr_size * 2;

    htab_t * new_table = htab_init(new_size);
    if(new_table == NULL) {
        return NULL;
    }

    for(int i = 0; i < t->arr_size; i++) {
        htab_item_t* temp = t->ptr[i];
        while(temp != NULL) {
            htab_pair_t * new_item = htab_lookup_add(new_table, temp->pair.key);
            if(new_item != NULL) {
                new_item->value = temp->pair.value;
            }
            temp = temp->next;
        }
    }

    new_table->size = t->size;

    htab_free(t);
    return new_table;
}