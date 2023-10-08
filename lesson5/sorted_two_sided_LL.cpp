#include <iostream>
#include <cstring>

using namespace std;

struct linked_list {
    const char* info;
    linked_list* next;
    linked_list* prev;
};

typedef linked_list* LL;


void sortedLLforming(LL& start, LL& end); // forming Linked List, sorting whwile forming
bool isLLSymmetrical(LL start, LL end);
void removeItem(LL &start); // remove all items with chosen info
void addItem(LL &start); // add item, saving ordering
int countItems(LL start); // count items in LL
void LLprimaryOutput(LL start); // output in order from start to end
void LLreverseOutput(LL end); // output in order from end to start
void LLdelete(LL start, LL end); // clearing memory



void sortedLLforming(LL& start, LL& end) {
    char* input = new char[100];

    cout << "Enter info: ";
    cin >> input;

    LL head = new linked_list;
    head->prev = start;
    head->next = end;
    head->info = input; 

    start->next = head;
    end->prev = head;

    int choice;
    LL new_item;
    LL cur;

    while (true) {
        cout << "Do you want to add a new item?\n1. Yes\n2. No" << endl;
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter new info: ";
            input = new char[100];
            cin >> input;

            new_item = new linked_list;
            new_item->info = input;
            new_item->prev = nullptr;
            new_item->next = nullptr;

            if (strcmp(new_item->info, head->info) < 0) {
                new_item->next = head;
                new_item->prev = start;
                head->prev = new_item;
                start->next = new_item;
                head = new_item;
            } else {
                cur = head;
                while (cur->next->info && strcmp(new_item->info, cur->next->info) >= 0) {
                    cur = cur->next;
                }
                new_item->next = cur->next;
                new_item->prev = cur;
                if (cur->next->info) {
                    cur->next->prev = new_item;
                } else {
                    end->prev = new_item;
                }
                cur->next = new_item;
            }
            break;
        case 2:
            cout << "LL successfully formed." << endl;
            return;
        default:
            cout << "Invalid choice." << endl;
            break;
        }
    }
}

bool isLLSymmetrical(LL start, LL end) {
    LL head = start->next;
    LL tail = end->prev;
    while (head->info) {
        if (strcmp(head->info, tail->info)) {
            return false;
        }
        head = head->next;
        tail = tail->prev;
    }
    return true;
}

void removeItem(LL &start) {
    char* info_to_remove = new char[100];
    cout << "Enter info, which you want to remove from LL (all items with this info will be removed): ";
    cin >> info_to_remove;

    LL cur = start->next;
    while (cur->info) {
        if (!strcmp(cur->info, info_to_remove)) {
            cur->next->prev = cur->prev;
            cur->prev->next = cur->next;
        }
        cur = cur->next;
    }
}

void addItem(LL &start) {
    char* new_info = new char[50];
    cout << "Enter new info: ";
    cin >> new_info;
    LL new_item = new linked_list;
    new_item->info = new_info;

    LL cur = start;
    if (strcmp(new_item->info, cur->next->info) <= 0) {
        new_item->prev = start;
        new_item->next = start->next;
        start->next->prev = new_item;
        start->next = new_item;
        return;
    }
    cur = cur->next;
    while(cur->info) {
        if (strcmp(new_item->info, cur->info) <= 0) {
            new_item->prev = cur->prev;
            new_item->next = cur;
            cur->prev->next = new_item;
            cur->prev = new_item;
            return;
        }
        cur = cur->next;
    }
    new_item->prev = cur->prev;
    new_item->next = cur;
    cur->prev->next = new_item;
    cur->prev = new_item;
}

int countItems(LL start) {
    int count = 0;
    LL cur = start->next;
    while (cur->info) {
        cur = cur->next;
        count++;
    }
    return count;
}

void LLprimaryOutput(LL start) {
    cout << endl << "Double-linked List in primary order: ";
    LL top = start->next;
    while (top->info) {
        cout << top->info << ' ';
        top = top->next;
    }
}

void LLreverseOutput(LL end) {
    cout << endl << "Double-linked List in reversed order: ";
    LL top = end->prev;
    while (top->info) {
        cout << top->info << ' ';
        top = top->prev;
    }
}

void LLdelete(LL start, LL end) {
    LL top = start->next;
    while (top->info) {
        LL temp = top;
        top = top->next;
        delete temp;
    }
    delete start;
    delete end;
    cout << endl << "LL successfully deleted." << endl;
}

int main() {
    LL start = new linked_list;
    start->info = nullptr;
    start->prev = nullptr;

    LL end = new linked_list;
    end->info = nullptr;
    end->next = nullptr;
    end->prev = start;
    start->next = end;

    bool flag = true;
    int choice;
    while (flag) {
        cout << endl << "MENU" << endl;
        if (countItems(start)) {
            cout << "1." << endl;
            cout << "2. Add item" << endl;
            cout << "3. Remove all chosen items" << endl;
            cout << "4. Count number of items" << endl;
            cout << "5. Output linked list in primary order" << endl;
            cout << "6. Output linked list in reversed order" << endl;
            cout << "7. Check is linked list symmetrical" << endl;
        } else {
            cout << "1. Form sorted linked list" << endl;
            cout << "2." << endl;
            cout << "3." << endl;
            cout << "4." << endl;
            cout << "5." << endl;
            cout << "6." << endl;
            cout << "7." << endl;
        }        
        cout << "8. Finish program" << endl;
        cin >> choice;
        if (!countItems(start) && choice > 1 && choice < 8) {
            choice = -1;
        }
        if (countItems(start) && choice == 1) {
            choice = -1;
        }
        switch (choice) {
        case 1:
            sortedLLforming(start, end);
            break;
        case 2:
            addItem(start);
            break;
        case 3:
            removeItem(start);
            break;
        case 4:
            cout << "In linked list " << countItems(start) << " items" << endl;
            break;
        case 5:
            LLprimaryOutput(start);
            break;
        case 6:
            LLreverseOutput(end);
            break;
        case 7:
            (isLLSymmetrical(start, end)) ? (cout << "Linked list is symmetrical" << endl) : (cout << "Linked list is not symmetrical" << endl);
            break;
        case 8:
            cout << "Thank you for using our program!" << endl;
            flag = false;
            LLdelete(start, end);
            break;
        default:
            cout << "Invalid choice" << endl;
            break;
        }
    }

    return 0;
}