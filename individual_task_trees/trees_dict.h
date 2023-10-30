#ifndef INDIVIDUAL_TASK_TREES_TREES_DICT_H
#define INDIVIDUAL_TASK_TREES_TREES_DICT_H

struct dictionaryTree {
    dictionaryTree* left;
    dictionaryTree* right;
    char* eng_word;
    char* ukr_word;
    int counter;
};

typedef dictionaryTree* DT;

const char* getEng(const char info[]);
const char* getUkr(const char info[]);
DT insert(DT root, const char* eng, const char* ukr);
DT dataToTreeTxt(char* filename);
void inOrderTraversal(DT root);
DT retrieveWord(DT root, const char* info);
DT updateWord(DT root, const char* info, const char* newInfo);
DT deleteWord(DT root, const char* info);

#endif //INDIVIDUAL_TASK_TREES_TREES_DICT_H
