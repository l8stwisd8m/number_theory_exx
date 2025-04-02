#include <stdint.h>
#include <iso646.h>
#include <assert.h>
#include "../include/gcd.h"

unsigned int extended_gcd(unsigned int a, unsigned int b, int *x, int *y) {
    /*    calculate greatest common
    divisor and Bezout coefficients
    using classic algorithm      */ 
    
    unsigned int gcd = 0, q = 0;
    int v1 = 0, v2 = 0; unsigned int v3 = 0;
    int t1 = 0, t2 = 0; unsigned int t3 = 0;
    
    assert(a or b);
    
    if (a < b) {
        *x = 0; *y = 1; gcd = b; // (x, y, gcd) = (0, 1, b)
        v1 = 1; v2 = 0; v3 = a;  // (v1, v2, v3) = (0, 1, a)
    }
    else {
        *x = 1; *y = 0; gcd = a; // (x, y, gcd) = (1, 0, a)
        v1 = 0; v2 = 1; v3 = b;  // (v1, v2, v3) = (0, 1, b)
    }
    
    if (ARE_EQUAL(a, b) or IS_NULL(a) or IS_NULL(b)) return gcd;
    
    t3 = gcd % v3;
    while (t3) {
        q = gcd / v3; // (t1, t2, t3) = (x, y, gcd) - q * (v1, v2, v3)
        t1 = *x - q * v1; t2 = *y - q * v2; t3 = gcd - q * v3;
        *x = v1; *y = v2; gcd = v3; // (x, y, gcd) = (v1, v2, v3)
        v1 = t1; v2 = t2; v3 = t3;  // (v1, v2, v3) = (t1, t2, t3)
    }
    
    return gcd;
}
