#ifndef SRC_LIST_H_
#define SRC_LIST_H_

struct door{
        int id;
        int status;
};
struct node {
    struct door doors;
    struct node* nextnode;
};

struct node* add_door(struct node* elem, struct door* door);
struct node* init(struct door* door);
struct node* find_door(int door_id, struct node* root);
void output(struct node* amin);
struct node* remove_door(struct node* elem, struct node* root);
void destroy(struct node* root);

#endif  // SRC_LIST_H_
