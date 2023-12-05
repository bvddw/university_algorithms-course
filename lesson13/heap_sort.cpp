#include <iostream>
#include "sorts.cpp"


int main() {
    const long long SIZE = 1000000; // Adjust the size as needed

    // Test best case
    int bestArray[SIZE];
    bestFill(bestArray, SIZE);

    SortStats bestStats = heapSort(bestArray, SIZE);

    std::cout << "Best case statistics: " << "\n";
    std::cout << "Comparisons: " << bestStats.comparisons << "\n";
    std::cout << "Swaps: " << bestStats.swaps << "\n";

    // Test random case
    int randomArray[SIZE];
    randomFill(randomArray, SIZE);

    SortStats randomStats = heapSort(randomArray, SIZE);

    std::cout << "Random case statistics:" << "\n"; 
    std::cout << "Comparisons: " << randomStats.comparisons << "\n";
    std::cout << "Swaps: " << randomStats.swaps << "\n";

    // Test worst case
    int worstArray[SIZE];
    worstFill(worstArray, SIZE);

    SortStats worstStats = heapSort(worstArray, SIZE);
    
    std::cout << "Worst case statistics: " << "\n";
    std::cout << "Comparisons: " << worstStats.comparisons << "\n";
    std::cout << "Swaps: " << worstStats.swaps << "\n";

    return 0;
}
