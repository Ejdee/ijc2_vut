/* wordcount.c
 * Solution IJC-DU2, task b)
 * Author: Adam Běhoun, FIT
 * Date: 17.4.2024
 * login: xbehoua00
 * Compiled: gcc (GCC) 10.5.0
*/


#include <stdio.h>
#include <stdlib.h>
#include "htab.h"
#include "io.h"

// Since we do not know actual size of input data, I decided to implement
// dynamic resizing of hash table. 
// According to "Data Structures and Algorithm Analysis in C++" by Mark Allen Weis, for separate chaining hashing,
// the load factor should be close to 1 for the best performance.
// After some tests, the load factor of 0.9 worked best for inputs of variable sizes.

// Since we have a load factor of 0.9, which means that hash table will resize when it reaches
// 90% of its capacity, i chose initial size of 100. It wont take too much memory for small inputs
// and save a couple of resizing for larger inputs.
#define HASH_SIZE 24533

// maximum length of read word
#define MAX_LENGTH_WORD 256


/**
 * @brief prints out pair of hash table in format "[key]    [value]"
 * 
 * @param data pair 
 */
void print_pair(htab_pair_t *data) {
    printf("%s\t%d\n", data->key, data->value);
}

int main() {
    htab_t *table = htab_init(HASH_SIZE);

    bool warning = false;
    char string[MAX_LENGTH_WORD];
    int length = 0;

    while((length = read_word(string, MAX_LENGTH_WORD, stdin)) != EOF) {

        // if a word is longer that MAX_LENGTH_WORD and a warning has not beed printed out yet,
        // we print it out and set flag so we dont print it out anymore.
        if(length > MAX_LENGTH_WORD-1 && !warning) {
            fprintf(stderr, "A word is longer than 255 characters, cutting.\n");
            warning = true;
        }

        // add or increment value of record in the hash table
        htab_pair_t *new_item = htab_lookup_add(table, string);
        (void)new_item;
        if(new_item == NULL) {
            fprintf(stderr, "Error: new_item allocation.\n");
            htab_free(table);
            return 1;
        }
    }

    // print out each pair
    htab_for_each(table, &print_pair);

    // if the program was compiled with -DSTATISTICS, we print out statistics
    #ifdef STATISTICS
        htab_statistics(table);
    #endif

    // free hash table
    htab_free(table);
    table=NULL;

    return 0;
} //main
