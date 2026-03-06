#include <iostream>
using namespace std;

/**
 * AP & GP Series (Revised)
 * Fix: Avoids floating point pow() for GP series where possible.
 */

long long intPower(long long base, int exp) {
    long long res = 1;
    while (exp > 0) {
        if (exp % 2 == 1) res *= base;
        base *= base;
        exp /= 2;
    }
    return res;
}

int main() {
    long long a, d, r, n;
    cout << "Enter first term (a): "; cin >> a;
    cout << "Enter common difference (d) for AP: "; cin >> d;
    cout << "Enter common ratio (r) for GP: "; cin >> r;
    cout << "Enter number of terms (n): "; cin >> n;
    
    cout << "AP Series: ";
    for (int i = 0; i < n; i++) cout << (a + i * d) << " ";
    cout << "\nSum of AP: " << (n * (2 * a + (n - 1) * d)) / 2 << endl;
    
    cout << "GP Series: ";
    for (int i = 0; i < n; i++) cout << (a * intPower(r, i)) << " ";
    // Sum of GP: a(r^n - 1) / (r - 1)
    if (r != 1) {
        long long gpSum = a * (intPower(r, n) - 1) / (r - 1);
        cout << "\nSum of GP: " << gpSum << endl;
    } else {
        cout << "\nSum of GP: " << a * n << endl;
    }
    
    return 0;
}
