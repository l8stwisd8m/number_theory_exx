#include "include/cf.h"
#include "src/cf_expansion.c"

int main(int argc, char **argv) {

    /* print expansion of continued fraction of
    rational number using the following format:
    [a_0; a_1, a_2 ... a_n]       input format:
    N for whole numbers, N/M for rational    */


    int p = 0;
    int q = 0;

    printf("Enter any positive rational number: ");
    scan_rn(&p, &q);

    printf("Expansion of %d/%d: ", p, q);
    cf_expansion(p, q);

    return 0;

}
