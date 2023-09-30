#include <iostream>
#include <cstring>

using namespace std;

struct LinkedList {
    char* info;
    LinkedList* next;
};

typedef LinkedList* LL;

LL recursiveForming(); // forming LL
void addElementRecursively(LL top); // add element to the end of LL
void addElementAfterChosenOrInTheEndRecursively(LL top, const char* info); // add element after first element with chosen info
void addElementBeforeChosenOrInTheEndRecursively(LL& top, const char* info, LL prev = nullptr); // add element before first element with chosen info
void OutputLLRecursively(LL head); // output LL
void removeAllElementsWithChosenInfoRecursively(LL &top, const char* info, LL prev = nullptr); // remove all elements from LL with chosen info
int countElementsRecursively(LL top); // count number of elements in LL
void deleteLLRecursively(LL head); // delete LL



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

void addElementRecursively(LL top) {
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
    addElementRecursively(top->next);
}

void addElementAfterChosenOrInTheEndRecursively(LL top, const char* info) {
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
        addElementAfterChosenOrInTheEndRecursively(top->next, info);
    }
}

void addElementBeforeChosenOrInTheEndRecursively(LL& top, const char* info, LL prev) {
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
    addElementBeforeChosenOrInTheEndRecursively(top->next, info, top);
}

void OutputLLRecursively(LL head) {
    cout << head->info << ' ';
    if (head->next){
        OutputLLRecursively(head->next);
    }
}

void removeAllElementsWithChosenInfoRecursively(LL &top, const char* info, LL prev) {
    if (!top) {
        return;
    }
    if (strcmp(top->info, info) == 0) {
        if (!prev) {
            LL temp = top;
            top = top->next;
            delete[] temp->info;
            delete temp;
            removeAllElementsWithChosenInfoRecursively(top, info);
        } else {
            LL temp = top;
            prev->next = top->next;
            delete[] temp->info;
            delete temp;
            removeAllElementsWithChosenInfoRecursively(prev->next, info, prev);
        }
        
    } else {
        removeAllElementsWithChosenInfoRecursively(top->next, info, top);
    }
}

int countElementsRecursively(LL top) {
    if (!top) {
        return 0;
    }
    if (!top->next) {
        return 1;
    }
    return 1 + countElementsRecursively(top->next);
}

void deleteLLRecursively(LL head) {
    if (!head) {
        return;
    }
    deleteLLRecursively(head->next);

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
        number_of_items = countElementsRecursively(head);
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
            addElementRecursively(head);
            break;
        case 3:
            user_info = new char[100];
            cout << "Enter info, after which you want to add new element: ";
            cin >> user_info;
            addElementAfterChosenOrInTheEndRecursively(head, user_info);
            break;
        case 4:
            user_info = new char[100];
            cout << "Enter info, before which you want to add new element: ";
            cin >> user_info;
            addElementBeforeChosenOrInTheEndRecursively(head, user_info);
            break;
        case 5:
            user_info = new char[100];
            cout << "Enter info, elements with which you want to remove: ";
            cin >> user_info;
            removeAllElementsWithChosenInfoRecursively(head, user_info);
            break;
        case 6:
            OutputLLRecursively(head);
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

    deleteLLRecursively(head);
    return 0;
}