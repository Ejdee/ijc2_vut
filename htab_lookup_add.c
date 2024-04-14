// htab_lookup_add.c

#include <stdio.h>
#include <stdlib.h>
#include "htab_struct.h"

htab_pair_t * htab_lookup_add(htab_t * t, htab_key_t key) {
    
    // calculate the position using hash function and modulo
    size_t position = htab_hash_function(key) % t->arr_size;

    htab_item_t *temp = t->ptr[position];
    htab_item_t *previous = NULL;
    while(temp != NULL) {
        if(strcmp(temp->pair.key, key) == 0) {
            temp->pair.value ++;
            return &temp->pair;
        } else {
            previous = temp; // store the current item
            temp = temp->next; // go to next item in table
        }
    }

    htab_item_t *new_item = malloc(sizeof(htab_item_t));
    if(new_item == NULL) {
        fprintf(stderr, "Allocation of new item was not succesfull.\n");
        return NULL;
    }

    new_item->pair.key = key;
    new_item->pair.value = 1; // set the value to 1
    new_item->next = NULL; // set the next pointer to NULL


    if(previous == NULL) {
        // if it is first item on the position, make it a head in the list
        t->ptr[position] = new_item;
    } else {
        previous->next = new_item; // set the previous item to point to new item
    }
    return &new_item->pair;
}