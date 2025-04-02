#include "../include/tree.h"

void calkin_wilf(vertice_t *vertice, unsigned int n, unsigned int lim) {
    if (n >= lim) return;
    vertice->left = create_vertice(vertice->n, vertice->n + vertice->d);
    vertice->right = create_vertice(vertice->n + vertice->d, vertice->d);
    calkin_wilf(vertice->left, n+1, lim);
    calkin_wilf(vertice->right, n+1, lim);
}
