#include "list.h"
#include <stdlib.h>
#include <stdio.h>

int add_door_test(struct node* elem, struct door door);
int remove_door_test(struct node* root, struct node* node);

int main() {
    struct door d1, d2, d3;
    d1.id = 0;
    d2.id = 1;
    d3.id = 2;
    d1.status = 0;
    d2.status = 1;
    d3.status = 1444;
    struct node* node = init(&d1);
    printf("\nTEST OF add_door:\n\nBEFORE RUNNING FUNCTION:\n\n");
    output(node);
    if (add_door_test(node, d2)) {
        printf("\nAFTER RUNNING FUNCTION\n\n");
        output(node);
        printf("\nRESULT:\nSUCCESS\n");
    } else {
        printf("\nAFTER RUNNING FUNCTION\n\n");
        output(node);
        printf("\nRESULT:\nFAIL\n");
    }
    node = add_door(node, &d3);
    printf("\n\nTEST OF remove_door:\n\nBEFORE RUNNING FUNCTION:\n\n");
    output(node);
    if (remove_door_test(node, node)) {
        printf("\nAFTER RUNNING FUNCTION\n\n");
        output(node);
        printf("\nRESULT:\nSUCCESS\n");
    } else {
        output(node);
        printf("\nAFTER RUNNING FUNCTION\n\n");
        printf("\nRESULT:\nFAIL\n");
    }
//    find_door(1 , node);
    destroy(node);
//    output(node);
    return 0;
}

int add_door_test(struct node* elem, struct door door) {
    int kolbefore = 0, kolafter = 0;
    while (elem -> nextnode != NULL) {
        kolbefore++;
        elem = elem -> nextnode;
    }
    elem = add_door(elem, &door);
    while (elem -> nextnode != NULL) {
        kolafter++;
        elem = elem -> nextnode;
    }
    return (kolafter == kolbefore) ? 0 : 1;
}

int remove_door_test(struct node* root, struct node* node) {
    int kolbefore = 0, kolafter = 0;
    while (root -> nextnode != NULL) {
        kolbefore++;
        root = root -> nextnode;
    }
    root = node;
    root = remove_door(root -> nextnode, root);
    while (root -> nextnode != NULL) {
        kolafter++;
        root = root -> nextnode;
    }
    return (kolafter == kolbefore) ? 0 : 1;
}
