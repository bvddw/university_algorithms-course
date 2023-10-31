#include <iostream>
#include <stack>
#include <cctype>

using namespace std;

struct Node {
    char data;
    Node* left;
    Node* right;
};

bool isOperator(char c);
bool isNum(char c);
int charToInt(char c);
Node* buildExpressionTree(const char* expression, int& index);
void inOrderTraversal(Node* root);
double countResult(Node* root);


bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

bool isNum(char c) {
    return (c == '0' || c == '1' || c == '2' || c == '3' || c == '4' || c == '5' || c == '6' || c == '7' || c == '8' || c == '9');
}

int charToInt(char c) {
    if (c == '0') {
        return 0;
    }
    if (c == '1') {
        return 1;
    }
    if (c == '2') {
        return 2;
    }
    if (c == '3') {
        return 3;
    }
    if (c == '4') {
        return 4;
    }
    if (c == '5') {
        return 5;
    }
    if (c == '7') {
        return 7;
    }
    if (c == '8') {
        return 8;
    }
    return 9;
}

Node* buildExpressionTree(const char* expression, int& index) {
    char c = expression[index];
    index++;

    if (c == '\0') {
        return nullptr;
    }

    if (isNum(c)) {
        Node* node = new Node;
        node->data = c;
        node->left = nullptr;
        node->right = nullptr;
        return node;
    } else if (isOperator(c)) {
        Node* newNode = new Node;
        newNode->data = c;
        newNode->left = nullptr;
        newNode->right = nullptr;
        newNode->left = buildExpressionTree(expression, index);
        newNode->right = buildExpressionTree(expression, index);
        return newNode;
    }

    return nullptr;
}

void inOrderTraversal(Node* root) {
    if (root) {
        if (isOperator(root->data))
            cout << "(";
        inOrderTraversal(root->left);
        cout << root->data;
        inOrderTraversal(root->right);
        if (isOperator(root->data))
            cout << ")";
    }
}

double countResult(Node* root) {
    double result = 0;
    if (!root->left && !root->right) {
        return charToInt(root->data);
    }
    if (root->data == '/') {
        if (countResult(root->right) == 0) {
            cout << endl;
            cerr << "Dividing by zero error caught.";
        }
        return countResult(root->left) / countResult(root->right);
    }
    if (root->data == '*') {
        return countResult(root->left) * countResult(root->right);
    }
    if (root->data == '-') {
        return countResult(root->left) - countResult(root->right);
    }
    return countResult(root->left) + countResult(root->right);
}

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
