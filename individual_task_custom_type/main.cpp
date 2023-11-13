#include "funcs.cpp"
#include <iostream>

using namespace std;

int main() {
    PriorityQueue priorityQueue;
    int choice;
    bool flag = true;
    int value;
    int priority;

    while(flag) {
        cout << endl << "MENU:" << endl;
        cout << "1. Add element to the queue" << endl;
        cout << "2. Remove element from queue byt its value" << endl;
        cout << "3. Check priority of the element by its value" << endl;
        cout << "4. Output queue" << endl;
        cout << "5. Get element with min pririty from queue" << endl;
        cout << "6. Check is queue empty" << endl;
        cout << "7. Get size of queue" << endl;
        cout << "8. Clear queue" << endl;
        cout << "9. Finish program" << endl;
        cout << "Choice: ";
        cin >> choice;
        
        switch(choice) {
            case 1:
                cout << "\nEnter value of element: ";
                cin >> value;
                cout << "Do you want to set priority manually, or use default (0)?";
                cout << "\n1. Use default";
                cout << "\n2. Set manually";
                cout << "\nChoice: ";
                int ch;
                cin >> ch;
                if (ch == 1) {
                    priorityQueue.insert(value);
                } else if (ch == 2) {
                    cout << "\nEnter prioirty: ";
                    cin >> priority;
                    priorityQueue.insert(value, priority);
                } else {
                    cout << "\nInvalid data.\n";
                }
                break;
            case 2:
                cout << "\nEnter value of element: ";
                cin >> value;
                priorityQueue.remove(value);
                cout << "Operation completed.\n";
                break;
            case 3:
                cout << "\nEnter value of element: ";
                cin >> value;
                if (priorityQueue.getPriority(value) == -1) {
                    cout << "\nThere no such value in queue.\n";
                } else {
                    cout << "\nThe priority of value " << value << " is " << priorityQueue.getPriority(value) << ".\n";
                }
                break;
            case 4:
                priorityQueue.printQueue();
                break;
            case 5:
                cout << "\nThe element with min priority is " << priorityQueue.getMaxPriority() << ".\n";
                break;
            case 6:
                (priorityQueue.isEmpty()) ? (cout << "\nQueue is empty.\n") : (cout << "\nQueue is not empty.\n");
                break;
            case 7:
                cout << "\nIn queue " << priorityQueue.size() << " items.\n";
                break;
            case 8:
                priorityQueue.clear();
                cout << "\nQueue is empty now.\n";
                break;
            case 9:
                priorityQueue.clear();
                flag = false;
                cout << "\nProgram is finished successfully!";
                break;
            default:
                cout << "\nInvalid choice.\n";
                break;
        }
    }
    return 0;
}
