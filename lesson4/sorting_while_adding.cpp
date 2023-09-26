#include <iostream>
#include <cstring>

struct linked_list {
    char* info;
    linked_list* next;
};

using namespace std;
typedef linked_list* LL;

// Функція для формування та сортування зв'язного списку
LL forming_sorted_LL() {
    int choice;
    char* data = new char;
    LL new_ll_item;
    LL cur;

    cout << "Enter info: ";
    cin >> data;

    // Створюємо початковий вузол списку
    LL head = new linked_list;
    head->info = data;
    strcpy(head->info, data);
    head->next = nullptr;

    while (true) {
        cout << "Do you want to add more new info?\n1 - YES\n2 - NO\n";
        cin >> choice;
        switch (choice) {
        case 1:
            cout << "Enter new data: ";
            data = new char;
            cin >> data;
            new_ll_item = new linked_list;
            new_ll_item->info = data;
            strcpy(new_ll_item->info, data);
            new_ll_item->next = nullptr;

            cur = head;
            if (strcmp(head->info, data) > 0) {
                new_ll_item->next = head;
                head = new_ll_item;
            } else {
                while (cur->next && strcmp(data, cur->next->info) > 0) {
                    cur = cur->next;
                }
                new_ll_item->next = cur->next;
                cur->next = new_ll_item;
            }
            break;
        case 2:
            cout << "All items added and sorted successfully!" << endl;
            return head;
        default:
            cout << "Invalid choice!" << endl;
            break;
        }
    }
}

// Функція для виведення списку
void printList(LL head) {
    LL cur = head;
    while (cur) {
        std::cout << cur->info << " ";
        cur = cur->next;
    }
    std::cout << std::endl;
}

int main() {
    const char* data = "banana cherry apple date";

    // Формування та сортування списку
    LL head = forming_sorted_LL();

    // Виведення списку
    printList(head);

    while (head) {
        LL temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}