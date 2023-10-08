#include <iostream>
#include <fstream>
#include <cstring>
#include "module_for_individual.h"

using namespace std;

const char* getName(const char info[]) {
    int index = 0;
    int spaces_counter = 0;
    while (spaces_counter < 2 && info[index] != '\0') {
        if (info[index] == ' ') {
            spaces_counter++;
        }
        if (spaces_counter < 2) {
            index++;
        }
    }

    char* surname = new char[index + 1];

    for (int i = 0; i < index; i++) {
        surname[i] = info[i];
    }

    surname[index] = '\0';

    return surname;
}

int getMark(const char info[]) {
    int index = strlen(info) - 1;

    // Find the last space in the string
    while (index >= 0 && info[index] != ' ') {
        index--;
    }

    // If no space is found, return 0 as an error value
    if (index < 0) {
        return 0;
    }

    // Extract the mark as a substring from the last space to the end
    const char* markStr = &info[index + 1];

    // Convert markStr to an integer and return it
    return atoi(markStr);
}

void getFileData(const char filename[], LL &head, const char* subject_name) {
    ifstream input_file(filename);

    if (!input_file.is_open()) {
        cerr << "Error while opening file." << endl;
    }

    const int length_line = 1000;
    char line[length_line];

    LL cur;
    LL prev;
    LL student;
    subLL subjects_list;
    subLL new_subject;
    const char* name;
    int mark;

    while(input_file.getline(line, length_line)) {
        name = getName(line);
        mark = getMark(line);
        cur = head->next;
        prev = head;

        new_subject = new subjectsLL;
        new_subject->subject = subject_name;
        new_subject->mark = mark;
        new_subject->next = nullptr;
        if (!head->next || strcmp(name, cur->student_name) < 0) {
            student = new linked_list;
            student->student_name = name;
            student->subject = new_subject;
            student->next = head->next;
            head->next = student;

            continue;
        }
        while (cur) {
            if (strcmp(name, cur->student_name) == 0) {
                subjects_list = cur->subject;
                while (subjects_list->next) {
                    subjects_list = subjects_list->next;
                }
                subjects_list->next = new_subject;
                break;
            } 
            if (strcmp(name, cur->student_name) < 0) {
                student = new linked_list;
                student->student_name = name;
                student->subject = new_subject;
                student->next = cur;
                prev->next = student;                    
                break;
            }
            cur = cur->next;
            prev = prev->next;
        }
        if (!cur) {
            student = new linked_list;
            student->student_name = name;
            student->subject = new_subject;
            student->next = nullptr;
            prev->next = student;
        }
    }

    input_file.close();
}

double averageMark(LL student) {
    subLL subject = student->subject;
    double avarage_mark = 0;
    double count = 0;
    while (subject) {
        avarage_mark += subject->mark;
        count++;
        subject = subject->next;
    }
    return (cout) ? (avarage_mark / count) : 0;
}

void dataToConsole(LL head) {
    LL cur = head->next;
    subLL subject;
    while (cur) {
        cout << "Student: " << cur->student_name << endl;
        subject = cur->subject;
        while (subject) {
            cout << "\t" << subject->subject << " - " << subject->mark << endl;
            subject = subject->next;
        }
        cout << "\tAvarage mark: " << averageMark(cur);
        cout << endl;
        cur = cur->next;
    }
}

const char* creatingFilenames(LL cur) {
    const char folder_name[] = "diplomas/";
    const int len = strlen(cur->student_name) + strlen(folder_name) + 4 + 1; // +1 for null-terminator
    char* filename = new char[len];
    int index = 0;
    const char* filetype = ".txt"; // Use const char* for the file extension

    // Copy the folder name to the filename
    for (int i = 0; i < strlen(folder_name); i++) {
        filename[index++] = folder_name[i];
    }

    // Create the filename by replacing spaces with underscores and appending the file extension
    for (int i = 0; i < strlen(cur->student_name); i++) {
        if (cur->student_name[i] == ' ') {
            filename[index++] = '_';
        } else {
            filename[index++] = cur->student_name[i];
        }
    }

    // Append the file extension
    for (int i = 0; i < strlen(filetype); i++) {
        filename[index++] = filetype[i];
    }

    // Null-terminate the filename
    filename[index] = '\0';

    return filename;
}

