
#include <iostream>
#include <cmath>

bool isArmstrong(int n) {
    if (n == 0) return true; // 0 is an Armstrong number
    int temp = n, sum = 0, digits = 0;

    // Safer way to count digits
    int countTemp = n;
    while (countTemp > 0) {
        digits++;
        countTemp /= 10;
    }

    temp = n;
    while (temp > 0) {
        int d = temp % 10;
        
        // Manual power calculation to avoid pow() precision issues
        int p = 1;
        for (int i = 0; i < digits; i++) p *= d;
        
        sum += p;
        temp /= 10;
    }
    return sum == n;
}

int main() {
    int n;
    if (!(std::cin >> n)) return 0; // Handle invalid input

    if (isArmstrong(n)) std::cout << "Armstrong Number" << std::endl;
    else std::cout << "Not Armstrong Number" << std::endl;

    return 0;
}