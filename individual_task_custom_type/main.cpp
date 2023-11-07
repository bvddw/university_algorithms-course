#include "funcs.cpp"
#include <iostream>

using namespace std;

int main() {
    PriorityQueue pq;

    pq.insert(1, 3);
    pq.insert(2, 1);
    pq.insert(3, 4);
    pq.insert(4, 1);
    pq.insert(5, 5);

    while (!pq.isEmpty()) {
        cout << pq.getMinPriority() << " ";
    }

    return 0;
}
