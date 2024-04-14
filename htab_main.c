#include <stdio.h>
#include "htab.h"
#include "htab_struct.h"
#include "htab_item.h"


int main() {
    htab_t *my_table = htab_init(20); 

    char *key = "adam";
    htab_pair_t *added = htab_lookup_add(my_table, key);
    printf("%s\n", added->key);

    for(int i = 0; i < 20; i++) {
        if(my_table->ptr[i] != NULL) {
            printf("%d: %s\n", i+1, my_table->ptr[i]->pair.key);
        } else {
            printf("%d: %p\n", i+1, (void*)my_table->ptr[i]);
        }
    }


    size_t size = htab_size(my_table);
    size_t count = htab_bucket_count(my_table);

    printf("size: %lu\n", size);
    printf("arr_size: %lu\n", count);
    return 0;
}