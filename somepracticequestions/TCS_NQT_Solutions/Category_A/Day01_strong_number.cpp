#include <iostream>
using namespace std;

/**
 * Strong Number Check
 * Definition: Sum of factorials of digits equals the number.
 * Example: 145 = 1! + 4! + 5! = 1 + 24 + 120 = 145
 */

int factorial(int n) {
    if (n <= 1) return 1;
    return n * factorial(n - 1);
}

bool isStrong(int n) {
    int temp = n, sum = 0;
    while (temp > 0) {
        sum += factorial(temp % 10);
        temp /= 10;
    }
    return sum == n;
}

int main() {
    int n;
    if (!(cin >> n)) return 0;
    
    if (isStrong(n)) cout << "Strong Number" << endl;
    else cout << "Not Strong Number" << endl;
    
    return 0;
}