void dataToDiploma(LL student) {
    const char* filename = creatingFilenames(student);
    ofstream output_file(filename); // Open the output file

    // Check if the file is opened successfully
    if (!output_file.is_open()) {
        cerr << "Error opening the file." << endl;
        return; // Exit the function if the file cannot be opened
    }
    subLL subject;
    output_file << "Student: " << student->student_name << endl;
    subject = student->subject;
    while (subject) {
        output_file << "\t" << subject->subject << " - " << subject->mark << endl;
        subject = subject->next;
    }
    output_file << "\tAverage mark: " << averageMark(student) << endl;
    output_file << endl;

    output_file.close(); // Close the output file
}

void infoAboutSubject(LL head) {
    int choice;
    bool flag = true;

    while (flag) {
        cout << "Choose the subject: " << endl;
        cout << "1. Math" << endl;
        cout << "2. History" << endl;
        cout << "3. English" << endl;
        cout << "4. Programming" << endl;
        cout << "5. Exit to main menu" << endl;
        cin >> choice;

        const char* subject_name;

        switch (choice) {
            case 1:
                subject_name = "Math";
                break;
            case 2:
                subject_name = "History";
                break;
            case 3:
                subject_name = "English";
                break;
            case 4:
                subject_name = "Programming";
                break;
            case 5:
                return;
            default:
                cout << "Invalid choice" << endl;
                continue; // Repeat the loop for an invalid choice
        }
        cout << subject_name << endl;
        LL cur = head->next;
        bool found = false; // Flag to check if any students were found for the subject
        LL best_student;
        int best_mark = -1;
        while (cur) {
            subLL subject = cur->subject;
            
            while (subject) {
                if (strcmp(subject->subject, subject_name) == 0) {
                    // Display student information for the selected subject
                    cout << "Student: " << cur->student_name << " has mark " << subject->mark << " in " << subject_name << endl;
                    if (subject->mark > best_mark) {
                        best_mark = subject->mark;
                        best_student = cur;
                    }
                    found = true; // Set the found flag to true
                    break; // Exit the subject loop when a match is found
                }
                subject = subject->next;
            }
            cur = cur->next;
        }

        if (!found) {
            cout << "No students found for " << subject_name << endl;
        } else {
            cout << "Best student is " << best_student->student_name << endl;
        }
    }
}

void getStudentInfo(LL head) {
    char surname[200];
    char name[200];
    cout << "Enter student`s surname: ";
    cin >> surname;
    cout << "Enter student`s name: ";
    cin >> name;
    char* fullname = new char[strlen(surname) + 1 + strlen(name) + 1];
    int index = 0;
    for (int i = 0; i < strlen(surname); i++) {
        fullname[index++] = surname[i];
    }
    fullname[index++] = ' ';
    for (int i = 0; i < strlen(name); i++) {
        fullname[index++] = name[i];
    }
    fullname[index] = '\0';

    LL cur = head->next;
    while (cur && strcmp(fullname, cur->student_name)) {
        cur = cur->next;
    }
    if (!cur) {
        cout << "There no student with such surnme & name." << endl;
        return;
    }
    cout << "Student: " << cur->student_name << endl;
    subLL subject = cur->subject;
    while (subject) {
        cout << "\t" << subject->subject << " - " << subject->mark << endl;
        subject = subject->next;
    }
    cout << "\tAvarage mark: " << averageMark(cur);
    cout << endl;
    cur = cur->next;
}

