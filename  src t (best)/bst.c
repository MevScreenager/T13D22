#include <stdlib.h>
#include "bst.h"

t_btree *bstree_create_node(int item) {
    t_btree *result = malloc(sizeof(t_btree));
    result->item = item;
    result->left = NULL;
    result->right = NULL;
    return result;
}

void bstree_insert(t_btree *root, int item, int (*cmpf)(int, int)) {
    // to the right
    if (cmpf(root->item, item)) {
        if (root->right == NULL)
            root->right = bstree_create_node(item);
        else
            bstree_insert(root->right, item, cmpf);
    // to the left
    } else {
        if (root->left == NULL)
            root->left = bstree_create_node(item);
        else
            bstree_insert(root->left, item, cmpf);
    }
}

void bstree_destroy(t_btree *root) {
    if (root->right != NULL)
        bstree_destroy(root->right);

    if (root->left != NULL)
        bstree_destroy(root->left);

    free(root);
}

void bstree_apply_infix(t_btree *root, void (*applyf)(int)) {
    if (root->left != NULL)
        bstree_apply_infix(root->left, applyf);
    applyf(root->item);
    if (root->right != NULL)
        bstree_apply_infix(root->right, applyf);
}

void bstree_apply_prefix(t_btree *root, void (*applyf)(int)) {
    applyf(root->item);
    if (root->left != NULL)
        bstree_apply_prefix(root->left, applyf);
    if (root->right != NULL)
        bstree_apply_prefix(root->right, applyf);
}

void bstree_apply_postfix(t_btree *root, void (*applyf)(int)) {
    if (root->right != NULL)
        bstree_apply_postfix(root->right, applyf);
    applyf(root->item);
    if (root->left != NULL)
        bstree_apply_postfix(root->left, applyf);
}
