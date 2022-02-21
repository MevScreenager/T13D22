#include <stdlib.h>
#include <stdio.h>
#include "bst.h"

int main() {
    t_btree *first = bstree_create_node(-1000);
    if (first == NULL || first->item != -1000 || first->left != NULL || first->right != NULL)
        printf("-1000: FAIL\n");
    else
        printf("-1000: SUCCESS\n");
    free(first);

    t_btree *second = bstree_create_node(333);
    if (second == NULL || second->item != 333 || second->left != NULL || second->right != NULL)
        printf("333: FAIL\n");
    else
        printf("333: SUCCESS\n");
    free(second);

    return 0;
}
