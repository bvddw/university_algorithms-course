#ifndef LESSON8_HEADER_H
#define LESSON8_HEADER_H

struct balanced_tree {
    balanced_tree* left;
    balanced_tree* right;
    int info;
};

typedef balanced_tree* avl;

#endif //LESSON8_HEADER_H
