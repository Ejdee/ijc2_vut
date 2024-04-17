/* htab_load_factor.c
 * Solution IJC-DU2, task b)
 * Author: Adam Běhoun, FIT
 * Date: 17.4.2024
 * login: xbehoua00
 * Compiled: gcc (GCC) 10.5.0
*/


#include "htab.h"
#include "htab_struct.h"

/**
 * @brief calculates the load factor of hash table. 
 * The load factor calculates how full the hash table is. It is number
 * of records in the hash table divided by number of buckets.
 * 
 * @param t hash table
 * @return float the load factor of the hash table
 */
float htab_load_factor(htab_t * t) {
    return (float)t->size / t->arr_size;
}