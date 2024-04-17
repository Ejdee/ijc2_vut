#include "htab.h"
#include "htab_struct.h"

float htab_load_factor(htab_t * t) {
    return (float)t->size / t->arr_size;
}