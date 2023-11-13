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
    PriorityQueue(); // constructor

    void insert(int value, int priority = 0); // add new element with its priority
    int getMinPriority(); // get value with min priority and remove this item from queue
    bool isEmpty(); // check is queue is empty
    void printQueue(); // output the queue
    void remove(int value); // remove item by its value
    void clear(); // clear the queue
    int size(); // check size of queue
    int getPriority(int value); // get priority by value
};

#endif //INDIVIDUAL_TASK_CUSTOM_TYPE_HEADER_H
