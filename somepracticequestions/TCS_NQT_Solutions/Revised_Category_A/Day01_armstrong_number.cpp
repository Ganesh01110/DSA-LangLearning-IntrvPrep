#include <iostream>
using namespace std;

/**
 * Armstrong Number Check (Revised)
 * Logic: Sum of digits raised to the power of number of digits equals the number.
 * Fix: Avoids pow() and log10() for precision.
 */

long long power(int base, int exp) {
    long long res = 1;
    for (int i = 0; i < exp; i++) res *= base;
    return res;
}

int countDigits(int n) {
    if (n == 0) return 1;
    int count = 0;
    while (n > 0) {
        count++;
        n /= 10;
    }
    return count;
}

bool isArmstrong(int n) {
    if (n < 0) return false;
    int temp = n;
    int digits = countDigits(n);
    long long sum = 0;
    
    while (temp > 0) {
        sum += power(temp % 10, digits);
        temp /= 10;
    }
    return sum == (long long)n;
}

int main() {
    int n;
    cout << "Enter a number: ";
    if (!(cin >> n)) return 0;
    
    if (isArmstrong(n)) cout << n << " is an Armstrong Number" << endl;
    else cout << n << " is not an Armstrong Number" << endl;
    
    return 0;
}
