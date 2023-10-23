#include <iostream>
#include <cstring>

struct Node {
    int info;
    char* name;
    Node* left;
    Node* right;
};

using namespace std;
Node* insert(Node* root, int value, const char* name); // Функція для вставки елемента в BST
Node* buildBST(); // Функція формування дерева
void inOrderTraversal(Node* root); // Функція для виводу дерева в симетричному порядку
Node* addStudent(Node* root, int value, const char* name); // Функція для додавання студента
Node* findMin(Node* root); // Фукнція для знаходження мінімума в дереві
Node* deleteStudent(Node* root, const char* name); // Фукнція для видалення студента
void listStudents(Node* root, int value);  // Функція для виводу тих студентів, у яких оцінка менша за передану
void deleteTree(Node* root); // Функція для видалення дерева з пам'яті



Node* insert(Node* root, int value, const char* name) {
    if (!root) {
        Node* newNode = new Node;
        newNode->info = value;
        newNode->name = new char[strlen(name) + 1];
        strcpy(newNode->name, name);
        newNode->left = nullptr;
        newNode->right = nullptr;
        return newNode;
    }

    if (value < root->info) {
        root->left = insert(root->left, value, name);
    } else if (value >= root->info) {
        root->right = insert(root->right, value, name);
    }

    return root;
}

Node* buildBST() {
    Node* root = nullptr;
    int value;
    char name[100];

    while (true) {
        cout << "Enter mark: ";
        cin >> value;
        if (value == 0) {
            break;
        }
        cout << "Enter name: ";
        cin >> name;
        root = insert(root, value, name);
    }

    return root;
}


void inOrderTraversal(Node* root) {
    if (!root) {
        return;
    }

    inOrderTraversal(root->left);
    cout << "Name: " << root->name << ", Info: " << root->info << endl;
    inOrderTraversal(root->right);
}

Node* addStudent(Node* root, int value, const char* name) {
    if (!root) {
        Node* newNode = new Node;
        newNode->info = value;
        newNode->name = new char[strlen(name) + 1];
        strcpy(newNode->name, name);
        newNode->left = nullptr;
        newNode->right = nullptr;
        return newNode;
    }

    if (value < root->info) {
        root->left = addStudent(root->left, value, name);
    } else if (value > root->info) {
        root->right = addStudent(root->right, value, name);
    }

    return root;
}

Node* findMin(Node* root) {
    while (root->left) {
        root = root->left;
    }
    return root;
}

Node* deleteStudent(Node* root, const char* name) {
    if (!root) {
        return root;
    }

    if (strcmp(name, root->name) < 0) {
        root->left = deleteStudent(root->left, name);
    } else if (strcmp(name, root->name) > 0) {
        root->right = deleteStudent(root->right, name);
    } else {
        if (root->left && root->right) {
            Node* minRightSubtree = findMin(root->right);
            root->info = minRightSubtree->info;
            root->name = new char[strlen(minRightSubtree->name) + 1];
            strcpy(root->name, minRightSubtree->name);
            root->right = deleteStudent(root->right, minRightSubtree->name);
        } else {
            Node* temp = root;
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

void listStudents(Node* root, int value) {
    if (!root) {
        return;
    }

    listStudents(root->left, value);
    if (root->info < value) {
        cout << "Name: " << root->name << ", Info: " << root->info << endl;
    }
    listStudents(root->right, value);
}

void deleteTree(Node* root) {
    if (!root) {
        return;
    }

    deleteTree(root->left);
    deleteTree(root->right);

    delete[] root->name;
    delete root;
}

int main() {
    Node* root = buildBST();
    bool flag = true;
    int choice;
    char name[100];
    int mark;

    while (flag) {
        cout << "MENU:" << endl;
        cout << "1. Output students in-order" << endl;
        cout << "2. Add new student" << endl;
        cout << "3. Delete student by name" << endl;
        cout << "4. Output students with mark less than given" << endl;
        cout << "5. Exit" << endl;
        cin >> choice;
        
        switch (choice)
        {
        case 1:
            inOrderTraversal(root);
            break;
        case 2:
            cout << "Enter new student`s mark: ";
            cin >> mark;
            cout << "Enter new student`s name: ";
            cin >> name;
            root = addStudent(root, mark, name);
            break;
        case 3:
            cout << "Enter student`s name: ";
            cin >> name;
            root = deleteStudent(root, name);
            break;  
        case 4:
            cout << "Enter mark: ";
            cin >> mark;
            cout << "Students with mark, less than " << mark << ":" << endl;
            listStudents(root, mark);
            break;    
        case 5:
            cout << "Program has been finished successfully!";
            flag = false;
            deleteTree(root);
            break; 
        default:
            cout << "Invalid choice" << endl;
            break;
        }
    }

    return 0;
}
