// htab_bucket_size.c --

#include "htab_struct.h"

size_t htab_bucket_count(const htab_t * t) {
    return t->arr_size;
}