void createStudent(LL &head) {
    char surname[200];
    char name[200];
    cout << "Enter student`s surname: ";
    cin >> surname;
    cout << "Enter student`s name: ";
    cin >> name;
    char* fullname = new char[strlen(surname) + 1 + strlen(name) + 1];
    int index = 0;
    for (int i = 0; i < strlen(surname); i++) {
        fullname[index++] = surname[i];
    }
    fullname[index++] = ' ';
    for (int i = 0; i < strlen(name); i++) {
        fullname[index++] = name[i];
    }
    fullname[index] = '\0';

    LL cur = head->next;
    while (cur) {
        if (!strcmp(cur->student_name, fullname)) {
            cout << "This student already exist." << endl;
            return;
        }
        cur = cur->next;
    }
    LL new_student = new linked_list;
    new_student->next = nullptr;
    new_student->subject = nullptr;
    new_student->student_name = fullname;
    bool flag = true;
    int choice;
    subLL subject;
    int mark;

    while (flag) {
        cout << "Have this student visiting English?" << endl;
        cout << "1. Yes" << endl;
        cout << "2. No" << endl;
        cin >> choice;
        switch (choice) {
        case 1:
            cout << "Enter his|her mark in english: ";
            cin >> mark;
            if (mark > 100) {
                mark = 100;
            }
            if (mark < 0) {
                mark = 0;
            }
            subject = new subjectsLL;
            subject->mark = mark;
            subject->next = nullptr;
            subject->subject = "English";
            new_student->subject = subject;
            flag = false;
            break;
        case 2:
            flag = false;
            break;
        default:
            cout << "Invalid choice." << endl;
            break;
        }
    }
    subLL cur_sub;
    subLL top;
    flag = true;
    while (flag) {
        cout << "Have this student visiting History?" << endl;
        cout << "1. Yes" << endl;
        cout << "2. No" << endl;
        cin >> choice;
        switch (choice) {
        case 1:
            cout << "Enter his|her mark in history: ";
            cin >> mark;
            if (mark > 100) {
                mark = 100;
            }
            if (mark < 0) {
                mark = 0;
            }
            subject = new subjectsLL;
            subject->mark = mark;
            subject->next = nullptr;
            subject->subject = "History";
            if (!new_student->subject) {
                new_student->subject = subject;
            } else {
                cur_sub = new_student->subject;
                while (cur_sub->next) {
                    cur_sub = cur_sub->next;
                }
                cur_sub->next = subject;
            }
            flag = false;
            break;
        case 2:
            flag = false;
            break;
        default:
            cout << "Invalid choice." << endl;
            break;
        }
    }
    flag = true;
    while (flag) {
        cout << "Have this student visiting Math?" << endl;
        cout << "1. Yes" << endl;
        cout << "2. No" << endl;
        cin >> choice;
        switch (choice) {
        case 1:
            cout << "Enter his|her mark in math: ";
            cin >> mark;
            if (mark > 100) {
                mark = 100;
            }
            if (mark < 0) {
                mark = 0;
            }
            subject = new subjectsLL;
            subject->mark = mark;
            subject->next = nullptr;
            subject->subject = "Math";
            if (!new_student->subject) {
                new_student->subject = subject;
            } else {
                cur_sub = new_student->subject;
                while (cur_sub->next) {
                    cur_sub = cur_sub->next;
                }
                cur_sub->next = subject;
            }
            flag = false;
            break;
        case 2:
            flag = false;
            break;
        default:
            cout << "Invalid choice." << endl;
            break;
        }
    }
    flag = true;
    while (flag) {
        cout << "Have this student visiting Programming?" << endl;
        cout << "1. Yes" << endl;
        cout << "2. No" << endl;
        cin >> choice;
        switch (choice) {
        case 1:
            cout << "Enter his|her mark in programming: ";
            cin >> mark;
            if (mark > 100) {
                mark = 100;
            }
            if (mark < 0) {
                mark = 0;
            }
            subject = new subjectsLL;
            subject->mark = mark;
            subject->next = nullptr;
            subject->subject = "Programming";
            if (!new_student->subject) {
                new_student->subject = subject;
            } else {
                cur_sub = new_student->subject;
                while (cur_sub->next) {
                    cur_sub = cur_sub->next;
                }
                cur_sub->next = subject;
            }
            flag = false;
            break;
        case 2:
            flag = false;
            break;
        default:
            cout << "Invalid choice." << endl;
            break;
        }
    }
    cur = head->next;
    if (strcmp(new_student->student_name, cur->student_name) < 0) {
        new_student->next = cur;
        head->next = new_student;
        return;
    }
    LL prev = cur;
    cur = cur->next;
    while (cur) {
        if (strcmp(new_student->student_name, cur->student_name) < 0) {
            new_student->next = cur;
            prev->next = new_student;
            updateFilesData(head);
            return;
        }
        cur = cur->next;
        prev = prev->next;
    }
    if (!cur) {
        prev->next = new_student;
        updateFilesData(head);
        return;
    }
}

