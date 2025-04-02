#include "../include/tree.h"

void stern_brocot(vertice_t *vertice, unsigned int n, unsigned int lim,
                  unsigned int lan, unsigned int lad,
                  unsigned int ran, unsigned int rad) {
    if (n >= lim) return;
    vertice->left = create_vertice(vertice->n + lan, vertice->d + lad);
    vertice->right = create_vertice(vertice->n + ran, vertice->d + rad);
    stern_brocot(vertice->left, n+1, lim, lan, lad, vertice->n, vertice->d);
    stern_brocot(vertice->right, n+1, lim, vertice->n, vertice->d, ran, rad);
}
