#include <iostream>
using namespace std;

/**
 * Strong Number Check (Revised)
 * Definition: Sum of factorial of digits equals the number.
 * Example: 145 = 1! + 4! + 5!
 */

long long factorial(int n) {
    long long res = 1;
    for (int i = 2; i <= n; i++) res *= i;
    return res;
}

bool isStrong(int n) {
    if (n <= 0) return false;
    int temp = n;
    long long sum = 0;
    while (temp > 0) {
        sum += factorial(temp % 10);
        temp /= 10;
    }
    return sum == (long long)n;
}

int main() {
    int n;
    cout << "Enter a number: ";
    if (!(cin >> n)) return 0;
    
    if (isStrong(n)) cout << n << " is a Strong Number" << endl;
    else cout << n << " is not a Strong Number" << endl;
    
    return 0;
}
