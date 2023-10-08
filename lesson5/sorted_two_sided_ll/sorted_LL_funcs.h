#include <fstream>
#ifndef SORTED_LL_FUNCS_H
#define SORTED_LL_FUNCS_H

struct linked_list {
    const char* info;
    linked_list* next;
    linked_list* prev;
};

typedef linked_list* LL;


void sortedLLforming(LL& start, LL& end); // forming Linked List, sorting whwile forming
bool isLLSymmetrical(LL start, LL end);
void removeItem(LL &start); // remove all items with chosen info
void addItem(LL &start); // add item, saving ordering
int countItems(LL start); // count items in LL
void LLprimaryOutput(LL start); // output in order from start to end
void LLreverseOutput(LL end); // output in order from end to start
void LLdelete(LL start, LL end); // clearing memory

#endif