#include <iostream>

using namespace std;

int gcd(int a, int b) {
    if (a == 1 || b == 1) {
        return 1;
    }
    if (a == b) {
        return a;
    }
    if (a == 0 || b == 0) {
        return abs(a - b);
    }
    if (a > b) {
        return gcd(a % b, b);
    } else {
        return gcd(a, b % a);
    }
}

int main() {
    int result1 = gcd(5, 3);
    std::cout << "GCD(5, 3) = " << result1 << " (Expected: 1)" << std::endl;

    // Test case 2
    int result2 = gcd(12, 4);
    std::cout << "GCD(12, 4) = " << result2 << " (Expected: 4)" << std::endl;

    // Test case 3
    int result3 = gcd(15, 10);
    std::cout << "GCD(15, 10) = " << result3 << " (Expected: 5)" << std::endl;

    // Test case 4
    int result4 = gcd(48, 18);
    std::cout << "GCD(48, 18) = " << result4 << " (Expected: 6)" << std::endl;

    // Test case 5
    int result5 = gcd(7, 11);
    std::cout << "GCD(7, 11) = " << result5 << " (Expected: 1)" << std::endl;

    // Test case 6
    int result6 = gcd(25, 5);
    std::cout << "GCD(25, 5) = " << result6 << " (Expected: 5)" << std::endl;

    // Test case 7
    int result7 = gcd(36, 9);
    std::cout << "GCD(36, 9) = " << result7 << " (Expected: 9)" << std::endl;

    // Test case 8
    int result8 = gcd(100, 75);
    std::cout << "GCD(100, 75) = " << result8 << " (Expected: 25)" << std::endl;

    // Test case 9
    int result9 = gcd(17, 23);
    std::cout << "GCD(17, 23) = " << result9 << " (Expected: 1)" << std::endl;

    // Test case 10
    int result10 = gcd(0, 5);
    std::cout << "GCD(0, 5) = " << result10 << " (Expected: 5)" << std::endl;

    return 0;
}