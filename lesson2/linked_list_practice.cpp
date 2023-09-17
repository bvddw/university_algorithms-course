#include <iostream>

struct tnode {
    int info;
    tnode* next;
};

typedef tnode *pnode;

using namespace std;

void initLLWithHead(pnode head); // function to initialization LL with given head
pnode initLLWOHead(); // function to initialization LL WO given head
void LLtoConsole(pnode head); // function to output data from LL

void initLLWithHead(pnode head) {
    cout << "Enter new info: ";
    int new_info;
    cin >> new_info;
    head->info = new_info;
    pnode prev = head;

    bool flag = true;
    int choice;
    pnode new_item; // Declare new_item outside the loop
    while (flag) {
        cout << "Do you want to add a new item? (1 - yes, 2 - no)" << endl;
        cin >> choice;
        switch (choice) {
            case 1:
                new_item = new tnode; // Reuse the same new_item variable
                cout << "Enter new info: ";
                cin >> new_info;
                new_item->info = new_info;
                prev->next = new_item;
                prev = new_item;
                break;
            case 2:
                prev->next = nullptr;
                flag = false;
                break;
            default:
                cout << "Invalid choice" << endl;
                break;
        }
    }
}

pnode initLLWOHead() {
    pnode head = new tnode;

    cout << "Enter new info: ";
    int new_info;
    cin >> new_info;
    head->info = new_info;
    pnode prev = head;

    bool flag = true;
    int choice;
    pnode new_item; // Declare new_item outside the loop
    while (flag) {
        cout << "Do you want to add a new item? (1 - yes, 2 - no)" << endl;
        cin >> choice;
        switch (choice) {
            case 1:
                new_item = new tnode; // Reuse the same new_item variable
                cout << "Enter new info: ";
                cin >> new_info;
                new_item->info = new_info;
                prev->next = new_item;
                prev = new_item;
                break;
            case 2:
                prev->next = nullptr;
                flag = false;
                break;
            default:
                cout << "Invalid choice" << endl;
                break;
        }
    }
    return head;
}

void LLtoConsole(pnode head) {
    if (!head) {
        cout << "No items in LL.";
        return;
    }

    pnode cur = head;
    while (cur) {
        std::cout << cur->info << " ";
        cur = cur->next;
    }
    cout << endl;
}

int main() {
    pnode head_1 = initLLWOHead();
    
    LLtoConsole(head_1);

    while (head_1) {
        pnode temp = head_1;
        head_1 = head_1->next;
        delete temp;
    }

    pnode head_2 = new tnode;
    initLLWithHead(head_2);

    LLtoConsole(head_2);

    while (head_2) {
        pnode temp = head_2;
        head_2 = head_2->next;
        delete temp;
    }
    
    return 0;
}