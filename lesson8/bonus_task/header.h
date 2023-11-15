#ifndef LESSON8_HEADER_H
#define LESSON8_HEADER_H

struct balanced_tree {
    balanced_tree* left;
    balanced_tree* right;
    int info;
};

typedef balanced_tree* avl;

int height_tree(avl root); // max lenght from root to the leaf
int get_balance(avl root); // balance (left - right)
avl rotate_left(avl y); // L rotation
avl rotate_left_right(avl x); // LR rotation
avl rotate_right(avl x); // R rotation
avl rotate_right_left(avl x); // RL rotation
avl insert(avl root, int info); // function that adds element correctly to tree (saving balance)
avl build_tree(); // function that starts building tree
void pre_order(avl root); // pre-order output
void in_order(avl root); // in-order output 



#endif //LESSON8_HEADER_H
