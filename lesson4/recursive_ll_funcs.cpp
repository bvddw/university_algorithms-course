#include <iostream>
#include <cstring>

using namespace std;

struct LinkedList {
    char* info;
    LinkedList* next;
};

typedef LinkedList* LL;

LL recursiveForming(); // forming LL
void addElement(LL top); // add element to the end of LL
void addElementAfterChosen(LL top, const char* info); // add element after first element with chosen info
void addElementBeforeChosen(LL& top, const char* info, LL prev = nullptr); // add element before first element with chosen info
void OutputLL(LL head); // output LL
void removeAllElements(LL &top, const char* info, LL prev = nullptr); // remove all elements from LL with chosen info
int countElements(LL top); // count number of elements in LL
void deleteLL(LL head); // delete LL



LL recursiveForming() {
    char* info = new char[100];
    cout << "Info: ";
    cin >> info;

    LL top = new LinkedList;
    top->info = info;
    cout << "You want to add more? (1 - Yes, 2 - No) ";
    int choice;
    cin >> choice;
    if (choice == 1) {
        top->next = recursiveForming();
    } else {
        top->next = nullptr;
    }
    return top;
}

void addElement(LL top) {
    if (!top->next) {
        char* info = new char[100];
        cout << "Info: ";
        cin >> info;
        LL new_elem = new LinkedList;
        new_elem->info = info;
        new_elem->next = nullptr;
        top->next = new_elem;
        return;
    }
    addElement(top->next);
}

void addElementAfterChosen(LL top, const char* info) {
    if (!top->next) {
        char* new_info = new char[100];
        cout << "Info: ";
        cin >> new_info;
        LL new_elem = new LinkedList;
        new_elem->info = new_info;
        new_elem->next = nullptr;
        top->next = new_elem;
    } else if (strcmp(top->info, info) == 0) {
        char* new_info = new char[100];
        cout << "Info: ";
        cin >> new_info;
        LL new_elem = new LinkedList;
        new_elem->info = new_info;
        new_elem->next = top->next;
        top->next = new_elem;
    } else {
        addElementAfterChosen(top->next, info);
    }
}

void addElementBeforeChosen(LL& top, const char* info, LL prev) {
    if (strcmp(top->info, info) == 0) {
        
        char* new_info = new char[100];
        cout << "Info: ";
        cin >> new_info;

        LinkedList* new_ll_item = new LinkedList;
        new_ll_item->info = new_info;
        new_ll_item->next = top;

        if (prev != nullptr) {
            prev->next = new_ll_item;
        } else {
            top = new_ll_item;
        }
        return;
    }
    addElementBeforeChosen(top->next, info, top);
}

void OutputLL(LL head) {
    cout << head->info << ' ';
    if (head->next){
        OutputLL(head->next);
    }
}

void removeAllElements(LL &top, const char* info, LL prev) {
    if (!top) {
        return;
    }
    if (strcmp(top->info, info) == 0) {
        if (!prev) {
            LL temp = top;
            top = top->next;
            delete[] temp->info;
            delete temp;
            removeAllElements(top, info);
        } else {
            LL temp = top;
            prev->next = top->next;
            delete[] temp->info;
            delete temp;
            removeAllElements(prev->next, info, prev);
        }
        
    } else {
        removeAllElements(top->next, info, top);
    }
}

int countElements(LL top) {
    if (!top) {
        return 0;
    }
    if (!top->next) {
        return 1;
    }
    return 1 + countElements(top->next);
}

void deleteLL(LL head) {
    if (!head) {
        return;
    }
    deleteLL(head->next);

    delete[] head->info;
    delete head;
}

int main() {
    LL head = nullptr;
    bool flag = true;
    int choice;
    int number_of_items;
    char* user_info;
    while (flag) {
        number_of_items = countElements(head);
        cout << endl << "MENU:" << endl;
        cout << "1. Forming LL" << endl;
        if (number_of_items) {
            cout << "2. Add element to the end" << endl;
            cout << "3. Add element after first element with chosen info" << endl;
            cout << "4. Add element before first element with chosen info" << endl;
            cout << "5. Delete all items with chosen info" << endl;
            cout << "6. Output all items" << endl;
        } else {
            cout << "2." << endl;
            cout << "3." << endl;
            cout << "4." << endl;
            cout << "5." << endl;
            cout << "6." << endl;
        }
        cout << "7. Exit program" << endl;
        cin >> choice;
        if (!number_of_items && choice > 1 && choice < 7) {
            choice = -1;
        }
        switch (choice) {
        case 1:
            head = recursiveForming();
            break;
        case 2:
            addElement(head);
            break;
        case 3:
            user_info = new char[100];
            cout << "Enter info, after which you want to add new element: ";
            cin >> user_info;
            addElementAfterChosen(head, user_info);
            break;
        case 4:
            user_info = new char[100];
            cout << "Enter info, before which you want to add new element: ";
            cin >> user_info;
            addElementBeforeChosen(head, user_info);
            break;
        case 5:
            user_info = new char[100];
            cout << "Enter info, elements with which you want to remove: ";
            cin >> user_info;
            removeAllElements(head, user_info);
            break;
        case 6:
            OutputLL(head);
            break;
        case 7:
            cout << "Program finished successfully!";
            flag = false;
            break;
        default:
            cout << "Invalid choice.";
            break;
        }
    }

    deleteLL(head);
    return 0;
}