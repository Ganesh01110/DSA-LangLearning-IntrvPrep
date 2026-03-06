#include <iostream>
using namespace std;

/**
 * Recursion Examples: Sum of Digits, Power(x, n)
 */

int sumOfDigits(int n) {
    if (n == 0) return 0;
    return (n % 10) + sumOfDigits(n / 10);
}

double power(double x, int n) {
    if (n == 0) return 1;
    if (n < 0) return 1 / power(x, -n);
    return x * power(x, n - 1);
}

int main() {
    int mode;
    cin >> mode;
    
    if (mode == 1) {
        int n; cin >> n;
        cout << "Sum of Digits: " << sumOfDigits(n) << endl;
    } else if (mode == 2) {
        double x; int n;
        cin >> x >> n;
        cout << x << "^" << n << " = " << power(x, n) << endl;
    }
    
    return 0;
}
