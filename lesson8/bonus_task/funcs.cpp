#include <iostream>
#include "header.h"

using namespace std;

int height_tree(avl root) {
    if (!root)
        return 0;

    int left_height = height_tree(root->left);
    int right_height = height_tree(root->right);

    return 1 + max(left_height, right_height);
}

int get_balance(avl root) {
    if (!root)
        return 0;

    int left_height = height_tree(root->left);
    int right_height = height_tree(root->right);

    return left_height - right_height;
}

avl rotate_left(avl y) {
    avl x = y->left;
    avl T = x->right;

    x->right = y;
    y->left = T;

    return x;
}

avl rotate_left_right(avl x) {
    avl y = x->left;
    avl z = y->right;
    avl T1 = z->left;
    avl T2 = z->right;

    z->left = y;
    z->right = x;
    x->left = T2;
    y->right = T1;

    return z;
}

avl rotate_right(avl x) {
    avl y = x->right;
    avl T = y->left;

    y->left = x;
    x->right = T;

    return y;
}

avl rotate_right_left(avl x) {
    avl y = x->right;
    avl z = y->left;
    avl T1 = z->left;
    avl T2 = z->right;

    z->left = x;
    z->right = y;
    x->right = T1;
    y->left = T2;

    return z;
}

avl insert(avl root, int info) {
    if (!root) {
        avl new_node = new balanced_tree;
        new_node->info = info;
        new_node->left = nullptr;
        new_node->right = nullptr;
        return new_node;
    }

    if (info < root->info)
        root->left = insert(root->left, info);
    else if (info > root->info)
        root->right = insert(root->right, info);
    else // Duplicate keys are not allowed in AVL tree
        return root;

    // Get the balance factor to check if the tree became unbalanced
    int balance = get_balance(root);

    // Perform rotations as needed to balance the tree
    if (balance > 1) {
        if (info < root->left->info) {
            // just Left case
            return rotate_left(root);
        } else {
            // Left Right case
            return rotate_left_right(root);
        }
    }
    if (balance < -1) {
        if (info > root->right->info) {
            // just Right case
            return rotate_right(root);
        } else {
            // Right Left case
            return rotate_right_left(root);
        }
    }

    return root;
}

avl build_tree() {
    avl root = nullptr;
    int new_info;
    cout << "Rule of generating - you can enter any positive number.\n";

    do {
        cout << "Enter new number (or a non-positive number to stop): ";
        cin >> new_info;

        if (new_info > 0) {
            root = insert(root, new_info);
        }
    } while (new_info > 0);

    return root;
}

void pre_order(avl root) {
    if (!root) {
        return;
    }
    cout << root->info << ' ';
    pre_order(root->left);
    pre_order(root->right);
}

void in_order(avl root) {
    if (!root) {
        return;
    }
    in_order(root->left);
    cout << root->info << ' ';
    in_order(root->right);
}
