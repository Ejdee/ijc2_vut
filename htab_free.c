// htab_clear.c--

#include <stdlib.h>
#include "htab_struct.h"

void htab_free(htab_t * t) {
    htab_clear(t);
    free(t);
}