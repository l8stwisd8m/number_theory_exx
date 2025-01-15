#include <stdio.h>
#include <stdlib.h>
#include <iso646.h>
#include "../include/cf.h"

void cf_convergents (int p, int q) {
    /*   print convergents of rational
    number using the following format:
    p_0/q_0, p_1/q_1 ... p_n/q_n    */

    p = abs(p); q = abs(q); // correct input

    // exceptions (basic cases)
    if (p == 0 or p == 1) {
        printf("%d/1\n", p);
        return;
    }

    int quotient = 0;
    int x = 0, y = 0, h = 0;    // vector (x,  y,  h)
    int v1 = 0, v2 = 0, v3 = 0; // vector (v1, v2, v3)
    int t1 = 0, t2 = 0, t3 = 0; // vector (t1, t2, t3)

    if (p < q) {
        x = 1; y = 0; h = p;    // (x,  y,  h)  = (1, 0, p)
        v1 = 0; v2 = 1; v3 = q; // (v1, v2, v3) = (0, 1, q)
    }
    else {
        x = 0; y = 1; h = q;    // (x,  y,  h)  = (0, 1, q)
        v1 = 1; v2 = 0; v3 = p; // (v1, v2, v3) = (1, 0, p)
    }

    quotient = h / v3;
    t3 = h - quotient*v3;

    while (t3 != 0) {
        quotient = h / v3;
        // (t1, t2, t3) = quotient*(v1, v2, v3)
        t1 = x - quotient*v1; t2 = y - quotient*v2; t3 = h - quotient*v3;
        // (x,  y,  h)  = (v1, v2, v3)
        x = v1; y = v2; h = v3;
        // (v1, v2, v3) = (t1, t2, t3)
        v1 = t1; v2 = t2; v3 = t3;
        // current convergent
        if (t1) printf("%d/%d", abs(t2), abs(t1));
        if (t1 and t3) printf(", ");
    }
    putchar('\n');
}
