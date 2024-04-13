// htab_item.h -- Define hash table item structure

#ifndef HTAB_ITEM_H
#define HTAB_ITEM_H

#include "htab.h"

typedef struct htab_item {
    struct htab_item *next;
    htab_pair_t pair;
} htab_item_t;

#endif // HTAB_ITEM_H