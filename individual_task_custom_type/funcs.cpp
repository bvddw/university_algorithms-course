#include "header.h"
#include <iostream>

using namespace std;

PriorityQueue::PriorityQueue() : front(nullptr) {}

void PriorityQueue::insert(int value, int priority) {
    if (priority < 0) {
        priority = 0;
    }
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

void PriorityQueue::printQueue() {
    Node* current = front;
    cout << endl;
    if (!current) {
        cout << "Queue is empty." << endl;
    }
    while (current != nullptr) {
        cout << "Value: " << current->value << ", Priority: " << current->priority << endl;
        current = current->next;
    }
}

void PriorityQueue::remove(int value) {
    Node* current = front;
    while (current != nullptr) {
        if (current->value == value) {
            if (current->prev != nullptr) {
                current->prev->next = current->next;
            } else {
                front = current->next;
            }

            if (current->next != nullptr) {
                current->next->prev = current->prev;
            }

            delete current;
            return;
        }

        current = current->next;
    }
}

void PriorityQueue::clear() {
    while (front != nullptr) {
        Node* temp = front;
        front = front->next;
        delete temp;
    }
}

int PriorityQueue::size() {
    int count = 0;
    Node* current = front;
    while (current != nullptr) {
        count++;
        current = current->next;
    }
    return count;
}

int PriorityQueue::getPriority(int value) {
    Node* current = front;
    while (current != nullptr) {
        if (current->value == value) {
            return current->priority;
        }
        current = current->next;
    }
    return -1;
}