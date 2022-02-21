#ifndef SRC_STACK_H_
#define SRC_STACK_H_

struct door{
        int id;
        int status;
};
struct node {
    struct door doors;
    struct node* nextnode;
};

struct node* push(struct node* elem, struct door* door);
struct node* init(struct door* door);
struct door pop(struct node* amin);
struct node* remove_door(struct node* elem, struct node* root);
void destroy(struct node* root);
void output(struct node* amin);

#endif  // SRC_STACK_H_
