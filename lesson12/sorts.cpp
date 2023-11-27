#include <iostream>
#include <cstdlib>
#include <ctime>
#include "header.h"

using namespace std;

int* randomFill(int size) {
    srand(static_cast<unsigned int>(time(nullptr)));
    int* array = new int[size];
    for (int i = 0; i < size; ++i) {
        array[i] = rand();
    }
    return array;
}

int* bestFill(int size) {
    int* array = new int[size];
    for (int i = 0; i < size; ++i) {
        array[i] = i + 1;
    }
    return array;
}

int* worstFill(int size) {
    int* array = new int[size];
    for (int i = 0; i < size; ++i) {
        array[i] = size - i;
    }
    return array;
}

void displayArray(int* array, int size) {
    cout << "Array: ";
    for (int i = 0; i < size; i++) {
        cout << array[i] << ' ';
    }
    cout << endl;
}

int* bubleSort(int* array, int size) {
    long long count_comp = 0;
    long long count_swap = 0;
    for (int i = 0; i < size; i++) {
        for (int j = i; j < size; j++) {
            count_comp++;
            if (array[i] > array[j]) {
                count_swap++;
                array[i] = array[i] + array[j];
                array[j] = array[i] - array[j];
                array[i] = array[i] - array[j];
            }
        }
    }
    cout << "Array sorted successfuly, using buble sort!\n";
    cout << "Number of comparisons: " << count_comp << endl;
    cout << "Number of swaps: " << count_swap << endl;
    return array;
}

int* insertionSort(int* array, int size) {
    long long count_comp = 0;
    long long count_swap = 0;

    for (int i = 1; i < size; ++i) {
        int key = array[i];
        int j = i - 1;
        count_comp++;
        while (j >= 0 && array[j] > key) {
            array[j + 1] = array[j];
            j = j - 1;
            count_comp++;
            count_swap++;
        }
        array[j + 1] = key;
    }

    cout << "Array sorted successfully using insertion sort!\n";
    cout << "Number of comparisons: " << count_comp << endl;
    cout << "Number of swaps: " << count_swap << endl;
    return array;
}

void selectionSort(int* array, int size) {
    long long count_comp = 0;
    long long count_swap = 0;
    for (int i = 0; i < size - 1; ++i) {
        int minIndex = i;
        for (int j = i + 1; j < size; ++j) {
            count_comp++;
            if (array[j] < array[minIndex]) {
                minIndex = j;
            }
        }
        if (i != minIndex) count_swap++;
        swap(array[i], array[minIndex]);
    }
    cout << "Array sorted successfully using selection sort!\n";
    cout << "Number of comparisons: " << count_comp << endl;
    cout << "Number of swaps: " << count_swap << endl;
}

void shellSort(int* array, int size) {
    long long count_comp = 0;
    long long count_swap = 0;
    for (int gap = size / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < size; ++i) {
            int temp = array[i];
            int j;

            count_comp++;
            for (j = i; j >= gap && array[j - gap] > temp; j -= gap) {
                count_comp++;
                array[j] = array[j - gap];
                count_swap++;
            }
            array[j] = temp;
        }
    }
    std::cout << "Array sorted successfully using shell sort!\n";
    std::cout << "Number of comparisons: " << count_comp << std::endl;
    std::cout << "Number of swaps: " << count_swap << std::endl;
}

