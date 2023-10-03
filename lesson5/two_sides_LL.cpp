#include <iostream>

using namespace std;

struct linked_list {
    int info;
    linked_list* next;
    linked_list* prev;
};

typedef linked_list *LL;

void sortedLLforming (LL &start, LL & end);
void LLprimaryOutput(LL start);
void LLreverseOutput(LL end);
void LLdelete(LL start, LL end);


void sortedLLforming (LL &start, LL &end) {
    int info;
    cout << "Enter info: ";
    cin >> info;
    LL head = new linked_list;
    head->prev = start;
    head->next = end;
    head->info = info;
    start->next = head;
    end->prev = head;
    int choice;
    LL new_item;
    LL cur;
    while (true) {
        cout << "Do you want to add new item?\n1. Yes\n2. No" << endl;
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter new info: ";
            cin >> info;
            new_item = new linked_list;
            new_item->info = info;
            new_item->prev = nullptr;
            new_item->next = nullptr;

            if (new_item->info < head->info) {
                new_item->next = head;
                new_item->prev = start;
                head->prev = new_item;
                start->next = new_item;
                head = new_item;
            } else {
                cur = head;
                while (cur->next->info && new_item->info >= cur->next->info) {
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
    start->info = NULL;
    start->next = nullptr;
    start->prev = nullptr;

    LL end = new linked_list;
    end->info = NULL;
    end->next = nullptr;
    end->prev = nullptr;

    //forming sorted double-LL 
    sortedLLforming(start, end);

    // printing LL
    LLprimaryOutput(start);
    LLreverseOutput(end);

    //clearing memory
    LLdelete(start, end);

    return 0;
}