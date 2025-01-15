#include <stdio.h>
#include "../include/cf.h"

#define EXP_LIMIT 100

int main(int argc, char **argv) {
    /* find generalization of given expansion of rational number
    in  the  format  [a_0; a_1, a_2, ... a_n],   result  in  the
    following format: N for whole numbers, N/M for rational   */

    int cf_ctr = 0;
    int cf_exp[EXP_LIMIT] = {0};

    printf("Enter expansion of positive rational number: ");
    scan_cf(&cf_ctr, cf_exp);

    printf("Restored generalization: ");
    cf_generalization(cf_ctr, cf_exp);

    return 0;
}
