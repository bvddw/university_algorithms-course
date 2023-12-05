#include <iostream>
#include "selection.cpp"

using namespace std;

int main() {
    const long long SIZE = 10000;

    // Test best case
    int bestArray[SIZE];
    bestFill(bestArray, SIZE);

    selectionSort(bestArray, SIZE);


    // Test random case
    int randomArray[SIZE];
    randomFill(randomArray, SIZE);

    selectionSort(randomArray, SIZE);


    // Test worst case
    int worstArray[SIZE];
    worstFill(worstArray, SIZE);

    selectionSort(worstArray, SIZE);

    return 0;
}