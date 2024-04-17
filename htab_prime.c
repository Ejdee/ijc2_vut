#include "htab.h"

bool htab_prime(size_t n) {
    for(int i = 2; i*i < n; i++) {
        if(n % i == 0) {
            return false;
        }
    }
    return true;
}