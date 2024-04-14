// htab_struct.h -- opaque data type for hash table

#ifndef HTAB_STRUCT_H
#define HTAB_STRUCT_H

#include "htab.h"
#include "htab_item.h"

struct htab {
    int size;
    int arr_size;
    htab_item_t *ptr[];
};

#endif // htab_struct.h