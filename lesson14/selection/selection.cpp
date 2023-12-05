#include "selection.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int comparisons = 0;
int moves = 0;

void randomFill(int array[], int size) {
    srand(static_cast<unsigned int>(time(nullptr)));
    for (int i = 0; i < size; ++i) {
        array[i] = rand();
    }
}

void bestFill(int array[], int size) {
    for (int i = 0; i < size; ++i) {
        array[i] = i + 1;
    }
}

void worstFill(int array[], int size) {
    for (int i = 0; i < size; ++i) {
        array[i] = size - i;
    }
}

void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; ++i) {
        int minIndex = i;

        // Знаходження індексу мінімального елемента в несортованій частині
        for (int j = i + 1; j < n; ++j) {
            ++comparisons;
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }

        // Обмін мінімального елемента з першим елементом несортованої частини
        std::swap(arr[i], arr[minIndex]);
        moves += 3; // Два присвоєння та один обмін
    }
    cout << "\nNumber of comparisons: " << comparisons << endl;
    cout << "Number of moves: " << moves << endl;
}
