#include <fstream>
#ifndef TWO_SIDED_LL_FUNCS_H
#define TWO_SIDED_LL_FUNCS_H

struct linked_list {
    const char* info;
    linked_list* next;
    linked_list* prev;
};

typedef linked_list* LL;



void LLforming(LL& start, LL& end); // forming two-sided LL
void removeItem(LL &start); // remove all items from LL
void addItemAfter(LL &start, LL &end); // add element after first item with chosen info or in the end
void addItemBefore(LL &start, LL &end); // ad element before last item with chosen info or in the start
bool isLLSymmetrical(LL start, LL end); // check is LL symmetrical
int countItems(LL head); // count item in LL
void LLprimaryOutput(LL start); // output from start to end
void LLreverseOutput(LL end); // output from end to start
void LLdelete(LL start, LL end); // clearing memory

#endif