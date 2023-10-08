#include <iostream>
#include "sorted_LL_funcs.h"
#include "sorted_LL_funcs.cpp"

using namespace std;


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