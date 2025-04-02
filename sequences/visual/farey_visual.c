#include <math.h>
#include <stdio.h>
#include <assert.h>
#include "../include/tree.h"

#define R 1.0
#define G 0.72
#define B 0.72

double angle(vertice_t *vertice) {
    return acos(vertice->n / sqrt(pow(vertice->n, 2) + pow(vertice->d, 2)));
}

void print_vertice_data(FILE *path, double a, double r, double g, double b) {
    fprintf(path, "%f, %f, %f, %f\n", a, r, g, b);
    fprintf(path, "%f, %f, %f, %f\n", M_PI - a, r, g, b);
    fprintf(path, "%f, %f, %f, %f\n", M_PI/2 + a, r, g, b);
    fprintf(path, "%f, %f, %f, %f\n", -M_PI/2 - a, r, g, b);
    fprintf(path, "%f, %f, %f, %f\n", M_PI + a, r, g, b);
    fprintf(path, "%f, %f, %f, %f\n", -a, r, g, b);
    fprintf(path, "%f, %f, %f, %f\n", -M_PI/2 + a, r, g, b);
    fprintf(path, "%f, %f, %f, %f\n", M_PI/2 - a, r, g, b);
}

void foo(vertice_t *vertice, FILE *path, unsigned int n, unsigned int lim) {
    if (n >= lim) return;
    print_vertice_data(path, angle(vertice->left), R - 0.0625*n, G - 0.03125*n, B);
    print_vertice_data(path, angle(vertice->right), R - 0.0625*n, G - 0.03125*n, B);
    foo(vertice->left, path, n+1, lim);
    foo(vertice->right, path, n+1, lim);
}

int main(void) {
    /* description */ 
    
    FILE *path = fopen("assets/csv/stern_brocot_data.csv", "w");
    unsigned int n = 16; // order
    assert (n > 0);
    
    // Strern-Brocot tree
    vertice_t *left_ancestor = create_vertice(0, 1);
    vertice_t *right_ancestor = create_vertice(1, 0);
    vertice_t *vertice = create_vertice(1, 1);
    stern_brocot(vertice, 1, n, 
                 left_ancestor->n, left_ancestor->d, 
                 right_ancestor->n, right_ancestor->d);
    
    //unsigned int s = (unsigned int)pow(2, n) - 1;
    fprintf(path, "angle, r, g, b\n");
    
    print_vertice_data(path, angle(left_ancestor), R, G, B);
    print_vertice_data(path, angle(right_ancestor), R, G, B);
    print_vertice_data(path, M_PI + angle(left_ancestor), R, G, B);
    print_vertice_data(path, M_PI + angle(right_ancestor), R, G, B);
    
    print_vertice_data(path, angle(vertice), R, G, B);
    print_vertice_data(path, angle(vertice) + M_PI/2, R, G, B);
    print_vertice_data(path, angle(vertice) + M_PI, R, G, B);
    print_vertice_data(path, angle(vertice) - M_PI/2, R, G, B);

    foo(vertice, path, 1, n);
    
    fclose(path);
    return 0;
}