void updateStudent(LL &head) {
    char surname[200];
    char name[200];
    cout << "Enter surname of student, which data you want to update: ";
    cin >> surname;
    cout << "Enter name of student, which data you want to update: ";
    cin >> name;
    char* fullname = new char[strlen(surname) + 1 + strlen(name) + 1];
    int index = 0;
    for (int i = 0; i < strlen(surname); i++) {
        fullname[index++] = surname[i];
    }
    fullname[index++] = ' ';
    for (int i = 0; i < strlen(name); i++) {
        fullname[index++] = name[i];
    }
    fullname[index] = '\0';

    LL cur = head->next;
    while (cur && strcmp(fullname, cur->student_name)) {
        cur = cur->next;
    }
    if (!cur) {
        cout << "There no student with such surnme & name." << endl;
        return;
    }

    LL student_to_update = cur;
    cur = head->next;
    while (cur->next) {
        if (strcmp(cur->next->student_name, student_to_update->student_name)) {
            cur->next = cur->next->next;
            break;
        }
    }
    bool flag = true;
    int choice;
    int subject_choice;
    char* subject_to_update;
    subLL updated_subject;
    while (flag) {
        cout << "Chose action:" << endl;
        cout << "1. Change surname & name" << endl;
        cout << "2. Change or add mark" << endl;
        cout << "3. Save changes and exit" << endl;

        cin >> choice;
        switch (choice){
        case 1:
            char surname[200];
            char name[200];
            cout << "Enter new surname: ";
            cin >> surname;
            cout << "Enter new name: ";
            cin >> name;
            fullname = new char[strlen(surname) + 1 + strlen(name) + 1];
            index = 0;
            for (int i = 0; i < strlen(surname); i++) {
                fullname[index++] = surname[i];
            }
            fullname[index++] = ' ';
            for (int i = 0; i < strlen(name); i++) {
                fullname[index++] = name[i];
            }
            fullname[index] = '\0';
            student_to_update->student_name = fullname;
            break;
        case 2:
            cout << "Pick subject:" << endl;
            cout << "1. English" << endl;
            cout << "2. History" << endl;
            cout << "3. Math" << endl;
            cout << "4. Programming" << endl;
            cin >> subject_choice;
            if (subject_choice == 1) {
                subject_to_update = "English";
            } else if (subject_choice == 2) {
                subject_to_update = "History";
            } else if (subject_choice == 3) {
                subject_to_update = "Math";
            } else if (subject_choice == 4) {
                subject_to_update = "Programming";
            } else {
                cout << endl << "Invalid choice" << endl;
            }
            if (0 < subject_choice && subject_choice < 5) {
                updated_subject = new subjectsLL;
                updated_subject->next = nullptr;
                updated_subject->subject = subject_to_update;
                cout << "Enter student`s new mark in subject " << subject_to_update << ": ";
                cin >> updated_subject->mark;
                subLL subject = student_to_update->subject;
                if (!strcmp(updated_subject->subject, subject->subject)) {
                    updated_subject->next = subject->next;
                    delete subject;
                    student_to_update->subject = updated_subject;
                } else if (strcmp(updated_subject->subject, subject->subject) < 0) {
                    updated_subject->next = subject;
                    student_to_update->subject = updated_subject;
                } else {
                    while (subject->next) {
                        if (!strcmp(subject->next->subject, updated_subject->subject)) {
                            subLL temp = subject->next;
                            updated_subject->next = subject->next->next;
                            subject->next = updated_subject;
                            delete temp;
                            break;
                        }
                        if (strcmp(updated_subject->subject, subject->next->subject) < 0) {
                            updated_subject->next = subject->next;
                            subject->next = updated_subject;
                            break;
                        }
                        subject = subject->next;
                    }
                    if (!subject->next) {
                        subject->next = updated_subject;
                    }
                }
            }
            break;
        case 3:
            cout << "Data updated successfully" << endl;
            flag = false;
            updateFilesData(head);
            return;
        default:
            cout << "Invalid choice." << endl;
            break;
        }

    }
}

