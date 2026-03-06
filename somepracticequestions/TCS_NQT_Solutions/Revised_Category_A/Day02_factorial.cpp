#include <iostream>
using namespace std;

/**
 * Factorial (Revised)
 * Logic: Iterative calculation using long long to handle larger results.
 */

int main() {
    int n;
    cout << "Enter a number: ";
    if (!(cin >> n)) return 0;
    
    if (n < 0) {
        cout << "Factorial not defined for negative numbers." << endl;
        return 0;
    }
    
    long long res = 1;
    for (int i = 2; i <= n; i++) res *= i;
    
    cout << "Factorial: " << res << endl;
    return 0;
}
