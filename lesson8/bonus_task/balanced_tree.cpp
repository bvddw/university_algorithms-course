#include <iostream>
#include "funcs.cpp"

using namespace std;

int main() {
    avl root = build_tree();
    cout << "\nPre order tree: ";
    pre_order(root);
    cout << "\nIn order tree: ";
    in_order(root);
    cout << "Height of the AVL tree: " << height_tree(root) << endl;

    return 0;
}
