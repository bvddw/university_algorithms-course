#ifndef LESSON8_HEADER_H
#define LESSON8_HEADER_H

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


#endif //LESSON8_HEADER_H
