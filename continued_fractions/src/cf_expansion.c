#include <stdio.h>

void cf_expansion (int p, int q) {

    /*   print expansion of continued fraction
    of  rational  number  using the  following
    format: [a_0; a_1, a_2 ... a_n]         */

    int r = p % q;
    printf("[%d", p / q);

    /* p/q is a whole number => expansion of
    p/q is represented by a single number */

    if (r != 0) putchar(';');
    while (r != 0) {
        p = q;
        q = r;
        r = p % q;
        printf(" %d", p / q);
        if (r != 0) putchar (',');
    }
    printf("]\n");

}
