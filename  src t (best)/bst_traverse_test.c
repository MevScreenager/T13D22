#include <stdlib.h>
#include <stdio.h>
#include "bst.h"

int cmpf(int first, int second) {
    return second >= first;
}

void applyf(int item) {
    printf("\tvisiting item: %d\n", item);
}

int main() {
    t_btree *first = bstree_create_node(0);
    bstree_insert(first, -1, cmpf);
    bstree_insert(first, 1, cmpf);
    bstree_insert(first, -3, cmpf);
    bstree_insert(first, -2, cmpf);
    bstree_insert(first, 3, cmpf);
    bstree_insert(first, 2, cmpf);

    printf("infix traversal:\n");
    bstree_apply_infix(first, applyf);

    printf("prefix traversal:\n");
    bstree_apply_prefix(first, applyf);

    printf("postifx traversal:\n");
    bstree_apply_postfix(first, applyf);

    bstree_destroy(first);
    return 0;
}
