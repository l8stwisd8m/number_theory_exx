#include <stdio.h>
#include <iso646.h>
#include "../include/gcd.h"

int main(void) {
    /*    calculate greatest common
    divisor and Bezout coefficients
    using classic algorithm      */
    
    unsigned int a = 0, b = 0, result = 0;
    int x = 0, y = 0;
    
    printf("Enter arguments \na:\t");
    scanf("%u", &a);
    printf("b:\t");
    scanf("%u", &b);
    if (IS_NULL(a) and (IS_NULL(b))) {
        printf("Invalid input\n");
        return 0;
    }
    
    // greatest common divisor
    result = gcd(a, b);
    printf("GCD(%u, %u) = %u\n", a, b, result);
    
    // Bezout identity
    result = extended_gcd(a, b, &x, &y);
    printf("Bezout coefficients\nx:\t%d\ny:\t%d\n", x, y);
    printf("Bezout identity: %u*(%d) + %u*(%d) = ", a, x, b, y);
    printf("%u\n", (unsigned int)((long)a * x + (long)b * y));
    
    return 0;
}
