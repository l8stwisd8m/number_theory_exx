#include <stdio.h>
#include <stdlib.h>
#include "../include/tree.h"

vertice_t* create_vertice(unsigned int p, unsigned int q) {
    vertice_t *vertice = (vertice_t *)malloc(sizeof(vertice_t));
    vertice->n = p;
    vertice->d = q;
    vertice->left = NULL;
    vertice->right = NULL;
    return vertice;
}

void print_vertice(vertice_t *vertice) {
    printf("%u/%u, ", vertice->n, vertice->d);
}

void print_tree(vertice_t *vertice) {
    if (vertice == NULL) return;

    // left brunch
    print_tree(vertice->left);
    // print current vertice
    print_vertice(vertice);
    // right brunch
    print_tree(vertice->right);
}
