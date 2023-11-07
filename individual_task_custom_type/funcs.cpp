#include "header.h"
#include <iostream>

using namespace std;

PriorityQueue::PriorityQueue() : front(nullptr) {}

void PriorityQueue::insert(int value, int priority) {
    Node* newNode = new Node(value, priority);
    if (!front || priority < front->priority) {
        newNode->next = front;
        if (front)
            front->prev = newNode;
        front = newNode;
    } else {
        Node* current = front;
        while (current->next && current->next->priority <= priority) {
            current = current->next;
        }
        newNode->next = current->next;
        if (current->next)
            current->next->prev = newNode;
        current->next = newNode;
        newNode->prev = current;
    }
}

int PriorityQueue::getMinPriority() {
    if (!front) {
        throw std::logic_error("Priority Queue is empty");
    }
    int minPriorityValue = front->value;
    Node* temp = front;
    front = front->next;
    if (front)
        front->prev = nullptr;
    delete temp;
    return minPriorityValue;
}

bool PriorityQueue::isEmpty() {
    return front == nullptr;
}