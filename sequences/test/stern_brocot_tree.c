#include <stdio.h>
#include "../include/tree.h"

int main(void) {
    /* description */ 
    
    unsigned int n = 0; // order
    unsigned int limit = 0; // amount of tree layers
    unsigned int prev = 1, next = 1, tmp = 0; // fibonacci numbers
    
    printf("Enter tree order: ");
    scanf("%u", &n);
    if (!n) return 0;
    
    // amount of tree layers calculation 
    while (next < n) {
        tmp = next;
        next += prev;
        prev = tmp;
        limit += 1;
    }
    
    printf("The tree consists of %u layers\n", limit);
    
    // Strern-Brocot tree
    vertice_t *left_ancestor = create_vertice(0, 1);
    vertice_t *right_ancestor = create_vertice(1, 0);
    vertice_t *vertice = create_vertice(1, 1);
    stern_brocot(vertice, 1, limit, 
                 left_ancestor->n, left_ancestor->d, 
                 right_ancestor->n, right_ancestor->d);
    
    printf("Strern-Brocot tree (inorder traveral):\n{");
    print_tree(left_ancestor);
    print_tree(vertice);
    printf("%u/%u}\n", right_ancestor->n, right_ancestor->d);
    
    return 0;
}
