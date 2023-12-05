#include <iostream>
#include "sorts.cpp"


int main() {
    const long long SIZE = 100000; // Adjust the size as needed

    // Test best case
    int bestArray[SIZE];
    bestFill(bestArray, SIZE);

    SortStats bestStats = quickSort(bestArray, 0, SIZE - 1);

    std::cout << "Best case statistics: " << "\n";
    std::cout << "Comparisons: " << bestStats.comparisons << "\n";
    std::cout << "Swaps: " << bestStats.swaps << "\n";

    // Test random case
    int randomArray[SIZE];
    randomFill(randomArray, SIZE);

    SortStats randomStats = quickSort(randomArray, 0, SIZE - 1);

    std::cout << "Random case statistics:" << "\n"; 
    std::cout << "Comparisons: " << randomStats.comparisons << "\n";
    std::cout << "Swaps: " << randomStats.swaps << "\n";

    // Test worst case
    int worstArray[SIZE];
    worstFill(worstArray, SIZE);

    SortStats worstStats = quickSort(worstArray, 0, SIZE - 1);
    
    std::cout << "Worst case statistics: " << "\n";
    std::cout << "Comparisons: " << worstStats.comparisons << "\n";
    std::cout << "Swaps: " << worstStats.swaps << "\n";

    return 0;
}
