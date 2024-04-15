#include <stdio.h>
#include "htab.h"
#include "htab_struct.h"
#include "htab_item.h"


int main() {
    htab_t *my_table = htab_init(20); 

    char *key = "adam";
    char *key2 = "daam";
    htab_pair_t *added = htab_lookup_add(my_table, key);
    htab_pair_t *add = htab_lookup_add(my_table, key2);
    (void)added;
    (void)add;
    char *key3 = "jeffrey";
    char *key4 = "honza";
    htab_pair_t *jeffrey = htab_lookup_add(my_table, key3);
    htab_pair_t *honza = htab_lookup_add(my_table, key4);
    (void)jeffrey;
    (void)honza;
    char *key5 = "trenky";
    char *key6 = "ponozky";
    htab_pair_t *trenky = htab_lookup_add(my_table, key5);
    htab_pair_t *ponozky = htab_lookup_add(my_table, key6);
    (void)trenky;
    (void)ponozky;

    bool erased = htab_erase(my_table, key6);
    if(erased)
        printf("True\n");
    else
        printf("False\n");


    for(int i = 0; i < 20; i++) {
        printf("%d:", i+1);
        if(my_table->ptr[i] != NULL) {
            htab_item_t *temp = my_table->ptr[i];
            while(temp != NULL) {
                printf(" --> (%s, %d)", my_table->ptr[i]->pair.key, my_table->ptr[i]->pair.value);
                temp = temp->next;
            }
            printf(" --> %p\n", (void*)temp);
        } else {
            printf(" --> %p\t", (void*)my_table->ptr[i]);
            printf("\n");
        }
    }

    htab_statistics(my_table);

    size_t size = htab_size(my_table);
    size_t count = htab_bucket_count(my_table);

    printf("size: %lu\n", size);
    printf("arr_size: %lu\n", count);

    htab_clear(my_table);

    for(int i = 0; i < 20; i++) {
        printf("%d:", i+1);
        if(my_table->ptr[i] != NULL) {
            htab_item_t *temp = my_table->ptr[i];
            while(temp != NULL) {
                printf(" --> (%s, %d)\t", my_table->ptr[i]->pair.key, my_table->ptr[i]->pair.value);
                temp = temp->next;
            }
            printf("\n");
        } else {
            printf(" --> %p\t", (void*)my_table->ptr[i]);
            printf("\n");
        }
    }

    htab_statistics(my_table);

    htab_free(my_table);

    return 0;
}