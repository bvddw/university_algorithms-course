#include <iostream>
#include <cstring>
#include "two_sided_ll_funcs.h"

using namespace std;

void LLforming(LL& start, LL& end) {
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
            new_item->prev = end->prev;
            new_item->next = end;
            end->prev->next = new_item;
            end->prev = new_item;
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

void addItemAfter(LL &start, LL &end) {
    char* after_which = new char[100];
    cout << "Enter info, after which you want to add new item (item will be added after first item in LL with chosen info, or in the end): ";
    cin >> after_which;

    char* new_info = new char[50];
    cout << "Enter new info: ";
    cin >> new_info;
    LL new_item = new linked_list;
    new_item->info = new_info;

    LL cur = start->next;
    while (cur->info) {
        if (!strcmp(cur->info, after_which)) {
            new_item->prev = cur;
            new_item->next = cur->next;
            cur->next->prev = new_item;
            cur->next = new_item;
            return;
        }
        cur = cur->next;
    }
    new_item->prev = end->prev;
    new_item->next = end;
    end->prev->next = new_item;
    end->prev = new_item;
}

void addItemBefore(LL &start, LL &end) {
    char* after_which = new char[100];
    cout << "Enter info, before which you want to add new item (item will be added before last item in LL with chosen info, or in the start): ";
    cin >> after_which;

    char* new_info = new char[50];
    cout << "Enter new info: ";
    cin >> new_info;
    LL new_item = new linked_list;
    new_item->info = new_info;

    LL cur = end->prev;
    while (cur->info) {
        if (!strcmp(cur->info, after_which)) {
            new_item->next = cur;
            new_item->prev = cur->prev;
            cur->prev->next = new_item;
            cur->prev = new_item;
            return;
        }
        cur = cur->prev;
    }
    new_item->next = start->next;
    new_item->prev = start;
    start->next->prev = new_item;
    start->next = new_item;
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

int countItems(LL head) {
    int count = 0;
    LL cur = head->next;
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