#include <stdio.h>
#include <gmp.h>

int main(void) {
    /* calculate the value of "golden ratio" 
    with  an  accuracy  up  to  n  digits */

    // amount of digits 
    unsigned int n;
    printf("Enter amount of digits: ");
    scanf("%u", &n);
    if (n == 0) return 0;

    // GMP variables
    mpz_t tmp, numerator, denominator;
    mpz_init(tmp);
    mpz_init(numerator);
    mpz_init(denominator);

    // first convergent
    mpz_set_ui(numerator, 1);
    mpz_set_ui(denominator, 1);

    // calculate the convergent to achieve the required accuracy
    while (mpz_sizeinbase(denominator, 10) < n) {
        mpz_set(tmp, denominator); // tmp = denominator
        mpz_set(denominator, numerator); // denominator = numerator
        mpz_add(numerator, numerator, tmp); // numerator += tmp
    }

    // first digit
    putchar('1');
    n -= 1;
    if (n) {
        putchar('.');
        mpz_sub(numerator, numerator, denominator); // numerator -= denominator
    }
    // the following digits
    while (n) {
        mpz_mul_ui(numerator, numerator, 10); // numerator *= 10
        mpz_div(tmp, numerator, denominator); // tmp = numerator / denominator
        gmp_printf("%Zd", tmp); // print the current digit
        mpz_fdiv_r(numerator, numerator, denominator); // numerator %= denominator
        n -= 1;
    }
    putchar('\n');

    mpz_clear(tmp);
    mpz_clear(numerator);
    mpz_clear(denominator);

    return 0;
}
