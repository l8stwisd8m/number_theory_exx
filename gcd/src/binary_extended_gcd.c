#include <stdint.h>
#include <iso646.h>
#include <assert.h>
#include "../include/gcd.h"

unsigned int binary_extended_gcd(unsigned int a, unsigned int b, int *x, int *y) {
    /*       calculate greatest common
    divisor  and  Bezout  coefficients
    using binary reduction approach */
    
    unsigned int gcd = 0, shift = 1;
    int v1 = 0, v2 = 0; unsigned int v3 = 0;
    
    assert(a or b);
    
    while (IS_EVEN(a) and IS_EVEN(b)){
        a = a >> 1;     // a /= 2
        b = b >> 1;     // b /= 2
        shift = shift << 1; // gcd *= 2
    }

    if (a < b) {
        *x = 0; *y = 1; gcd = b; // (x, y, gcd) = (0, 1, b)
        v1 = 1; v2 = 0; v3 = a;  // (v1, v2, v3) = (0, 1, a)
    }
    else {
        *x = 1; *y = 0; gcd = a; // (x, y, gcd) = (1, 0, a)
        v1 = 0; v2 = 1; v3 = b;  // (v1, v2, v3) = (0, 1, b)
    }
    
    if (ARE_EQUAL(a, b) or IS_NULL(a) or IS_NULL(b)) return gcd << shift;
    
    while (gcd != v3) {
        if (IS_ODD(gcd)) {
            if (gcd > v3) {
                // (x, y, gcd) -= (v1, v2, v3)
                *x -= v1; *y -= v2; gcd -= v3;
            }
            else {
                // (v1, v2, v3) -= (x, y, gcd)
                v1 -= *x; v2 -= *y; v3 -= gcd;
            }
        }
        else {
            if (IS_EVEN(*x) and IS_EVEN(*y)) {
                // (x, y, gcd) /= 2
                *x /= 2; *y /= 2; gcd /= 2;
            }
            else {
                // (x, y, gcd) = ((x+b)/2, (y-a)/2, gcd/2)
                *x = (*x + (int)b) / 2; *y = (*y - (int)a) / 2; gcd /= 2;
            }
        }
    }
    
    return gcd << shift;
}
