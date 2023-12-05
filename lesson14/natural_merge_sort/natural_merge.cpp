#include "natural_merge.h"
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

void merge(int arr[], int left, int middle, int right) {
    int n1 = middle - left + 1;
    int n2 = right - middle;

    int* leftArray = new int[n1];
    int* rightArray = new int[n2];

    for (int i = 0; i < n1; ++i)
        leftArray[i] = arr[left + i];
    for (int j = 0; j < n2; ++j)
        rightArray[j] = arr[middle + 1 + j];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        ++comparisons;
        if (leftArray[i] <= rightArray[j]) {
            arr[k] = leftArray[i];
            ++i;
        } else {
            arr[k] = rightArray[j];
            ++j;
        }
        ++moves;
        ++k;
    }

    while (i < n1) {
        arr[k] = leftArray[i];
        ++i;
        ++k;
        ++moves;
    }

    while (j < n2) {
        arr[k] = rightArray[j];
        ++j;
        ++k;
        ++moves;
    }

    delete[] leftArray;
    delete[] rightArray;
}

void naturalMergeSort(int arr[], int left, int right) {
    if (left < right) {
        int middle = left + (right - left) / 2;

        naturalMergeSort(arr, left, middle);
        naturalMergeSort(arr, middle + 1, right);

        merge(arr, left, middle, right);
    }
}

int main() {
    const long long SIZE = 1000000;

    // Test best case
    int bestArray[SIZE];
    bestFill(bestArray, SIZE);

    naturalMergeSort(bestArray, 0, SIZE - 1);

    cout << "\nNumber of comparisons: " << comparisons << endl;
    cout << "Number of moves: " << moves << endl;
    
    comparisons = 0;
    moves = 0;

    // Test random case
    int randomArray[SIZE];
    randomFill(randomArray, SIZE);

    naturalMergeSort(randomArray, 0, SIZE - 1);

    cout << "\nNumber of comparisons: " << comparisons << endl;
    cout << "Number of moves: " << moves << endl;
    
    comparisons = 0;
    moves = 0;

    // Test worst case
    int worstArray[SIZE];
    worstFill(worstArray, SIZE);

    naturalMergeSort(worstArray, 0, SIZE - 1);

    cout << "\nNumber of comparisons: " << comparisons << endl;
    cout << "Number of moves: " << moves << endl;

    return 0;
}
