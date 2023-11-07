//
// Created by Arsenii on 11/7/2023.
//

#ifndef INDIVIDUAL_TASK_CUSTOM_TYPE_HEADER_H
#define INDIVIDUAL_TASK_CUSTOM_TYPE_HEADER_H

class Node {
public:
    int value;
    int priority;
    Node* prev;
    Node* next;

    Node(int val, int prior) : value(val), priority(prior), prev(nullptr), next(nullptr) {}
};

class PriorityQueue {
private:
    Node* front;

public:
    PriorityQueue();

    void insert(int value, int priority);
    int getMinPriority();
    bool isEmpty();
};

#endif //INDIVIDUAL_TASK_CUSTOM_TYPE_HEADER_H
