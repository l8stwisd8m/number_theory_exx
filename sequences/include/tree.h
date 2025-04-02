#ifndef _TREE_H_
#define _TREE_H_

typedef struct vertice_t {
    unsigned int n; // numerator
    unsigned int d; // denominator
    struct vertice_t *left;
    struct vertice_t *right;
} vertice_t;

vertice_t* create_vertice(unsigned int p, unsigned int q);
void print_vertice(vertice_t *vertice);
void print_tree(vertice_t *vertice);
void calkin_wilf(vertice_t *vertice, unsigned int n, unsigned int lim);
void stern_brocot(vertice_t *vertice, unsigned int n, unsigned int lim,
                  unsigned int lan, unsigned int lad,
                  unsigned int ran, unsigned int rad);

#endif // _TREE_H_
