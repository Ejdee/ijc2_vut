// htab_clear.c--

#include <stdlib.h>
#include "htab_struct.h"

void htab_free(htab_t * t) {
    for(int i = 0; i < t->arr_size; i++) {
        free(t->ptr[i]);
    }
    free(t);
}