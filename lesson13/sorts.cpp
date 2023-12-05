#include <iostream>
#include <cstdlib>
#include <ctime>
#include "header.h"

using namespace std;

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


void displayArray(int array[], int size) {
    cout << "Array: ";
    for (int i = 0; i < size; i++) {
        cout << array[i] << ' ';
    }
    cout << endl;
}

struct SortStats {
    long long comparisons;
    long long swaps;
};

// Function to swap two elements
void swap(int& a, int& b, long long& swapCount) {
    int temp = a;
    a = b;
    b = temp;
    swapCount++;
}

// Partition function for QuickSort
int partition(int array[], int low, int high, long long& compareCount, long long& swapCount) {
    int pivot = array[(low + high) / 2];  // Choose the rightmost element as the pivot
    int i = (low - 1);        // Index of smaller element

    for (int j = low; j <= high - 1; j++) {
        compareCount++;  // Increment comparison count
        if (array[j] < pivot) {
            i++;
            swap(array[i], array[j], swapCount);
        }
    }
    swap(array[i + 1], array[high], swapCount);
    return (i + 1);
}

// QuickSort function with statistics
SortStats quickSort(int array[], int low, int high) {
    SortStats stats{0, 0};  // Initialize stats

    if (low < high) {
        // Partition the array, arr[p] is now at the correct position
        int pivotIndex = partition(array, low, high, stats.comparisons, stats.swaps);

        // Recursively sort the subarrays
        SortStats leftStats = quickSort(array, low, pivotIndex - 1);
        SortStats rightStats = quickSort(array, pivotIndex + 1, high);

        // Update stats with counts from recursive calls
        stats.comparisons += leftStats.comparisons + rightStats.comparisons;
        stats.swaps += leftStats.swaps + rightStats.swaps;
    }

    return stats;
}

// Heapify the subtree rooted at index i
void heapify(int array[], int size, int index, long long& compareCount, long long& swapCount) {
    int largest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;

    // Compare with left child
    compareCount++;
    if (left < size && array[left] > array[largest]) {
        largest = left;
    }

    // Compare with right child
    compareCount++;
    if (right < size && array[right] > array[largest]) {
        largest = right;
    }

    // If the largest is not the root
    if (largest != index) {
        swap(array[index], array[largest], swapCount);

        // Recursively heapify the affected sub-tree
        heapify(array, size, largest, compareCount, swapCount);
    }
}

// Heap Sort function with statistics
SortStats heapSort(int array[], int size) {
    SortStats stats{0, 0};  // Initialize stats

    // Build a max heap
    for (int i = size / 2 - 1; i >= 0; i--) {
        heapify(array, size, i, stats.comparisons, stats.swaps);
    }

    // Extract elements from the heap one by one
    for (int i = size - 1; i > 0; i--) {
        swap(array[0], array[i], stats.swaps);
        heapify(array, i, 0, stats.comparisons, stats.swaps);
    }

    return stats;
}