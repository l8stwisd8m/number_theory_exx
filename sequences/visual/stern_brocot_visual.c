#include <stdio.h>
#include <assert.h>
#include "../include/tree.h"

void print_vector(FILE *path, unsigned int tail_x, unsigned int tail_y,
                  unsigned int head_x, unsigned int head_y) {
    fprintf(path, "%u, %u, %u, %u\n", tail_x, tail_y, head_x, head_y);
}

void foo(FILE *path, vertice_t *vertice, vertice_t *la, vertice_t *ra) {
    if (vertice == NULL) return;

    // left brunch
    foo(path, vertice->left, la, vertice);
    // print current vertice
    print_vector(path, 0, 0, vertice->d, vertice->n);
    print_vector(path, la->d, la->n, vertice->d, vertice->n);
    print_vector(path, ra->d, ra->n, vertice->d, vertice->n);
    // right brunch
    foo(path, vertice->right, vertice, ra);
}

int main(void) {
    /* description */ 
    
    FILE *path = fopen("assets/csv/stern_brocot_vectors.csv", "w");
    unsigned int n = 5; // order
    assert (n > 0);
    
    // Strern-Brocot tree
    vertice_t *left_ancestor = create_vertice(0, 1);
    vertice_t *right_ancestor = create_vertice(1, 0);
    vertice_t *vertice = create_vertice(1, 1);
    stern_brocot(vertice, 1, n, 
                 left_ancestor->n, left_ancestor->d, 
                 right_ancestor->n, right_ancestor->d);
    
    fprintf(path, "tail_x, tail_y, head_x, head_y\n");
    print_vector(path, 0, 0, left_ancestor->d, left_ancestor->n);
    print_vector(path, 0, 0, right_ancestor->d, right_ancestor->n);
    foo(path, vertice, left_ancestor, right_ancestor);
    
    fclose(path);
    return 0;
}
