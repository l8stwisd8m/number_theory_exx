#include <stdint.h>
#include <iso646.h>
#include <assert.h>
#include "../include/gcd.h"

static void swap(unsigned int *a, unsigned int *b) {
    unsigned int tmp = *a;
    *a = *b;
    *b = tmp;
}

unsigned int gcd(unsigned int a, unsigned int b) {
    /* classic greatest common divisor algorithm */ 
    
    unsigned int r = 0; // residue
    
    assert(a or b);
    if (a < b) swap(&a, &b);
    if (!b) return a;
    
    while ((r = a % b)) {
        a = b;
        b = r;
    }
    
    return b;
}
