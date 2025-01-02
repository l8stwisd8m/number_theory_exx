#include "include/cf.h"
#include "src/cf_expansion.c"

int main(int argc, char **argv) {
    int p = 0;
    int q = 0;

    scan_rn(&p, &q);
    cf_expansion(p, q);

    return 0;
}
