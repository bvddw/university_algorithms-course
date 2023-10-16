#include <iostream>

struct binary_tree {
    int info;
    binary_tree* left;
    binary_tree* right;
};

using namespace std;
typedef binary_tree* Node;

Node formTree() {
    Node new_node;
    int info;
    cin >> info;
    if (!info) {
        return nullptr;
    }
    new_node = new binary_tree;
    new_node->info = info;
    new_node->left = formTree();
    new_node->right = formTree();
    return new_node;
}

int findNodes(Node node, int info_to_comp) {
    int counter = 0;
    if (node->info == info_to_comp) {
        counter++;
    }
    if (node->left){
        counter += findNodes(node->left, info_to_comp);
    }
    if (node->right) {
        counter += findNodes(node->right, info_to_comp);
    }
    return counter;
}

void directOrder(Node node) {
    if (node) {
        cout << node->info << ' ';
        directOrder(node->left);
        directOrder(node->right);
    }
}

void symmetricalOrder(Node node) {
    if (node) {
        symmetricalOrder(node->left);
        cout << node->info << ' ';
        symmetricalOrder(node->right);
    }
}

void reversedOrder(Node node) {
    if (node) {
        reversedOrder(node->left);
        reversedOrder(node->right);
        cout << node->info << ' ';
    }
}

int main() {
    Node main_node;
    main_node = formTree();
    cout << "In your tree " << findNodes(main_node, 100) << " items with value 100." << endl;
    cout << "In direct order: ";
    directOrder(main_node);
    cout << endl;
    cout << "In symmetrical order: ";
    symmetricalOrder(main_node);
    cout << endl;
    cout << "In reversed order: ";
    reversedOrder(main_node);
    return 0;
}
