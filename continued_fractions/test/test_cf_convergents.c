#include <stdio.h>
#include "../include/cf.h"

int main(void) {
    /*   print convergents of rational
    number using the following format:
    p_0/q_0, p_1/q_1  ... ...  p_n/q_n
    input format:  N for whole numbers
                   N/M for rational */

    int p = 0, q = 0;

    printf("Enter any positive rational number: ");
    scan_rn(&p, &q);

    printf("Convergents of %d/%d: ", p, q);
    cf_convergents(p, q);

    return 0;
}
