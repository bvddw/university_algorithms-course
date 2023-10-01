#include <iostream>
#include <cstring>

struct linked_list {
    char* info;
    linked_list* next;
};

using namespace std;
typedef linked_list* LL;


LL forming_sorted_LL(); // Функція для формування та сортування зв'язного списку
void outputLL(LL head); // Функція для виведення списку
void addElementToLL(LL& head); // додавання елемента, зберігаючи порядок сортування
void removeElementFromLL(LL& head, const char* info); // видалення елемента, зебрігаючи порядок сортування
int countElementsRecursively(LL head); // функція для рахування елементів (рекурсивно)


LL forming_sorted_LL() {
    int choice;
    char* data = new char[100];
    LL new_ll_item;
    LL cur;

    cout << "Enter info: ";
    cin >> data;

    // Створюємо початковий вузол списку
    LL head = new linked_list;
    head->info = data;
    strcpy(head->info, data);
    head->next = nullptr;

    while (true) { // додаємо вузли, поки цього хоче користувач
        cout << "Do you want to add more new info?\n1 - YES\n2 - NO\n";
        cin >> choice;
        switch (choice) {
        case 1: // додаємо вузел, заповнюємо інформацією
            cout << "Enter new data: ";
            data = new char[100];
            cin >> data;
            new_ll_item = new linked_list;
            new_ll_item->info = data;
            strcpy(new_ll_item->info, data);
            new_ll_item->next = nullptr;

            cur = head; 
            // шукаємо місце для нового вузла, і вставляємо його туди
            if (strcmp(head->info, data) > 0) { // якщо він менший за голову - новий вузел тепер голова списку
                new_ll_item->next = head;
                head = new_ll_item;
            } else { // якщо голова незмінна, шукаємо місце і вставляємо туди
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

void outputLL(LL head) {
    LL cur = head;
    while (cur) {
        std::cout << cur->info << " ";
        cur = cur->next;
    }
    std::cout << std::endl;
}

void addElementToLL(LL& head) {
    char* new_info = new char[100];
    cout << "Enter info to add: ";
    cin >> new_info;
    LL new_item;

    if (strcmp(head->info, new_info) > 0) {
        new_item = new linked_list;
        new_item->info = new_info;
        new_item->next = head;
        head = new_item;
        return;
    }
    LL cur = head->next;
    LL prev = head;
    while (cur) {
        if (strcmp(cur->info, new_info) > 0) {
            new_item = new linked_list;
            new_item->info = new_info;
            new_item->next = cur;
            prev->next = new_item;
            return;
        }
        cur = cur->next;
        prev = prev->next;
    }
    new_item = new linked_list;
    new_item->info = new_info;
    new_item->next = nullptr;
    prev->next = new_item;
    return;
}

void removeElementFromLL(LL& head, const char* info) {
    if (strcmp(head->info, info ) == 0) {
        LL temp = head;
        head = head->next;
        delete[] temp->info;
        delete temp;
        return;
    }
    LL cur = head->next;
    LL prev = head;
    while (cur) {
        if (strcmp(cur->info, info) == 0) {
            prev->next = cur->next;
            delete[] cur->info;
            delete cur;
            cout << "Element with info " << info << " removed successfully!";
            return;
        }
        cur = cur->next;
        prev = prev->next;
    }
    cout << "No elements with info " << info << '!' << endl;
}

int countElementsRecursively(LL head) {
    if (!head) {
        return 0;
    }
    if (!head->next) {
        return 1;
    }
    return 1 + countElementsRecursively(head->next);
}

int main() {
    // Формування та сортування списку
    LL head = nullptr;
    bool flag = true;
    int number_of_elements = 0;
    int choice;
    char* info_to_remove;
    while (flag) {
        number_of_elements = countElementsRecursively(head);
        cout << endl << "MENU:" << endl;
        cout << "1. Forming sorted Linked List" << endl;
        if (number_of_elements > 0) {
            cout << "2. Add element to the Linked List, saving ordering" << endl;
            cout << "3. Remove element from the Linked Listm saving ordering" << endl;
            cout << "4. Output Linked List" << endl;
        } else {
            cout << "2." << endl;
            cout << "3." << endl;
            cout << "4." << endl;
        }
        cout << "5. Exit program" << endl;
        cin >> choice;
        if (!number_of_elements && choice > 1 && choice < 5) {
            choice = 6;
        }
        switch (choice) {
        case 1:
            head = forming_sorted_LL();
            break;
        case 2:
            addElementToLL(head);
            break;
        case 3:
            info_to_remove = new char[100];
            cout << "Enter info to remove: ";
            cin >> info_to_remove;
            removeElementFromLL(head, info_to_remove);
            break;
        case 4:
            outputLL(head);
            break;
        case 5:
            cout << "Program finished successfully!";
            flag = false;
            break;
        default:
            cout << "Invalid choice." << endl;
            break;
        }
    }

    while (head) {
        LL temp = head;
        head = head->next;
        delete[] temp->info;
        delete temp;
    }

    return 0;
}