#ifndef INDIVIDUAL_TASK_TREES_TREES_DICT_H
#define INDIVIDUAL_TASK_TREES_TREES_DICT_H

/*
Англо-український словник побудований у вигляді двійкового дерева. Кожна компонента містить англійське слово,
 відповідне йому українське слово та лічильник кількості звернень до цієї компоненти. Початкове дерево формується
 у порядку англійського алфавіту. У процесі експлуатації словника при кожному зверненні до компонента до лічильника
 звернень додається одиниця. Написати програму, яка:
• Забезпечує початкове введення словника з конкретними значеннями лічильників звернень;
• Формує нове представлення словника у вигляді двійкового дерева за таким алгоритмом:
a) у старому словнику шукається компонента із найбільшим значенням лічильника звернень;
b) знайдена компонента заноситься до нового словника та видаляється зі старого;
c) перехід до п. а) до вичерпання вихідного словника.
• Виводить вихідний та новий словник.
*/

struct dictionaryTree {
    dictionaryTree* left;
    dictionaryTree* right;
    char* eng_word;
    char* ukr_word;
    int counter;
};
typedef dictionaryTree* DT;

int NUMBER_OF_WORDS = 0;
int TOTAL_VIEWS = 0;

const char* getEng(const char info[]);
const char* getUkr(const char info[]);
DT insert(DT root, const char* eng, const char* ukr);
DT dataToTreeTxt(char* filename);
void inOrderTraversal(DT root);
void preOrderTraversal(DT root);
DT retrieveWord(DT root, const char* info);
DT updateWord(DT root, const char* info, const char* newInfo);
DT deleteWord(DT root, const char* info);
DT findMaxCounter(DT root, DT mostCount);
DT insertNode(DT root, DT newNode);
DT rebuiltTree(DT root);

#endif //INDIVIDUAL_TASK_TREES_TREES_DICT_H
