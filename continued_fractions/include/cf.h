#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <iso646.h>

#define LIMIT 11

void scan_rn (int *p, int *q); // scan whole or rational number
void scan_cf (int *ctr, int *exp); // scan representation of continued fraction
void cf_expansion (int p, int q); // print expansion of continued fraction
void cf_convergents (int p, int q); // print continued fraction convergents
void cf_generalization (int ctr, int *exp); // find generalization using expansion

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
    char number[LIMIT] = {0};

    // input parsing
    do {
        scanf("%c", &symbol);
        if (isdigit(symbol) and i < LIMIT - 1) {
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

}
