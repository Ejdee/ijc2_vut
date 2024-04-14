// htab_init.c

#include <stdio.h>
#include <stdlib.h>

#include "htab.h"
#include "htab_struct.h"
#include "htab_item.h"


htab_t *htab_init(const size_t n) {    
    htab_t *table = malloc(sizeof(htab_t) + n * sizeof(htab_item_t*));
    if(table == NULL) {
        fprintf(stderr, "Allocation was not succesfull.\n");
        return NULL;
    }

    table->size = 0;
    table->arr_size = n;
    
    for(int i = 0; i < table->arr_size; i++) {
        table->ptr[i] = NULL;
    } 

    return table;
}