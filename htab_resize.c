/* htab_resize.c
 * Solution IJC-DU2, task b)
 * Author: Adam Běhoun, FIT
 * Date: 17.4.2024
 * login: xbehoua00
 * Compiled: gcc (GCC) 10.5.0
*/

#include "htab.h"
#include "htab_struct.h"

/**
 * @brief Resize the hash table with new size of 2*current_size.
 * Each record is rehashed into the new hash table. Return the pointer
 * to the new hash table
 * 
 * @param t hash table
 * @return htab_t* pointer to the new allocated hash table
 * @return NULL if memory allocation failed
 */
htab_t * resize_hash_table(htab_t * t) {
    // calculate the new size to allocate
    int new_size = t->arr_size * 2;

    //while(!htab_prime(new_size)) {
    //    new_size++;
    //}

    // allocate the new hash table
    htab_t * new_table = htab_init(new_size);
    if(new_table == NULL) {
        return NULL;
    }

    // traverse all the records and rehash them
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

    // the number of records stay the same 
    new_table->size = t->size;

    // free the old hash table
    htab_free(t);
    return new_table;
}