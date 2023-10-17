#include <iostream>

struct binary_tree {
    int info;
    binary_tree* left;
    binary_tree* right;
};

using namespace std;
typedef binary_tree* Node;

Node formTree(); // function to forming binary tree
int findNodes(Node node, int info_to_comp); // function to count number of elements with chosen information in binary tree
void directOrder(Node node); // function to print binary tree in direct order
void symmetricalOrder(Node node); // function to print binary tree in symmetrical order
void reversedOrder(Node node); // function to print binary tree in reversed order
void deleteBinaryTree(Node node); // function to delete binary tree from memery

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

void deleteBinaryTree(Node node) {
    if (node) {
        deleteBinaryTree(node->left);
        deleteBinaryTree(node->right);
        delete node;
    }
}

int main() {
    Node main_node;
    cout << "Please, form your binary tree." << endl;
    main_node = formTree();
    bool flag = true;
    int choice;
    int info_to_find;
    while (flag) {
        cout << "MENU" << endl;
        cout << "1. Find Nodes with chosen info" << endl;
        cout << "2. Output binary tree in direct order" << endl;
        cout << "3. Output binary tree in symmetracal order" << endl;
        cout << "4. Output binary tree in reversed order" << endl;
        cout << "5. Finish program" << endl;
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "Enter info, nodes with which one you want search: ";
            cin >> info_to_find;
            (findNodes(main_node, info_to_find)) ? (cout << "There is item with info " << info_to_find << " in your binary tree." << endl) : (cout << "There is not item with info " << info_to_find << " in your binary tree." << endl);
            break;
        case 2:
            cout << "Binary tree in direct order: ";
            directOrder(main_node);
            cout << endl;
            break;
        case 3:
            cout << "In symmetrical order: ";
            symmetricalOrder(main_node);
            cout << endl;
            break;
        case 4:
            cout << "In reversed order: ";
            reversedOrder(main_node);
            cout << endl;
            break;
        case 5:
            deleteBinaryTree(main_node);
            cout << "Binary tree deleted successfully!" << endl;
            cout << "Program finished successfully!";
            flag = false;
            break;
        default:
            cout << "Invalid choice." << endl;
            break;
        }
    }
    
    return 0;
}
