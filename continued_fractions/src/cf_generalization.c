#include <stdio.h>
#include "../include/cf.h"

void cf_generalization (int ctr, int *exp) {
    /*   find generalization using expansion
    input format: [a_0; a_1, a_2 ... a_n] */

    int tmp = 0;
    int numerator = 1;
    int denominator = 0;

    if (ctr == 0) return;

    if (ctr == 1) {
        printf("%d\n", exp[0]);
        return;
    }

    denominator = exp[ctr - 1];
    for (int i = ctr - 2; i > 0; i--) {
        tmp = numerator;
        numerator = denominator;
        denominator = tmp + numerator * exp[i];
    }
    numerator += denominator * exp[0];
    printf("%d/%d\n", numerator, denominator);
}
