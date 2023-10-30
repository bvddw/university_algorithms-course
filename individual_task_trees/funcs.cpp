#include <iostream>
#include <fstream>
#include <cstring>
#include "trees_dict.h"

using namespace std;

const char* getEng(const char info[]) {
    int endIndex = 0;
    int spacesCounter = 0;
    while (spacesCounter < 1) {
        if (info[endIndex] == ' ') {
            spacesCounter++;
        }
        endIndex++;
    }

    char* engWord = new char[endIndex];

    for (int i = 0; i < endIndex; i++) {
        engWord[i] = info[i];
    }

    engWord[endIndex - 1] = '\0';

    return engWord;
}

const char* getUkr(const char info[]) {
    int index = 0;
    int startIndex = 0;
    int spaceCounter = 0;
    while (spaceCounter < 2) {
        if (info[index] == ' ') {
            spaceCounter++;
            startIndex = index + 1;
        }
        index++;
    }

    char* ukrWord = new char[strlen(info) + 1 - startIndex];

    for (int i = startIndex; i < strlen(info); i++) {
        ukrWord[i - startIndex] = info[i];
    }

    ukrWord[strlen(info) - startIndex] = '\0';

    return ukrWord;
}

DT insert(DT root, const char* eng, const char* ukr) {
    if (!root) {
        DT newNode = new dictionaryTree;
        newNode->eng_word = new char[strlen(eng) + 1];
        strcpy(newNode->eng_word, eng);
        newNode->ukr_word = new char[strlen(ukr) + 1];
        strcpy(newNode->ukr_word, ukr);
        newNode->counter = 0;
        newNode->left = nullptr;
        newNode->right = nullptr;

        return newNode;
    }

    if (strcmp(eng, root->eng_word) == -1) {
        root->left = insert(root->left, eng, ukr);
    } else if (strcmp(eng, root->eng_word) == 1) {
        root->right = insert(root->right, eng, ukr);
    }

    return root;
}

DT dataToTreeTxt(char* filename) {
    DT root = nullptr;
    ifstream input_file(filename);

    if (!input_file.is_open()) {
        cerr << "Error while opening file." << endl;
    }

    const int length_line = 1000;
    char line[length_line];

    while(input_file.getline(line, length_line)) {
        root = insert(root, getEng(line), getUkr(line));
    }

    input_file.close();
    return root;
}

void inOrderTraversal(DT root) {
    if (!root) {
        return;
    }

    inOrderTraversal(root->left);
    cout << "English word: " << root->eng_word << " -- " << "Ukrainian translit: " << root->ukr_word << " -- " << root->counter << endl;
    inOrderTraversal(root->right);
}

void preOrderTraversal(DT root) {
    if (!root) {
        return;
    }

    cout << "English word: " << root->eng_word << " -- " << "Ukrainian translit: " << root->ukr_word << " -- " << root->counter << endl;
    preOrderTraversal(root->left);
    preOrderTraversal(root->right);
}

DT retrieveWord(DT root, const char* info) {
    if (!root) {
        return nullptr;
    }
    if (!strcmp(root->eng_word, info)) {
        root->counter++;
        return root;
    }
    return retrieveWord(strcmp(root->eng_word, info) == -1 ? root->right : root->left, info);
}

DT updateWord(DT root, const char* info, const char* newInfo) {
    if (!root) {
        return nullptr;
    }
    if (!strcmp(root->eng_word, info)) {
        root->ukr_word = new char[strlen(newInfo) + 1];
        strcpy(root->ukr_word, newInfo);
        return root;
    }
    return updateWord(strcmp(root->eng_word, info) == -1 ? root->right : root->left, info, newInfo);
}

DT findMin(DT root) {
    while (root->left) {
        root = root->left;
    }
    return root;
}

DT deleteWord(DT root, const char* info) {
    if (!root) {
        return root;
    }

    if (strcmp(info, root->eng_word) < 0) {
        root->left = deleteWord(root->left, info);
    } else if (strcmp(info, root->eng_word) > 0) {
        root->right = deleteWord(root->right, info);
    } else {
        if (root->left && root->right) {
            DT minRightSubtree = findMin(root->right);
            root->counter = minRightSubtree->counter;
            root->eng_word = new char[strlen(minRightSubtree->eng_word) + 1];
            strcpy(root->eng_word, minRightSubtree->eng_word);
            root->ukr_word = new char[strlen(minRightSubtree->ukr_word) + 1];
            strcpy(root->ukr_word, minRightSubtree->ukr_word);
            root->right = deleteWord(root->right, minRightSubtree->eng_word);
        } else {
            DT temp = root;
            if (root->left) {
                root = root->left;
            } else {
                root = root->right;
            }
            delete temp;
        }
    }
    return root;
}

DT findMaxCounter(DT root, DT mostCount) {
    if (!root) {
        return mostCount;
    }
    if (root->counter > mostCount->counter) {
        mostCount = root;
    }

    mostCount = findMaxCounter(root->left, mostCount);
    mostCount = findMaxCounter(root->right, mostCount);
    return mostCount;
}

DT insertNode(DT root, DT newNode) {
    if (!root) {
        DT newRoot = new dictionaryTree;
        newRoot->counter = newNode->counter;
        newRoot->eng_word = new char[strlen(newNode->eng_word) + 1];
        strcpy(newRoot->eng_word, newNode->eng_word);
        newRoot->ukr_word = new char[strlen(newNode->ukr_word) + 1];
        strcpy(newRoot->ukr_word, newNode->ukr_word);
        newRoot->left = nullptr;
        newRoot->right = nullptr;

        return newRoot;
    }

    if (strcmp(newNode->eng_word, root->eng_word) < 0) {
        root->left = insertNode(root->left, newNode);
    } else if (strcmp(newNode->eng_word, root->eng_word) > 0) {
        root->right = insertNode(root->right, newNode);
    }

    return root;
}

DT rebuiltTree(DT root) {
    DT newRoot = nullptr;
    DT rootToDelete;

    while (root->left || root->right) {
        rootToDelete = findMaxCounter(root, root);
        newRoot = insertNode(newRoot, rootToDelete);
        root = deleteWord(root, rootToDelete->eng_word);
    }

    newRoot = insertNode(newRoot, root);
    delete root;

    return newRoot;
}
