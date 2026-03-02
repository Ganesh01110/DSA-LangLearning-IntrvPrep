#include <iostream>
#include <cmath>
using namespace std;

/**
 * Armstrong Number Check
 * Definition: Sum of digits raised to the power of number of digits equals the number.
 * Example: 153 = 1^3 + 5^3 + 3^3
 */

bool isArmstrong(int n) {
    int temp = n, sum = 0;
    int digits = floor(log10(n) + 1);
    
    while (temp > 0) {
        sum += pow(temp % 10, digits);
        temp /= 10;
    }
    return sum == n;
}

int main() {
    int n;
    if (!(cin >> n)) return 0;
    
    if (isArmstrong(n)) cout << "Armstrong Number" << endl;
    else cout << "Not Armstrong Number" << endl;
    
    return 0;
}
