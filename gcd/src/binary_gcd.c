#include <stdint.h>
#include <iso646.h>
#include <assert.h>
#include "../include/gcd.h"

unsigned int binary_gcd(unsigned int a, unsigned int b) {
    /* binary greatest common divisor algorithm */ 
    
    unsigned int gcd = 1; // result
    
    assert(a or b);
    if (a == 0) return b;
    if (b == 0) return a;
    
    while (IS_EVEN(a) and IS_EVEN(b)){
        a = a >> 1;     // a /= 2
        b = b >> 1;     // b /= 2
        gcd = gcd << 1; // gcd *= 2
    }
    
    while (a != 0) {
        while (IS_EVEN(a)) a = a >> 1; // a /= 2
        while (IS_EVEN(b)) b = b >> 1; // b /= 2
        if (a < b) b -= a;
        else a -= b;
    }
    
    return b * gcd;
}
