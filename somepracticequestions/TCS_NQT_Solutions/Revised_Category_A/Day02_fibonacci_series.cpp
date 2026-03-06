#include <iostream>
#include <vector>
using namespace std;

/**
 * Fibonacci Series (Revised)
 * Logic: Iterative approach to avoid recursion overhead.
 */

int main() {
    int n;
    cout << "Enter number of terms: ";
    if (!(cin >> n)) return 0;
    
    if (n <= 0) return 0;
    
    long long a = 0, b = 1;
    cout << "Fibonacci Series: ";
    for (int i = 0; i < n; i++) {
        cout << a << " ";
        long long next = a + b;
        a = b;
        b = next;
    }
    cout << endl;
    
    return 0;
}
