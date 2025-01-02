#include "include/cf.h"
#include "src/cf_convergents.c"

int main(int argc, char **argv) {
    int p = 0;
    int q = 0;

    scan_rn(&p, &q);
    cf_convergents(p, q);

    return 0;
}
