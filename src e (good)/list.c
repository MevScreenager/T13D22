#include "list.h"
#include <stdlib.h>
#include <stdio.h>

struct node* init(struct door* door) {
    struct node* node = malloc(sizeof(struct node));
    node -> doors.id = door -> id;
    node -> doors.status = door -> status;
    node -> nextnode = NULL;
    return node;
}

struct node* add_door(struct node* elem, struct door* door) {
    struct node* node = malloc(sizeof(struct node));
    node -> nextnode = elem -> nextnode;
    elem -> nextnode = node;
    node -> doors.id = door -> id;
    node -> doors.status = door -> status;
    return elem;
}

struct node* find_door(int door_id, struct node* root) {
    int check = 0;
    while (root -> nextnode != NULL && check == 0) {
        if (door_id == root -> doors.id) {
            check = 1;
        }
        if (check == 0)
        root = root -> nextnode;
    }
    printf("\nFIND DOOR == %d\n", root -> doors.id);
    return root;
}

struct node* remove_door(struct node* elem, struct node* root) {
    while (root -> nextnode != elem) {
        root = root -> nextnode;
    }
    root -> nextnode = elem -> nextnode;
    free(elem);
    return root;
}

void destroy(struct node* root) {
    while (root -> nextnode != NULL) {
        root = remove_door(root -> nextnode, root);
    }
    free(root);
}

void output(struct node* amin) {
    while (amin -> nextnode != NULL) {
        printf("DOORID %d\nDOOR STATUS %d\n", amin -> doors.id, amin -> doors.status);
        amin = amin -> nextnode;
    }
    printf("DOORID %d\nDOOR STATUS %d\n", amin -> doors.id, amin -> doors.status);
}
