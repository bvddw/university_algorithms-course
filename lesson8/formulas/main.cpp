#include <iostream>
#include "funcs.cpp"

using namespace std;


int main() {
    char* input = new char;
    cout << "Enter expression: ";
    cin >> input;
    const char* expression = input;
    int index = 0;
    Node* root = buildExpressionTree(expression, index);
    cout << "Inorder traversal of the expression tree:" << endl;
    inOrderTraversal(root);
    cout << endl;
    cout << "Result of the expression: " << countResult(root);
    return 0;
}
