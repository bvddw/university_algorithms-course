#include <iostream>
#include <cstring>
#include "sorted_LL_funcs.h"

using namespace std;

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
