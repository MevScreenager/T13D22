#include "stack.h"
#include <stdio.h>
#include <stdlib.h>

struct node* init(struct door* door) {
    struct node* node = malloc(sizeof(struct node));
    node -> doors.id = door -> id;
    node -> doors.status = door -> status;
    node -> nextnode = NULL;
    return node;
}

struct node* push(struct node* elem, struct door* door) {
    struct node* node = malloc(sizeof(struct node));
    while (elem -> nextnode != NULL)
        elem = elem -> nextnode;
    elem -> nextnode = node;
    node -> doors.id = door -> id;
    node -> doors.status = door -> status;
    node -> nextnode = NULL;
    return elem;
}


struct node* remove_door(struct node* elem, struct node* root) {
    while (root -> nextnode != elem) {
        root = root -> nextnode;
    }
    root -> nextnode = elem -> nextnode;
    elem = NULL;
    free(elem);
    return root;
}

void destroy(struct node* root) {
    while (root -> nextnode != NULL) {
        pop(root);
    }
    free(root);
}

struct door pop(struct node* amin) {
    struct node* temp = amin;
    struct node* prev;
    while (temp -> nextnode != NULL) {
        prev = temp;
        temp = temp -> nextnode;
    }
    struct door res;
    res.id = temp -> doors.id;
    res.status = temp -> doors.status;
    free(temp);
    prev -> nextnode = NULL;
    return res;
}

void output(struct node* amin) {
    while (amin -> nextnode != NULL) {
        printf("DOORID %d\nDOOR STATUS %d\n", amin -> doors.id, amin -> doors.status);
        amin = amin -> nextnode;
    }
    printf("DOORID %d\nDOOR STATUS %d\n", amin -> doors.id, amin -> doors.status);
}
