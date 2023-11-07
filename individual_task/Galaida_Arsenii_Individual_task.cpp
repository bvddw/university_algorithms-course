#include <iostream>
#include "module_for_individual.h"
#include "module_for_individual.cpp"

using namespace std;


int main() {
    LL head = new linked_list; // Initialize the head node properly
    head->student_name = nullptr;
    head->next = nullptr;
    head->subject = nullptr;
    getFileData("english.txt", head, "English");
    getFileData("history.txt", head, "History");
    getFileData("math.txt", head, "Math");
    getFileData("programming.txt", head, "Programming");

    dataToConsole(head);

    bool flag = true;
    int choice;
    while (flag) {
        cout << endl << "MENU:" << endl;
        cout << "1. Add new student" << endl;
        cout << "2. Update student data" << endl;
        cout << "3. Delete student" << endl;
        cout << "4. Get student info" << endl;
        cout << "5. Get info about subject" << endl;
        cout << "6. Get data about all students" << endl;
        cout << "7. Create diploma files and finish program" << endl;
        cin >> choice;
        switch (choice) {
        case 1:
            createStudent(head);
            break;
        case 2:
            updateStudent(head);
            break;
        case 3:
            deleteStudent(head);
            break;
        case 4:
            getStudentInfo(head);
            break;
        case 5:
            infoAboutSubject(head);
            break;
        case 6:
            cout << endl;
            dataToConsole(head);
            break;
        case 7:
            creatingDiplomas(head);
            cout << "Dimplomas successfully created!\nThank you for using our program!";
            flag = false;
            deleteLL(head);
            break;
        default:
            cout << "Invalid choice";
            break;
        }
    }
    return 0;
}