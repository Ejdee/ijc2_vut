#include "htab.h"

struct htab_item {
    struct htab_item *next;
    htab_pair_t pair;
};

struct htab {
    int size;
    int arr_size;
    htab_item_t items[]; 
};