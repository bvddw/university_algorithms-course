#include <iostream>
#include <cstring>
#include "two_sided_ll_funcs.h"
#include "two_sided_ll_funcs.cpp"

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

    //forming two-sided-LL
    bool flag = true;
    int choice;

    while (flag) {
        cout << endl << "MENU" << endl;
        if (countItems(start)) {
            cout << "1." << endl;
            cout << "2. Add item after chosen" << endl;
            cout << "3. Add item before chosen" << endl;
            cout << "4. Remove chosen item" << endl;
            cout << "5. Count number of items" << endl;
            cout << "6. Output linked list in primary order" << endl;
            cout << "7. Output linked list in reversed order" << endl;
            cout << "8. Check is linked list symmetrical" << endl;
        } else {
            cout << "1. Form linked list" << endl;
            cout << "2." << endl;
            cout << "3." << endl;
            cout << "4." << endl;
            cout << "5." << endl;
            cout << "6." << endl;
            cout << "7." << endl;
            cout << "8." << endl;
        }        
        cout << "9. Finish program" << endl;
        cin >> choice;
        if (!countItems(start) && choice > 1 && choice < 9) {
            choice = -1;
        }
        if (countItems(start) && choice == 1) {
            choice = -1;
        }
        switch (choice) {
        case 1:
            LLforming(start, end);
            break;
        case 2:
            addItemAfter(start, end);
            break;
        case 3:
            addItemBefore(start, end);
            break;
        case 4:
            removeItem(start);
            break;
        case 5:
            cout << "In linked list " << countItems(start) << " items" << endl;
            break;
        case 6:
            LLprimaryOutput(start);
            break;
        case 7:
            LLreverseOutput(end);
            break;
        case 8:
            (isLLSymmetrical(start, end)) ? (cout << "Linked list is symmetrical" << endl) : (cout << "Linked list is not symmetrical" << endl);
            break;
        case 9:
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