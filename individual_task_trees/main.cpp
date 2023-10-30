#include <iostream>
#include "trees_dict.h"
#include "funcs.cpp"

using namespace std;


int main() {
    DT root = dataToTreeTxt("data.txt");
    DT checkWord;
    char* checkEngInfo;
    char* newUkrWord;
    bool flag = true;
    bool subFlag = true;
    int choice;
    int subChoice;


    while (flag) {
        cout << "MENU" << endl;
        cout << "1. Check list of all words" << endl;
        cout << "2. Check word by its info" << endl;
        cout << "3. Add new word" << endl;
        cout << "4. Update translate" << endl;
        cout << "5. Delete word by its info" << endl;
        cout << "6. Get the most popular word" << endl;
        cout << "7. Rebuilt dictionary" << endl;
        cout << "8. Finish program" << endl;
        cout << "Option: ";
        cin >> choice;

        switch (choice) {
            case 1:
                inOrderTraversal(root);
                break;
            case 2:
                subFlag = true;
                cout << "Enter an word, which translate you want to check: ";
                checkEngInfo = new char;
                cin >> checkEngInfo;
                checkWord = retrieveWord(root, checkEngInfo);
                if (checkWord) {
                    cout << checkWord->eng_word << " -- " << checkWord->ukr_word << " -- " << checkWord->counter << endl;
                } else {
                    cout << "Unfortunately we do not have this word in our dictionary." << endl;
                    while (subFlag) {
                        cout << "Do you want to provide a translate?" << endl;
                        cout << "1. Yes\n2.No\nChoice: ";
                        cin >> subChoice;

                        switch (subChoice) {
                            case 1:
                                newUkrWord = new char;
                                cout << "Enter, please a translate of word " << checkEngInfo << ": ";
                                cin >> newUkrWord;
                                insert(root, checkEngInfo, newUkrWord);
                                cout << "Word was added successfully, thank you for coworking!";
                                subFlag = false;
                                break;
                            case 2:
                                subFlag = false;
                                break;
                            default:
                                cout << "Invalid choice" << endl;
                                break;
                        }
                    }
                }
                break;
            case 3:
                cout << "Enter english word, which you want to add: ";
                checkEngInfo = new char;
                cin >> checkEngInfo;
                checkWord = retrieveWord(root, checkEngInfo);
                if (checkWord) {
                    cout << "We already have this word in dictionary." << endl;
                } else {
                    newUkrWord = new char;
                    cout << "Enter, please a translate of word " << checkEngInfo << ": ";
                    cin >> newUkrWord;
                    insert(root, checkEngInfo, newUkrWord);
                    cout << "Word was added successfully, thank you for coworking!" << endl;
                }
                break;
            case 4:
                cout << "Enter english word, which you want to update: ";
                checkEngInfo = new char;
                cin >> checkEngInfo;
                checkWord = retrieveWord(root, checkEngInfo);
                if (!checkWord) {
                    cout << "We do not have this word in dictionary." << endl;
                } else {
                    newUkrWord = new char;
                    cout << "Enter, please a translate of word " << checkEngInfo << ": ";
                    cin >> newUkrWord;
                    updateWord(root, checkEngInfo, newUkrWord);
                    cout << "Word was added successfully, thank you for coworking!" << endl;
                }
                break;
            case 5:
                cout << "Enter english word, which you want to delete: ";
                checkEngInfo = new char;
                cin >> checkEngInfo;
                deleteWord(root, checkEngInfo);
                cout << "Operation completed." << endl;
                break;
            case 6:
                cout << "The most popular word is: ";
                checkWord = findMaxCounter(root, root);
                cout << checkWord->eng_word << " with translate - " << checkWord->ukr_word << endl;
                cout << "Visitors have already opened this word " << checkWord->counter << " times!" << endl;
                break;
            case 7:
                cout << "Original dictionary:" << endl;
                preOrderTraversal(root);
                root = rebuiltTree(root);
                cout << "New dictionary:" << endl;
                preOrderTraversal(root);
                break;
            case 8:
                cout << "Program finished.";
                flag = false;
                break;
            default:
                cout << "Invalid choice" << endl;
                break;
        }
    }
    delete root;

    return 0;
}