void deleteStudent(LL &head) {
    char surname[200];
    char name[200];
    cout << "Enter surname of student, which data you want to update: ";
    cin >> surname;
    cout << "Enter name of student, which data you want to update: ";
    cin >> name;
    char* fullname = new char[strlen(surname) + 1 + strlen(name) + 1];
    int index = 0;
    for (int i = 0; i < strlen(surname); i++) {
        fullname[index++] = surname[i];
    }
    fullname[index++] = ' ';
    for (int i = 0; i < strlen(name); i++) {
        fullname[index++] = name[i];
    }
    fullname[index] = '\0';

    LL cur = head->next;
    while (cur && strcmp(fullname, cur->student_name)) {
        cur = cur->next;
    }
    if (!cur) {
        cout << "There no student with such surname & name." << endl;
        return;
    }
    cur = head;
    while (cur->next) {
        if (!strcmp(cur->next->student_name, fullname)) {
            LL temp = cur->next;
            cur->next = cur->next->next;
            delete temp;
            updateFilesData(head);
            return;
        }
        cur = cur->next;
    }
    updateFilesData(head);
}

void updateFilesData(LL head) {
    const char* english_filename = "english.txt";
    ofstream english_output_file(english_filename);

    if (!english_output_file.is_open()) {
        cerr << "Error opening the file." << endl;
        return; // Exit the function if the file cannot be opened
    }

    LL cur;
    cur = head->next;
    while(cur) {
        subLL subject = cur->subject;
        while (subject) {
            if (!strcmp(subject->subject, "English")) {
                english_output_file << cur->student_name << " - " << subject->mark << endl;
                break;
            }
            subject = subject->next;
        }
        cur = cur->next;
    }
    english_output_file.close();


    const char* history_filename = "history.txt";
    ofstream history_output_file(history_filename);

    if (!history_output_file.is_open()) {
        cerr << "Error opening the file." << endl;
        return; // Exit the function if the file cannot be opened
    }

    cur = head->next;
    while(cur) {
        subLL subject = cur->subject;
        while (subject) {
            if (!strcmp(subject->subject, "History")) {
                history_output_file << cur->student_name << " - " << subject->mark << endl;
                break;
            }
            subject = subject->next;
        }
        cur = cur->next;
    }
    history_output_file.close();


    const char* math_filename = "math.txt";
    ofstream math_output_file(math_filename);

    if (!math_output_file.is_open()) {
        cerr << "Error opening the file." << endl;
        return; // Exit the function if the file cannot be opened
    }

    cur = head->next;
    while(cur) {
        subLL subject = cur->subject;
        while (subject) {
            if (!strcmp(subject->subject, "Math")) {
                math_output_file << cur->student_name << " - " << subject->mark << endl;
                break;
            }
            subject = subject->next;
        }
        cur = cur->next;
    }
    math_output_file.close();


    const char* programming_filename = "programming.txt";
    ofstream programming_output_file(programming_filename);

    if (!programming_output_file.is_open()) {
        cerr << "Error opening the file." << endl;
        return; // Exit the function if the file cannot be opened
    }

    cur = head->next;
    while(cur) {
        subLL subject = cur->subject;
        while (subject) {
            if (!strcmp(subject->subject, "Programming")) {
                programming_output_file << cur->student_name << " - " << subject->mark << endl;
                break;
            }
            subject = subject->next;
        }
        cur = cur->next;
    }
    programming_output_file.close();
}

void creatingDiplomas(LL head) {
    LL cur = head->next;
    while (cur) {
        dataToDiploma(cur);
        cur = cur->next;
    }
}

void deleteLL(LL head) {
    while (head) {
        LL temp = head;
        subLL subject = head->subject;
        while (subject) {
            subLL temp_sub = subject;
            subject = subject->next;
            delete temp_sub;
        }
        head = head->next;
        delete temp;
    }
}