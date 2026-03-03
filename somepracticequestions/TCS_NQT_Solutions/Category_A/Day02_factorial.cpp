#include <iostream>
using namespace std;

/**
 * Factorial of a number
 */

long long factorial(int n) {
    if (n <= 1) return 1;
    return n * factorial(n - 1);
}

int main() {
    int n;
    if (!(cin >> n)) return 0;
    cout << factorial(n) << endl;
    return 0;
}
