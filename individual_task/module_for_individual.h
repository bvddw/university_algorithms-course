#ifndef MODULE_FOR_INDIVIDUAL_H
#define MODULE_FOR_INDIVIDUAL_H

struct subjectsLL {
    const char* subject;
    int mark;
    subjectsLL* next;
};

struct linked_list {
    const char* student_name;
    subjectsLL* subject;
    linked_list* next;
};

// typedefs for better using
typedef subjectsLL* subLL;
typedef linked_list* LL;


// file management and tools
const char* getName(const char info[]); // get fullname from row in file
int getMark(const char info[]); // get mark from row in file
void getFileData(const char filename[], LL &head, const char* subject_name); // get all data from one file and forming LL
const char* creatingFilenames(LL cur); // creating name for diploma file from fullname
void dataToDiploma(LL student); // write data to diploma
void creatingDiplomas(LL head); // creating diplomas, using tools funcs
void updateFilesData(LL head); // update files after CRUD

// student`s C(create)R(retrieve)U(update)D(delete)
void createStudent(LL &head); // create new
void getStudentInfo(LL head); // get one
void dataToConsole(LL head); // get all
void updateStudent(LL &head); // update
void deleteStudent(LL &head); // delete

// tools
double averageMark(LL student); // get average mark for chosen student
void infoAboutSubject(LL head); // get info about one subject - here additional menu
void deleteLL(LL head); // cleaning data after program

#endif