#include <stdlib.h>
#include <stdio.h>
#include "bst.h"

int cmpf(int first, int second) {
    return second >= first;
}

int main() {
    t_btree *first = bstree_create_node(-1000);
    bstree_insert(first, -999, cmpf);
    if (first->right == NULL || first->right->item != -999) {
        printf("-1000 root > -999 to the right: FAIL\n");
    } else {
        printf("-1000 root > -999 to the right: SUCCESS\n");
        // another
        bstree_insert(first, -998, cmpf);
        if (first->right->right == NULL || first->right->right->item != -998) {
            printf("-1000 root > -999 to the right > -998 to the right: FAIL\n");
        } else {
            printf("-1000 root > -999 to the right > -998 to the right: SUCCESS\n");
        }
    }
    bstree_destroy(first);

    t_btree *second = bstree_create_node(0);
    bstree_insert(second, -1, cmpf);
    if (second->left == NULL || second->left->item != -1) {
        printf("0 root > -1 to the left: FAIL\n");
    } else {
        printf("0 root > -1 to the left: SUCCESS\n");
    }
    // another
    bstree_insert(second, 1, cmpf);
    if (second->right == NULL || second->right->item != 1) {
        printf("0 root > 1 to the right: FAIL\n");
    } else {
        printf("0 root > 1 to the right: SUCCESS\n");
        // another
        bstree_insert(second, 1, cmpf);
        if (second->right->right == NULL || second->right->right->item != 1) {
            printf("0 root > 1 to the right > 1 to the right: FAIL\n");
        } else {
            printf("0 root > 1 to the right > 1 to the right: SUCCESS\n");
        }
    }
    bstree_destroy(second);

    return 0;
}
