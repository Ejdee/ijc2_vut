//htab_statistics --

#include <stdio.h>
#include "htab_struct.h"

void htab_statistics(const htab_t * t) {
    int min = 0;
    int max = 0;

    for(int i = 0; i < t->arr_size; i++) {
        htab_item_t *temp = t->ptr[i];
        int length = 0;
        while(temp != NULL) {
            length ++;
            temp = temp->next;
        }
        max = max > length ? max : length;

        if(i == 0) {
            min = length;
        } else {
            min = min > length ? length : min;
        }
    }


    // calculate average number of records as float number
    // we have size and arr_size as integers, so we need to convert int to float
    float avg = (float)t->size/(float)t->arr_size;
    fprintf(stderr, "min: %d\n", min);
    fprintf(stderr, "max: %d\n", max);
    fprintf(stderr, "avg: %.2f\n", avg);
}