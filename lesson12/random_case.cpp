#include "sorts.cpp"

using namespace std;


int main() {
    // random case
    int SIZE = 1000000;
    int* array_1 = randomFill(SIZE);
    int* array_2 = new int[SIZE];
    int* array_3 = new int[SIZE];
    int* array_4 = new int[SIZE];
    for (int i = 0; i < SIZE; i++) {
        array_2[i] = array_1[i];
        array_3[i] = array_1[i];
        array_4[i] = array_1[i];
    }
    // bubleSort(array_1, SIZE);
    // insertionSort(array_2, SIZE);
    // selectionSort(array_3, SIZE);
    shellSort(array_4, SIZE);
}