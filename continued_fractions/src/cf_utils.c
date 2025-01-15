#include <math.h>
#include <assert.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <iso646.h>
#include <limits.h>
#include "../include/cf.h"

void scan_rn (int *p, int *q) {
    /*  scan whole or rational number
    input format: N for whole numbers
                  N/M for rational */

    scanf("%d/%d", p, q);
    if (*q == 0) *q = 1; // correct input
}

void scan_cf (int *ctr, int *exp) {
    /* scan representation of continued fraction
    input format: [a_0; a_1, a_2 ... a_n]     */

    *ctr = -1;
    int i = 0;
    char symbol = 0;
    const int limit = log10(INT_MAX) + 1;
    char *number = (char *)calloc(limit, sizeof(char));
    assert(number);

    // input parsing
    do {
        scanf("%c", &symbol);
        if (isdigit(symbol) and i <= limit) {
            if (i == 0) *ctr += 1;
            number[i++] = symbol;
        }
        else {
            if (i) exp[*ctr] = atoi(number);
            for (int j = 0; j < i; number[j++] = 0);
            i = 0;
        }
    }
    while (symbol != '\n');
    *ctr += 1;

    free(number);
}
