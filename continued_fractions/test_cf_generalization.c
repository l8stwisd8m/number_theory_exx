#include "include/cf.h"
#include "src/cf_generalization.c"

#define EXP_LIMIT 100

int main(int argc, char **argv) {
    int cf_ctr = 0;
    int cf_exp[EXP_LIMIT] = {0};

    scan_cf(&cf_ctr, cf_exp);
    cf_generalization(cf_ctr, cf_exp);

    return 0;
}
