#include "stack.h"
#include <stdio.h>
#include <stdlib.h>

int push_test(struct node* elem, struct door* door);
int pop_test(struct node* amin, struct node* node);
int main() {
    struct door d1, d2, d3;
    d1.id = 0;
    d2.id = 1;
    d3.id = 2;
    d1.status = 0;
    d2.status = 1;
    d3.status = 1444;
    struct node* node = init(&d1);
    printf("\nTEST OF push:\n\nBEFORE RUNNING FUNCTION:\n\n");
    output(node);
    if (push_test(node, &d2)) {
        printf("\nAFTER RUNNING FUNCTION\n\n");
        output(node);
        printf("\nRESULT:\nSUCCESS\n");
    } else {
        printf("\nAFTER RUNNING FUNCTION\n\n");
        output(node);
        printf("\nRESULT:\nFAIL\n");
    }
    printf("\n\nTEST OF pop:\n\nBEFORE RUNNING FUNCTION:\n\n");
    output(node);
    push(node, &d3);
    if (pop_test(node, node)) {
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
    output(node);
    return 0;
}

int push_test(struct node* elem, struct door* door) {
    int check = 0;
    push(elem, door);
    struct node* temp;
    while (elem -> nextnode != NULL) {
        elem = elem -> nextnode;
    }
    if (elem -> doors.id == door -> id)
        check = 1;
    return check;
}

int pop_test(struct node* amin, struct node* node) {
    struct node* temp = amin;
    int check = 0;
    while (temp -> nextnode != NULL) {
        temp = temp -> nextnode;
        check++;
    }
    int after = 0;
    struct door data = pop(amin);
    temp = amin;
    while (temp -> nextnode != NULL) {
        temp = temp -> nextnode;
        after++;
    }
    printf("\nDOOR RETURNED IS:\n ID:%d STATUS:%d\n", data.id, data.status);
    return (after == check - 1) ? 1 : 0;
}
