// htab_item.h -- Define hash table item structure

#ifndef HTAB_ITEM_H
#define HTAB_ITEM_H

#include "htab.h"

typedef struct htab_item {
    htab_pair_t pair;
    struct htab_item *next;
} htab_item_t;

#endif // HTAB_ITEM_H
