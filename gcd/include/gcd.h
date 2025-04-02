#ifndef _GCD_H_
#define _GCD_H_

#include <stdint.h>

#define IS_ODD(x) ((x) % 2 == 1)
#define IS_EVEN(x) ((x) % 2 == 0)
#define IS_NULL(x) ((x) == 0)
#define ARE_EQUAL(x, y) ((x) == (y))

unsigned int gcd(unsigned int a, unsigned int b); // classic greatest common divisor algorithm
unsigned int binary_gcd(unsigned int a, unsigned int b); // binary greatest common divisor algorithm
unsigned int extended_gcd(unsigned int a, unsigned int b, int *x, int *y); // calculate Bezout coefficients & GCD
unsigned int binary_extended_gcd(unsigned int a, unsigned int b, int *x, int *y); // calculate Bezout coefficients & GCD

#endif // _GCD_H_
